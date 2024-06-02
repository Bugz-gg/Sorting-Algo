/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_2;
    QLCDNumber *lcdNumber;
    QSpinBox *vBtn;
    QTextBrowser *textBrowser_3;
    QTextBrowser *complexity;
    QTextBrowser *textBrowser;
    QTextBrowser *textBrowser_4;
    QComboBox *algoTxt;
    QSlider *horizontalSlider;
    QTextBrowser *nbComparaison;
    QPushButton *startBtn;
    QPushButton *resetBtn;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(623, 606);
        MainWindow->setMinimumSize(QSize(603, 0));
        MainWindow->setDocumentMode(true);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");

        horizontalLayout->addWidget(graphicsView);

        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName("verticalLayout");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        textBrowser_2 = new QTextBrowser(widget);
        textBrowser_2->setObjectName("textBrowser_2");
        textBrowser_2->setAutoFillBackground(true);

        gridLayout->addWidget(textBrowser_2, 1, 0, 1, 2);

        lcdNumber = new QLCDNumber(widget);
        lcdNumber->setObjectName("lcdNumber");

        gridLayout->addWidget(lcdNumber, 4, 2, 1, 2);

        vBtn = new QSpinBox(widget);
        vBtn->setObjectName("vBtn");
        vBtn->setMinimum(2);
        vBtn->setMaximum(200);

        gridLayout->addWidget(vBtn, 1, 2, 1, 2);

        textBrowser_3 = new QTextBrowser(widget);
        textBrowser_3->setObjectName("textBrowser_3");
        textBrowser_3->setAutoFillBackground(true);

        gridLayout->addWidget(textBrowser_3, 2, 0, 1, 2);

        complexity = new QTextBrowser(widget);
        complexity->setObjectName("complexity");
        complexity->setAutoFillBackground(true);

        gridLayout->addWidget(complexity, 3, 2, 1, 2);

        textBrowser = new QTextBrowser(widget);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setAutoFillBackground(true);

        gridLayout->addWidget(textBrowser, 0, 0, 1, 2);

        textBrowser_4 = new QTextBrowser(widget);
        textBrowser_4->setObjectName("textBrowser_4");
        textBrowser_4->setAutoFillBackground(true);

        gridLayout->addWidget(textBrowser_4, 3, 0, 1, 2);

        algoTxt = new QComboBox(widget);
        algoTxt->addItem(QString());
        algoTxt->addItem(QString());
        algoTxt->addItem(QString());
        algoTxt->setObjectName("algoTxt");

        gridLayout->addWidget(algoTxt, 0, 2, 1, 2);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setMaximum(15);
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider, 2, 2, 1, 2);

        nbComparaison = new QTextBrowser(widget);
        nbComparaison->setObjectName("nbComparaison");
        nbComparaison->setAutoFillBackground(true);

        gridLayout->addWidget(nbComparaison, 4, 0, 1, 2);

        startBtn = new QPushButton(widget);
        startBtn->setObjectName("startBtn");

        gridLayout->addWidget(startBtn, 5, 2, 1, 2);

        resetBtn = new QPushButton(widget);
        resetBtn->setObjectName("resetBtn");

        gridLayout->addWidget(resetBtn, 5, 0, 1, 2);


        verticalLayout->addLayout(gridLayout);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        textBrowser_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Number of values :</p></body></html>", nullptr));
        textBrowser_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Speed :</p></body></html>", nullptr));
        complexity->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Algorithm :</p></body></html>", nullptr));
        textBrowser_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Complexity :</p></body></html>", nullptr));
        algoTxt->setItemText(0, QCoreApplication::translate("MainWindow", "Bogosort", nullptr));
        algoTxt->setItemText(1, QCoreApplication::translate("MainWindow", "BubbleSort", nullptr));
        algoTxt->setItemText(2, QCoreApplication::translate("MainWindow", "GnomeSort", nullptr));

        nbComparaison->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Comparaison :</p></body></html>", nullptr));
        startBtn->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        resetBtn->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
