#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGraphicsRectItem>
#include <QRandomGenerator>
#include <algorithm>
#include <random>
#include <signal.h>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    timer(nullptr),
    i(0),
    j(0),
    speed_ms(0),
    sound(1),
    sorted(false)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startBtn_clicked()
{
    if (ui->startBtn->text() == "Start"){
        ui->startBtn->setText("Pause");
        int length = ui->vBtn->value();
        initializeArray(length + 1);
        initializeScene();
        resetState(); // Reset sorting state

        if (timer != nullptr) {
            timer->stop();
            delete timer;
        }
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::sortStep);
        timer->start(speed_ms);
    }
    else {
        if (timer->isActive()) {
            timer->stop();
            ui->startBtn->setText("Unpause");
        }
        else {
            timer->start();
            ui->startBtn->setText("Pause");
        }
    }
}

void MainWindow::initializeArray(int length)
{
    array.clear();
    bars.clear();
    for (int i = 1; i < length; ++i){
        array.append(i);
    }
    //qDebug() << array;
    random_device rd;
    mt19937 g(rd());
    shuffle(array.begin(), array.end(), g);
}

void MainWindow::initializeScene()
{
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    int maxVal = *max_element(array.begin(), array.end());
    int barWidth = ui->graphicsView->width() / array.size();
    QBrush brush(Qt::blue); // Fill color
    QPen pen(Qt::black);

    for (int i = 0; i < array.size(); ++i) {
        int barHeight = (array[i] * (ui->graphicsView->height()* 0.9)) / maxVal;
        QGraphicsRectItem* bar = scene->addRect(i * barWidth, ui->graphicsView->height() - barHeight, barWidth, barHeight);
        bar->setPen(pen);
        bar->setBrush(brush);
        bars.append(bar);
    }
}

void MainWindow::updateBars()
{
    int maxVal = *std::max_element(array.begin(), array.end());
    int barWidth = ui->graphicsView->width() / array.size();
    QBrush brush(Qt::blue); // Fill color
    QPen pen(Qt::black);    // Border color
    for (int i = 0; i < array.size(); ++i) {
        int barHeight = (array[i] * (ui->graphicsView->height()* 0.9)) / maxVal;
        bars[i]->setRect(i * barWidth, ui->graphicsView->height() - barHeight, barWidth, barHeight);
        bars[i]->setBrush(brush);
        bars[i]->setPen(pen);
    }
}

//#include <unistd.h>
void MainWindow::sortStep()
{
    if (sorted) {
        QBrush brush(Qt::green); // Fill color
        for (int i = 0; i < array.size(); ++i) {
            bars[i]->setBrush(brush);
        }
        timer->stop();
        disconnect(timer);
        return;
    }
    switch (ui->algoTxt->currentIndex()){
    case Bogosort:
        return bogoSort();
        break;
    case BubbleSort:
        return bubbleSort();
        break;
    case GnomeSort:
        return gnomeSort();
        break;
    case QuickSort:
        if (stack.empty() && !i)  {
            stack.push({0, array.size() - 1});
            ++i;
        }
        return quickSort();
        break;
    default:
        break;
    }
}
#include <QtConcurrent/QtConcurrent>

void MainWindow::qswap(QVector<int> *array, int i, int j) {
    QtConcurrent::run([this]() {
        Beep(sound, speed_ms);
    });
    qSwap((*array)[i], (*array)[j]);
}

void MainWindow::bubbleSort(){
    if (i < array.size() - 1) {
        if (j < array.size() - i - 1) {
            if (array[j] > array[j + 1]) {
                qswap(&array, j, j+1); // maybe add color to the swap
                updateBars();
            }
            ++j;
            incrementComp();
        } else {
            j = 0;
            ++i;
        }
    }
    else {
        sorted = true;
    }
}

void MainWindow::bogoSort(){
    if (!sorted) {
        random_device rd;
        mt19937 g(rd());
        shuffle(array.begin(), array.end(), g);
        QtConcurrent::run([this]() {
            Beep(sound, speed_ms);
        });
        updateBars();
        bool s = true;
        for (int i = 0; i < array.size() - 1; ++i){
            if (array[i] > array[i + 1]){
                incrementComp();
                s = false;
                break;
            }
            incrementComp();
        }
        if (s){
            sorted = true;
        }
    }
}



void MainWindow::quickSort() {
    if (!stack.empty()) {
        auto [low, high] = stack.pop();
        int pivotIndex = partition(low, high);

        if (pivotIndex - 1 > low) {
            stack.push({low, pivotIndex - 1});
        }
        if (pivotIndex + 1 < high) {
            stack.push({pivotIndex + 1, high});
        }

        updateBars();
    } else {
        sorted = true;
    }
}

int MainWindow::partition(int low, int high) {
    int pivot = array[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (array[j] < pivot) {
            ++i;
            qswap(&array, i, j);
            updateBars();
            incrementComp();
        }
    }
    qswap(&array, i + 1, high);
    updateBars();
    incrementComp();
    return i + 1;
}


void MainWindow::gnomeSort(){
    if (i < array.size()) {
        if (array[i] >= array[i - 1]){
            incrementComp();
            ++i;
        }
        else {
            qswap(&array, i, i- 1);
            updateBars();
            incrementComp();
            if (i > 1) --i;
        }
    }
    else {
        sorted = true;
    }
}

void MainWindow::incrementComp(){
    ui->lcdNumber->display(ui->lcdNumber->value() + 1);
}

void MainWindow::on_resetBtn_clicked()
{
    if (timer) {
        timer->stop();
        delete timer;
        timer = nullptr;
    }
    array.clear();
    while (!stack.empty()) {
        stack.pop();
    }
    bars.clear();
    scene->clear();
    ui->lcdNumber->display(0);
    sorted = false;
    ui->startBtn->setText("Start");
    i = 0;
    j = 0;
}

void MainWindow::resetState()
{
    //i = 0; a func because it depends on the algo
    //j = 0;
    sorted = false;
    ui->lcdNumber->display(0);
}

void MainWindow::on_lcdNumber_overflow()
{
    printf("There is an overflow !\n");
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    speed_ms = position;
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    speed_ms = value;
}


void MainWindow::on_algoTxt_currentIndexChanged(int index)
{
    return on_algoTxt_activated(index);
}
void MainWindow::on_algoTxt_activated(int index)
{
    switch (index){
    case Bogosort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O((n+1)!)</span></b></p>");
        break;
    case BubbleSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
        break;
    case GnomeSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
        break;
    case QuickSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n log n)</span></b></p>");
        break;
    }

}


void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    sound = position;
}

