/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label;
    QRadioButton *radioY;
    QRadioButton *radioX;
    QLineEdit *simple_axis;
    QLineEdit *simple_val;
    QPushButton *pushButton;
    QLabel *label_2;
    QLineEdit *size;
    QLineEdit *looper;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QLabel *gavsLabel;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *cX;
    QLineEdit *cY;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *radiusBox;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *rV0_Box;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QFrame *line_3;
    QRadioButton *radioJ;
    QRadioButton *radioG;
    QRadioButton *radioS;
    QRadioButton *radioM;
    QRadioButton *radioHollow;
    QRadioButton *radioFilled;
    QGraphicsView *graphicsView;
    QToolButton *tab1;
    QToolButton *tab2;
    QProgressBar *gavsBar;
    QFrame *line_4;
    QPushButton *interact;
    QSpinBox *spinBox;
    QLineEdit *V3;
    QLineEdit *by;
    QLabel *label_16;
    QWidget *widget_3;
    QRadioButton *radioFilled_5;
    QRadioButton *radioHollow_5;
    QPushButton *pushButton_5;
    QLabel *label_15;
    QLabel *label_14;
    QLineEdit *bx;
    QLabel *label_13;
    QLineEdit *blength;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *bwidth;
    QLabel *label_17;
    QMenuBar *menuBar;
    QMenu *menuES;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1433, 825);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(440, 0, 20, 861));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(-50, 260, 1431, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 290, 101, 21));
        QFont font;
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        label->setFont(font);
        radioY = new QRadioButton(centralWidget);
        radioY->setObjectName(QStringLiteral("radioY"));
        radioY->setGeometry(QRect(310, 330, 110, 26));
        radioX = new QRadioButton(centralWidget);
        radioX->setObjectName(QStringLiteral("radioX"));
        radioX->setGeometry(QRect(310, 370, 110, 26));
        simple_axis = new QLineEdit(centralWidget);
        simple_axis->setObjectName(QStringLiteral("simple_axis"));
        simple_axis->setGeometry(QRect(80, 330, 131, 33));
        simple_val = new QLineEdit(centralWidget);
        simple_val->setObjectName(QStringLiteral("simple_val"));
        simple_val->setGeometry(QRect(80, 390, 131, 33));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(300, 430, 95, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 10, 66, 21));
        label_2->setFont(font);
        size = new QLineEdit(centralWidget);
        size->setObjectName(QStringLiteral("size"));
        size->setGeometry(QRect(100, 60, 113, 33));
        looper = new QLineEdit(centralWidget);
        looper->setObjectName(QStringLiteral("looper"));
        looper->setGeometry(QRect(100, 130, 113, 33));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 60, 66, 21));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 130, 66, 21));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(180, 230, 131, 31));
        gavsLabel = new QLabel(centralWidget);
        gavsLabel->setObjectName(QStringLiteral("gavsLabel"));
        gavsLabel->setGeometry(QRect(480, 280, 481, 241));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 330, 41, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 390, 21, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 10, 101, 21));
        label_7->setFont(font);
        cX = new QLineEdit(centralWidget);
        cX->setObjectName(QStringLiteral("cX"));
        cX->setGeometry(QRect(550, 50, 41, 31));
        cY = new QLineEdit(centralWidget);
        cY->setObjectName(QStringLiteral("cY"));
        cY->setGeometry(QRect(630, 50, 41, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(530, 50, 21, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(610, 50, 21, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(460, 50, 66, 21));
        radiusBox = new QLineEdit(centralWidget);
        radiusBox->setObjectName(QStringLiteral("radiusBox"));
        radiusBox->setGeometry(QRect(540, 120, 111, 33));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(470, 120, 51, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(470, 180, 21, 21));
        rV0_Box = new QLineEdit(centralWidget);
        rV0_Box->setObjectName(QStringLiteral("rV0_Box"));
        rV0_Box->setGeometry(QRect(540, 180, 111, 33));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 180, 95, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(340, 230, 95, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_4->setFont(font1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(780, -30, 20, 541));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        radioJ = new QRadioButton(centralWidget);
        radioJ->setObjectName(QStringLiteral("radioJ"));
        radioJ->setGeometry(QRect(260, 40, 110, 26));
        radioG = new QRadioButton(centralWidget);
        radioG->setObjectName(QStringLiteral("radioG"));
        radioG->setGeometry(QRect(260, 80, 110, 26));
        radioS = new QRadioButton(centralWidget);
        radioS->setObjectName(QStringLiteral("radioS"));
        radioS->setGeometry(QRect(260, 120, 110, 26));
        radioM = new QRadioButton(centralWidget);
        radioM->setObjectName(QStringLiteral("radioM"));
        radioM->setGeometry(QRect(260, 160, 110, 26));
        radioHollow = new QRadioButton(centralWidget);
        radioHollow->setObjectName(QStringLiteral("radioHollow"));
        radioHollow->setGeometry(QRect(700, 50, 110, 26));
        radioFilled = new QRadioButton(centralWidget);
        radioFilled->setObjectName(QStringLiteral("radioFilled"));
        radioFilled->setGeometry(QRect(700, 90, 110, 26));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(-30, 510, 481, 261));
        tab1 = new QToolButton(centralWidget);
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1->setGeometry(QRect(710, 240, 31, 29));
        tab2 = new QToolButton(centralWidget);
        tab2->setObjectName(QStringLiteral("tab2"));
        tab2->setGeometry(QRect(740, 240, 31, 29));
        gavsBar = new QProgressBar(centralWidget);
        gavsBar->setObjectName(QStringLiteral("gavsBar"));
        gavsBar->setGeometry(QRect(7, 230, 161, 31));
        gavsBar->setValue(24);
        gavsBar->setTextVisible(false);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(-40, 500, 491, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        interact = new QPushButton(centralWidget);
        interact->setObjectName(QStringLiteral("interact"));
        interact->setGeometry(QRect(930, 270, 95, 31));
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(350, 140, 47, 24));
        V3 = new QLineEdit(centralWidget);
        V3->setObjectName(QStringLiteral("V3"));
        V3->setGeometry(QRect(880, 220, 111, 33));
        by = new QLineEdit(centralWidget);
        by->setObjectName(QStringLiteral("by"));
        by->setGeometry(QRect(970, 50, 41, 31));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(810, 120, 51, 21));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(1030, 40, 141, 91));
        radioFilled_5 = new QRadioButton(widget_3);
        radioFilled_5->setObjectName(QStringLiteral("radioFilled_5"));
        radioFilled_5->setGeometry(QRect(30, 20, 102, 20));
        radioHollow_5 = new QRadioButton(widget_3);
        radioHollow_5->setObjectName(QStringLiteral("radioHollow_5"));
        radioHollow_5->setGeometry(QRect(30, 50, 102, 20));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(1010, 220, 95, 31));
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(800, 10, 141, 21));
        label_15->setFont(font);
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(800, 50, 66, 21));
        bx = new QLineEdit(centralWidget);
        bx->setObjectName(QStringLiteral("bx"));
        bx->setGeometry(QRect(890, 50, 41, 31));
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(810, 220, 21, 21));
        blength = new QLineEdit(centralWidget);
        blength->setObjectName(QStringLiteral("blength"));
        blength->setGeometry(QRect(880, 120, 111, 33));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(950, 50, 21, 21));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(810, 170, 51, 21));
        bwidth = new QLineEdit(centralWidget);
        bwidth->setObjectName(QStringLiteral("bwidth"));
        bwidth->setGeometry(QRect(880, 170, 111, 33));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(870, 50, 21, 21));
        MainWindow->setCentralWidget(centralWidget);
        line->raise();
        line_2->raise();
        label->raise();
        radioY->raise();
        radioX->raise();
        simple_axis->raise();
        simple_val->raise();
        pushButton->raise();
        label_2->raise();
        size->raise();
        looper->raise();
        label_3->raise();
        label_4->raise();
        pushButton_2->raise();
        label_5->raise();
        label_6->raise();
        label_7->raise();
        cX->raise();
        cY->raise();
        label_8->raise();
        label_9->raise();
        label_10->raise();
        radiusBox->raise();
        label_11->raise();
        label_12->raise();
        rV0_Box->raise();
        pushButton_3->raise();
        pushButton_4->raise();
        line_3->raise();
        radioJ->raise();
        radioG->raise();
        radioS->raise();
        radioM->raise();
        radioHollow->raise();
        radioFilled->raise();
        graphicsView->raise();
        tab1->raise();
        tab2->raise();
        gavsBar->raise();
        line_4->raise();
        interact->raise();
        spinBox->raise();
        V3->raise();
        by->raise();
        label_16->raise();
        widget_3->raise();
        pushButton_5->raise();
        label_15->raise();
        label_14->raise();
        bx->raise();
        label_13->raise();
        blength->raise();
        label_18->raise();
        label_19->raise();
        bwidth->raise();
        label_17->raise();
        gavsLabel->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1433, 22));
        menuES = new QMenu(menuBar);
        menuES->setObjectName(QStringLiteral("menuES"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuES->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Simple Bound", Q_NULLPTR));
        radioY->setText(QApplication::translate("MainWindow", "Y parallel", Q_NULLPTR));
        radioX->setText(QApplication::translate("MainWindow", "X parallel", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "General", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Grid size:", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "#loops:", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Create/Reset", Q_NULLPTR));
        gavsLabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Point:", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "V0:", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Radial Bound", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "Centre:", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Radius: ", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "V0:", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Run", Q_NULLPTR));
        radioJ->setText(QApplication::translate("MainWindow", "Jacobi", Q_NULLPTR));
        radioG->setText(QApplication::translate("MainWindow", "Gauss-Seidel", Q_NULLPTR));
        radioS->setText(QApplication::translate("MainWindow", "SOR", Q_NULLPTR));
        radioM->setText(QApplication::translate("MainWindow", "Multigrid", Q_NULLPTR));
        radioHollow->setText(QApplication::translate("MainWindow", "Hollow", Q_NULLPTR));
        radioFilled->setText(QApplication::translate("MainWindow", "Filled", Q_NULLPTR));
        tab1->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        tab2->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        interact->setText(QApplication::translate("MainWindow", "Interact", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "length:", Q_NULLPTR));
        radioFilled_5->setText(QApplication::translate("MainWindow", "Filled", Q_NULLPTR));
        radioHollow_5->setText(QApplication::translate("MainWindow", "Hollow", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Rectangular Bound", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Corner:", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "V0:", Q_NULLPTR));
        label_18->setText(QApplication::translate("MainWindow", "Y:", Q_NULLPTR));
        label_19->setText(QApplication::translate("MainWindow", "width:", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "X:", Q_NULLPTR));
        menuES->setTitle(QApplication::translate("MainWindow", "ES", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
