/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QToolButton *tab1;
    QToolButton *tab2;
    QProgressBar *gavsBar;
    QFrame *line_4;
    QPushButton *interact;
    QGroupBox *groupBox;
    QRadioButton *radioM;
    QRadioButton *radioG;
    QRadioButton *radioJ;
    QRadioButton *radioS;
    QFrame *frame;
    QWidget *widget_2;
    QRadioButton *radioX;
    QRadioButton *radioY;
    QWidget *widget_3;
    QRadioButton *radioFilled;
    QRadioButton *radioHollow;
    QFrame *frame_3;
    QFrame *frame_2;
    QLabel *label_13;
    QLabel *label_14;
    QWidget *widget_4;
    QRadioButton *radioFilled_2;
    QRadioButton *radioHollow_2;
    QFrame *frame_4;
    QLabel *label_15;
    QLabel *label_16;
    QLineEdit *rX;
    QLineEdit *length;
    QLineEdit *rY;
    QLabel *label_17;
    QPushButton *recButoon;
    QLabel *label_18;
    QLineEdit *recV0;
    QLineEdit *width;
    QLabel *label_19;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1009, 825);
        MainWindow->setAutoFillBackground(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(480, 0, 20, 861));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(10, 260, 1431, 20));
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
        simple_axis = new QLineEdit(centralWidget);
        simple_axis->setObjectName(QStringLiteral("simple_axis"));
        simple_axis->setGeometry(QRect(80, 330, 131, 33));
        simple_val = new QLineEdit(centralWidget);
        simple_val->setObjectName(QStringLiteral("simple_val"));
        simple_val->setGeometry(QRect(80, 390, 131, 33));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 460, 95, 31));
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
        pushButton_2->setGeometry(QRect(230, 230, 131, 31));
        gavsLabel = new QLabel(centralWidget);
        gavsLabel->setObjectName(QStringLiteral("gavsLabel"));
        gavsLabel->setGeometry(QRect(500, 290, 481, 241));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 330, 41, 21));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 390, 21, 21));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 520, 101, 21));
        label_7->setFont(font);
        cX = new QLineEdit(centralWidget);
        cX->setObjectName(QStringLiteral("cX"));
        cX->setGeometry(QRect(100, 560, 41, 31));
        cY = new QLineEdit(centralWidget);
        cY->setObjectName(QStringLiteral("cY"));
        cY->setGeometry(QRect(180, 560, 41, 31));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(80, 560, 21, 21));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(160, 560, 21, 21));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 560, 66, 21));
        radiusBox = new QLineEdit(centralWidget);
        radiusBox->setObjectName(QStringLiteral("radiusBox"));
        radiusBox->setGeometry(QRect(90, 630, 111, 33));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 630, 51, 21));
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 690, 21, 21));
        rV0_Box = new QLineEdit(centralWidget);
        rV0_Box->setObjectName(QStringLiteral("rV0_Box"));
        rV0_Box->setGeometry(QRect(90, 690, 111, 33));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(390, 730, 95, 31));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(390, 230, 95, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_4->setFont(font1);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(1000, 0, 20, 541));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        tab1 = new QToolButton(centralWidget);
        tab1->setObjectName(QStringLiteral("tab1"));
        tab1->setGeometry(QRect(710, 730, 31, 29));
        tab2 = new QToolButton(centralWidget);
        tab2->setObjectName(QStringLiteral("tab2"));
        tab2->setGeometry(QRect(740, 730, 31, 29));
        gavsBar = new QProgressBar(centralWidget);
        gavsBar->setObjectName(QStringLiteral("gavsBar"));
        gavsBar->setGeometry(QRect(7, 230, 211, 31));
        gavsBar->setValue(24);
        gavsBar->setTextVisible(false);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(0, 500, 491, 20));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        interact = new QPushButton(centralWidget);
        interact->setObjectName(QStringLiteral("interact"));
        interact->setGeometry(QRect(910, 270, 95, 31));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(260, 30, 191, 171));
        radioM = new QRadioButton(groupBox);
        radioM->setObjectName(QStringLiteral("radioM"));
        radioM->setGeometry(QRect(50, 130, 110, 26));
        radioG = new QRadioButton(groupBox);
        radioG->setObjectName(QStringLiteral("radioG"));
        radioG->setGeometry(QRect(50, 50, 110, 26));
        radioJ = new QRadioButton(groupBox);
        radioJ->setObjectName(QStringLiteral("radioJ"));
        radioJ->setGeometry(QRect(50, 10, 110, 26));
        radioS = new QRadioButton(groupBox);
        radioS->setObjectName(QStringLiteral("radioS"));
        radioS->setGeometry(QRect(50, 90, 110, 26));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(20, -10, 171, 181));
        QFont font2;
        font2.setStrikeOut(false);
        font2.setKerning(true);
        frame->setFont(font2);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame->raise();
        radioM->raise();
        radioG->raise();
        radioJ->raise();
        radioS->raise();
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(290, 320, 120, 80));
        radioX = new QRadioButton(widget_2);
        radioX->setObjectName(QStringLiteral("radioX"));
        radioX->setGeometry(QRect(10, 50, 110, 26));
        radioY = new QRadioButton(widget_2);
        radioY->setObjectName(QStringLiteral("radioY"));
        radioY->setGeometry(QRect(10, 10, 110, 26));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(290, 560, 151, 111));
        radioFilled = new QRadioButton(widget_3);
        radioFilled->setObjectName(QStringLiteral("radioFilled"));
        radioFilled->setGeometry(QRect(30, 60, 110, 26));
        radioHollow = new QRadioButton(widget_3);
        radioHollow->setObjectName(QStringLiteral("radioHollow"));
        radioHollow->setGeometry(QRect(30, 20, 110, 26));
        frame_3 = new QFrame(widget_3);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setGeometry(QRect(-1, 10, 141, 81));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        frame_3->raise();
        radioFilled->raise();
        radioHollow->raise();
        frame_2 = new QFrame(centralWidget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(280, 310, 141, 101));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(520, 210, 21, 21));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(660, 50, 21, 21));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(790, 50, 151, 111));
        radioFilled_2 = new QRadioButton(widget_4);
        radioFilled_2->setObjectName(QStringLiteral("radioFilled_2"));
        radioFilled_2->setGeometry(QRect(30, 60, 110, 26));
        radioHollow_2 = new QRadioButton(widget_4);
        radioHollow_2->setObjectName(QStringLiteral("radioHollow_2"));
        radioHollow_2->setGeometry(QRect(30, 20, 110, 26));
        frame_4 = new QFrame(widget_4);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setGeometry(QRect(0, 0, 151, 111));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        frame_4->raise();
        radioFilled_2->raise();
        radioHollow_2->raise();
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(580, 50, 21, 21));
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(510, 50, 66, 21));
        rX = new QLineEdit(centralWidget);
        rX->setObjectName(QStringLiteral("rX"));
        rX->setGeometry(QRect(600, 50, 41, 31));
        length = new QLineEdit(centralWidget);
        length->setObjectName(QStringLiteral("length"));
        length->setGeometry(QRect(590, 120, 111, 33));
        rY = new QLineEdit(centralWidget);
        rY->setObjectName(QStringLiteral("rY"));
        rY->setGeometry(QRect(680, 50, 41, 31));
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(510, 10, 141, 21));
        label_17->setFont(font);
        recButoon = new QPushButton(centralWidget);
        recButoon->setObjectName(QStringLiteral("recButoon"));
        recButoon->setGeometry(QRect(910, 240, 95, 31));
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(520, 120, 51, 21));
        recV0 = new QLineEdit(centralWidget);
        recV0->setObjectName(QStringLiteral("recV0"));
        recV0->setGeometry(QRect(590, 210, 111, 33));
        width = new QLineEdit(centralWidget);
        width->setObjectName(QStringLiteral("width"));
        width->setGeometry(QRect(590, 160, 111, 33));
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(520, 160, 51, 21));
        MainWindow->setCentralWidget(centralWidget);
        frame_2->raise();
        line->raise();
        line_2->raise();
        label->raise();
        simple_axis->raise();
        simple_val->raise();
        pushButton->raise();
        label_2->raise();
        size->raise();
        looper->raise();
        label_3->raise();
        label_4->raise();
        pushButton_2->raise();
        gavsLabel->raise();
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
        tab1->raise();
        tab2->raise();
        gavsBar->raise();
        line_4->raise();
        interact->raise();
        groupBox->raise();
        widget_2->raise();
        widget_3->raise();
        label_13->raise();
        label_14->raise();
        widget_4->raise();
        label_15->raise();
        label_16->raise();
        rX->raise();
        length->raise();
        rY->raise();
        label_17->raise();
        recButoon->raise();
        label_18->raise();
        recV0->raise();
        width->raise();
        label_19->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1009, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Simple Bound", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Add", 0));
        label_2->setText(QApplication::translate("MainWindow", "General", 0));
        label_3->setText(QApplication::translate("MainWindow", "Grid size:", 0));
        label_4->setText(QApplication::translate("MainWindow", "#loops:", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Create/Reset", 0));
        gavsLabel->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "Point:", 0));
        label_6->setText(QApplication::translate("MainWindow", "V0:", 0));
        label_7->setText(QApplication::translate("MainWindow", "Radial Bound", 0));
        label_8->setText(QApplication::translate("MainWindow", "X:", 0));
        label_9->setText(QApplication::translate("MainWindow", "Y:", 0));
        label_10->setText(QApplication::translate("MainWindow", "Centre:", 0));
        label_11->setText(QApplication::translate("MainWindow", "Radius: ", 0));
        label_12->setText(QApplication::translate("MainWindow", "V0:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Add", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "Run", 0));
        tab1->setText(QApplication::translate("MainWindow", "1", 0));
        tab2->setText(QApplication::translate("MainWindow", "2", 0));
        interact->setText(QApplication::translate("MainWindow", "Interact", 0));
        radioM->setText(QApplication::translate("MainWindow", "Multigrid", 0));
        radioG->setText(QApplication::translate("MainWindow", "Gauss-Seidel", 0));
        radioJ->setText(QApplication::translate("MainWindow", "Jacobi", 0));
        radioS->setText(QApplication::translate("MainWindow", "SOR", 0));
        radioX->setText(QApplication::translate("MainWindow", "X parallel", 0));
        radioY->setText(QApplication::translate("MainWindow", "Y parallel", 0));
        radioFilled->setText(QApplication::translate("MainWindow", "Filled", 0));
        radioHollow->setText(QApplication::translate("MainWindow", "Hollow", 0));
        label_13->setText(QApplication::translate("MainWindow", "V0:", 0));
        label_14->setText(QApplication::translate("MainWindow", "Y:", 0));
        radioFilled_2->setText(QApplication::translate("MainWindow", "Filled", 0));
        radioHollow_2->setText(QApplication::translate("MainWindow", "Hollow", 0));
        label_15->setText(QApplication::translate("MainWindow", "X:", 0));
        label_16->setText(QApplication::translate("MainWindow", "Origin", 0));
        label_17->setText(QApplication::translate("MainWindow", "Rectangular Bound", 0));
        recButoon->setText(QApplication::translate("MainWindow", "Add", 0));
        label_18->setText(QApplication::translate("MainWindow", "length:", 0));
        width->setText(QString());
        label_19->setText(QApplication::translate("MainWindow", "height:", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
