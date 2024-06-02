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
        timer->start(15 * speed_ms);
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

    for (int i = 0; i < array.size(); ++i) {
        int barHeight = (array[i] * ui->graphicsView->height()) / maxVal;
        QGraphicsRectItem* bar = scene->addRect(i * barWidth, ui->graphicsView->height() - barHeight, barWidth, barHeight);
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
        int barHeight = (array[i] * ui->graphicsView->height()) / maxVal;
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
    default:
        break;
    }
}

void MainWindow::bubbleSort(){
    QBrush brush(Qt::red);
    if (i < array.size() - 1) {
        if (j < array.size() - i - 1) {
            //bars[j]->setBrush(brush);
            //bars[j + 1]->setBrush(brush);
            if (array[j] > array[j + 1]) {
                qSwap(array[j], array[j + 1]); // maybe add color to the swap
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

void MainWindow::gnomeSort(){
    if (i < array.size()) {
        if (array[i] >= array[i - 1]){
            incrementComp();
            ++i;
        }
        else {
            qSwap(array[i], array[i - 1]);
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


void MainWindow::on_exitBtn_clicked()
{
    pid_t mypid = getpid();
    //kill(mypid, 9); // Only on linux maybe because I didnt test it on Mac.
}


void MainWindow::on_algoTxt_currentIndexChanged(int index)
{
    switch (index){
    case Bogosort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>Infinity</span></b></p>");
        break;
    case BubbleSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
    case GnomeSort:
        i = 1;
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
    }}

void MainWindow::on_algoTxt_activated(int index)
{
    switch (index){
    case Bogosort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>Infinity</span></b></p>");
        break;
    case BubbleSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
    case GnomeSort:
        ui->complexity->setText("<p align='center'><b><span style='font-family: Arial; font-size: 30pt;'>O(n²)</span></b></p>");
    }
}

