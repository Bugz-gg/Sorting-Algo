#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QVector>
using namespace std;


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_startBtn_clicked();
    void sortStep();

    void on_resetBtn_clicked();
    void incrementComp();

    void on_lcdNumber_overflow();

    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

    void on_algoTxt_currentIndexChanged(int index);

    void on_algoTxt_activated(int index);

private:
    Ui::MainWindow *ui;
    QGraphicsView *graphicsView;
    QGraphicsScene *scene;
    QTimer *timer;

    QVector<int> array;
    QVector<int> cpyarray;
    QVector<QGraphicsRectItem*> bars;
    int i, j, speed_ms;
    bool sorted;

    void initializeArray(int);
    void initializeScene();
    void updateBars();
    void resetState();
    void bubbleSort();
    void bogoSort();
    void gnomeSort();
};

enum Algo {
    Bogosort,
    BubbleSort,
    GnomeSort,
};

#endif // MAINWINDOW_H
