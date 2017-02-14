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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *linetab;
    QPushButton *pushButton;
    QPushButton *linear;
    QGroupBox *groupBox;
    QRadioButton *horizontal;
    QRadioButton *vertical;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_5;
    QSlider *displacement;
    QLabel *label_6;
    QSlider *slideeeer;
    QLabel *label_8;
    QComboBox *comboBox;
    QLabel *label_7;
    QSlider *V02;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QDoubleSpinBox *doubleSpinBox_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QSpacerItem *verticalSpacer;
    QDoubleSpinBox *doubleSpinBox_4;
    QWidget *circletab;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_3;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QSlider *xcentre;
    QSlider *ycentre;
    QSlider *radius;
    QSlider *voltage;
    QLabel *label_14;
    QComboBox *comboBox_2;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QDoubleSpinBox *doubleSpinBox_7;
    QDoubleSpinBox *doubleSpinBox_6;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *circle;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_5;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_3;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QSlider *a2;
    QSlider *w2;
    QSlider *h2;
    QSlider *d2;
    QSlider *V2;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QDoubleSpinBox *doubleSpinBox_10;
    QDoubleSpinBox *doubleSpinBox_11;
    QDoubleSpinBox *doubleSpinBox_12;
    QDoubleSpinBox *doubleSpinBox_9;
    QDoubleSpinBox *doubleSpinBox_8;
    QPushButton *task22;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *complie;
    QPushButton *reset;
    QPushButton *pushButton_9;
    QPushButton *showimage;
    QLabel *plot2;
    QGroupBox *groupBox_5;
    QWidget *formLayoutWidget_4;
    QFormLayout *formLayout_4;
    QLabel *label_16;
    QSlider *resolution;
    QLabel *label_17;
    QSlider *loops;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_4;
    QDoubleSpinBox *doubleSpinBox_14;
    QDoubleSpinBox *doubleSpinBox_15;
    QWidget *formLayoutWidget_5;
    QFormLayout *formLayout_5;
    QRadioButton *Jacobi;
    QRadioButton *Gauss;
    QRadioButton *muligrid;
    QLabel *label_21;
    QRadioButton *sor;
    QLabel *label_15;
    QSlider *relatation;
    QSpacerItem *horizontalSpacer;
    QLabel *label_22;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(601, 436);
        MainWindow->setMinimumSize(QSize(533, 374));
        MainWindow->setMaximumSize(QSize(601, 436));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(290, 10, 311, 261));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(301, 261));
        tabWidget->setSizeIncrement(QSize(5, 0));
        tabWidget->setTabShape(QTabWidget::Rounded);
        linetab = new QWidget();
        linetab->setObjectName(QStringLiteral("linetab"));
        pushButton = new QPushButton(linetab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(310, 210, 115, 32));
        linear = new QPushButton(linetab);
        linear->setObjectName(QStringLiteral("linear"));
        linear->setGeometry(QRect(0, 200, 115, 32));
        groupBox = new QGroupBox(linetab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(180, 150, 111, 71));
        horizontal = new QRadioButton(groupBox);
        horizontal->setObjectName(QStringLiteral("horizontal"));
        horizontal->setGeometry(QRect(0, 30, 102, 20));
        vertical = new QRadioButton(groupBox);
        vertical->setObjectName(QStringLiteral("vertical"));
        vertical->setGeometry(QRect(0, 50, 102, 20));
        horizontal->raise();
        vertical->raise();
        groupBox_2 = new QGroupBox(linetab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 291, 151));
        formLayoutWidget = new QWidget(groupBox_2);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(0, 20, 231, 121));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        displacement = new QSlider(formLayoutWidget);
        displacement->setObjectName(QStringLiteral("displacement"));
        displacement->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, displacement);

        label_6 = new QLabel(formLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_6);

        slideeeer = new QSlider(formLayoutWidget);
        slideeeer->setObjectName(QStringLiteral("slideeeer"));
        slideeeer->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, slideeeer);

        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        comboBox = new QComboBox(formLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        V02 = new QSlider(formLayoutWidget);
        V02->setObjectName(QStringLiteral("V02"));
        V02->setOrientation(Qt::Horizontal);

        formLayout->setWidget(3, QFormLayout::FieldRole, V02);

        verticalLayoutWidget = new QWidget(linetab);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(240, 20, 61, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_2 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_2->setObjectName(QStringLiteral("doubleSpinBox_2"));

        verticalLayout->addWidget(doubleSpinBox_2);

        doubleSpinBox_3 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_3->setObjectName(QStringLiteral("doubleSpinBox_3"));

        verticalLayout->addWidget(doubleSpinBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        doubleSpinBox_4 = new QDoubleSpinBox(verticalLayoutWidget);
        doubleSpinBox_4->setObjectName(QStringLiteral("doubleSpinBox_4"));

        verticalLayout->addWidget(doubleSpinBox_4);

        tabWidget->addTab(linetab, QString());
        circletab = new QWidget();
        circletab->setObjectName(QStringLiteral("circletab"));
        pushButton_3 = new QPushButton(circletab);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 210, 115, 32));
        groupBox_3 = new QGroupBox(circletab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 0, 301, 201));
        formLayoutWidget_2 = new QWidget(groupBox_3);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 30, 201, 171));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        label_2 = new QLabel(formLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(formLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        xcentre = new QSlider(formLayoutWidget_2);
        xcentre->setObjectName(QStringLiteral("xcentre"));
        xcentre->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, xcentre);

        ycentre = new QSlider(formLayoutWidget_2);
        ycentre->setObjectName(QStringLiteral("ycentre"));
        ycentre->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, ycentre);

        radius = new QSlider(formLayoutWidget_2);
        radius->setObjectName(QStringLiteral("radius"));
        radius->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, radius);

        voltage = new QSlider(formLayoutWidget_2);
        voltage->setObjectName(QStringLiteral("voltage"));
        voltage->setOrientation(Qt::Horizontal);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, voltage);

        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_14);

        comboBox_2 = new QComboBox(formLayoutWidget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, comboBox_2);

        verticalLayoutWidget_2 = new QWidget(groupBox_3);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(220, 30, 68, 131));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_7 = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox_7->setObjectName(QStringLiteral("doubleSpinBox_7"));

        verticalLayout_2->addWidget(doubleSpinBox_7);

        doubleSpinBox_6 = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox_6->setObjectName(QStringLiteral("doubleSpinBox_6"));

        verticalLayout_2->addWidget(doubleSpinBox_6);

        doubleSpinBox_5 = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox_5->setObjectName(QStringLiteral("doubleSpinBox_5"));

        verticalLayout_2->addWidget(doubleSpinBox_5);

        doubleSpinBox = new QDoubleSpinBox(verticalLayoutWidget_2);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));

        verticalLayout_2->addWidget(doubleSpinBox);

        circle = new QPushButton(circletab);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(0, 200, 115, 32));
        horizontalLayoutWidget = new QWidget(circletab);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(-100, 240, 211, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout->addWidget(pushButton_5);

        tabWidget->addTab(circletab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 291, 301));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy1);
        formLayoutWidget_3 = new QWidget(groupBox_4);
        formLayoutWidget_3->setObjectName(QStringLiteral("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(0, 20, 171, 171));
        formLayout_3 = new QFormLayout(formLayoutWidget_3);
        formLayout_3->setSpacing(6);
        formLayout_3->setContentsMargins(11, 11, 11, 11);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(formLayoutWidget_3);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_9);

        label_10 = new QLabel(formLayoutWidget_3);
        label_10->setObjectName(QStringLiteral("label_10"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_10);

        label_11 = new QLabel(formLayoutWidget_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_11);

        label_12 = new QLabel(formLayoutWidget_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_12);

        label_13 = new QLabel(formLayoutWidget_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_13);

        a2 = new QSlider(formLayoutWidget_3);
        a2->setObjectName(QStringLiteral("a2"));
        a2->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, a2);

        w2 = new QSlider(formLayoutWidget_3);
        w2->setObjectName(QStringLiteral("w2"));
        w2->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, w2);

        h2 = new QSlider(formLayoutWidget_3);
        h2->setObjectName(QStringLiteral("h2"));
        h2->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, h2);

        d2 = new QSlider(formLayoutWidget_3);
        d2->setObjectName(QStringLiteral("d2"));
        d2->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, d2);

        V2 = new QSlider(formLayoutWidget_3);
        V2->setObjectName(QStringLiteral("V2"));
        V2->setOrientation(Qt::Horizontal);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, V2);

        verticalLayoutWidget_3 = new QWidget(groupBox_4);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(190, 20, 91, 171));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_10 = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_10->setObjectName(QStringLiteral("doubleSpinBox_10"));

        verticalLayout_3->addWidget(doubleSpinBox_10);

        doubleSpinBox_11 = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_11->setObjectName(QStringLiteral("doubleSpinBox_11"));

        verticalLayout_3->addWidget(doubleSpinBox_11);

        doubleSpinBox_12 = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_12->setObjectName(QStringLiteral("doubleSpinBox_12"));

        verticalLayout_3->addWidget(doubleSpinBox_12);

        doubleSpinBox_9 = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_9->setObjectName(QStringLiteral("doubleSpinBox_9"));

        verticalLayout_3->addWidget(doubleSpinBox_9);

        doubleSpinBox_8 = new QDoubleSpinBox(verticalLayoutWidget_3);
        doubleSpinBox_8->setObjectName(QStringLiteral("doubleSpinBox_8"));

        verticalLayout_3->addWidget(doubleSpinBox_8);

        task22 = new QPushButton(groupBox_4);
        task22->setObjectName(QStringLiteral("task22"));
        task22->setGeometry(QRect(0, 200, 115, 32));
        horizontalLayoutWidget_2 = new QWidget(groupBox_4);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(9, 259, 321, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(tab, QString());
        complie = new QPushButton(centralWidget);
        complie->setObjectName(QStringLiteral("complie"));
        complie->setGeometry(QRect(480, 340, 115, 32));
        reset = new QPushButton(centralWidget);
        reset->setObjectName(QStringLiteral("reset"));
        reset->setGeometry(QRect(10, 340, 115, 32));
        pushButton_9 = new QPushButton(centralWidget);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(180, 340, 115, 32));
        showimage = new QPushButton(centralWidget);
        showimage->setObjectName(QStringLiteral("showimage"));
        showimage->setGeometry(QRect(330, 340, 115, 32));
        plot2 = new QLabel(centralWidget);
        plot2->setObjectName(QStringLiteral("plot2"));
        plot2->setGeometry(QRect(350, 310, 71, 31));
        plot2->setMaximumSize(QSize(511, 251));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 0, 271, 331));
        formLayoutWidget_4 = new QWidget(groupBox_5);
        formLayoutWidget_4->setObjectName(QStringLiteral("formLayoutWidget_4"));
        formLayoutWidget_4->setGeometry(QRect(0, 40, 171, 61));
        formLayout_4 = new QFormLayout(formLayoutWidget_4);
        formLayout_4->setSpacing(6);
        formLayout_4->setContentsMargins(11, 11, 11, 11);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(formLayoutWidget_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_16);

        resolution = new QSlider(formLayoutWidget_4);
        resolution->setObjectName(QStringLiteral("resolution"));
        resolution->setOrientation(Qt::Horizontal);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, resolution);

        label_17 = new QLabel(formLayoutWidget_4);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_17);

        loops = new QSlider(formLayoutWidget_4);
        loops->setObjectName(QStringLiteral("loops"));
        loops->setOrientation(Qt::Horizontal);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, loops);

        verticalLayoutWidget_4 = new QWidget(groupBox_5);
        verticalLayoutWidget_4->setObjectName(QStringLiteral("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(190, 40, 71, 61));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_14 = new QDoubleSpinBox(verticalLayoutWidget_4);
        doubleSpinBox_14->setObjectName(QStringLiteral("doubleSpinBox_14"));

        verticalLayout_4->addWidget(doubleSpinBox_14);

        doubleSpinBox_15 = new QDoubleSpinBox(verticalLayoutWidget_4);
        doubleSpinBox_15->setObjectName(QStringLiteral("doubleSpinBox_15"));

        verticalLayout_4->addWidget(doubleSpinBox_15);

        formLayoutWidget_5 = new QWidget(groupBox_5);
        formLayoutWidget_5->setObjectName(QStringLiteral("formLayoutWidget_5"));
        formLayoutWidget_5->setGeometry(QRect(68, 140, 181, 164));
        formLayout_5 = new QFormLayout(formLayoutWidget_5);
        formLayout_5->setSpacing(6);
        formLayout_5->setContentsMargins(11, 11, 11, 11);
        formLayout_5->setObjectName(QStringLiteral("formLayout_5"));
        formLayout_5->setContentsMargins(0, 0, 0, 0);
        Jacobi = new QRadioButton(formLayoutWidget_5);
        Jacobi->setObjectName(QStringLiteral("Jacobi"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, Jacobi);

        Gauss = new QRadioButton(formLayoutWidget_5);
        Gauss->setObjectName(QStringLiteral("Gauss"));

        formLayout_5->setWidget(1, QFormLayout::FieldRole, Gauss);

        muligrid = new QRadioButton(formLayoutWidget_5);
        muligrid->setObjectName(QStringLiteral("muligrid"));

        formLayout_5->setWidget(2, QFormLayout::FieldRole, muligrid);

        label_21 = new QLabel(formLayoutWidget_5);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_5->setWidget(3, QFormLayout::LabelRole, label_21);

        sor = new QRadioButton(formLayoutWidget_5);
        sor->setObjectName(QStringLiteral("sor"));

        formLayout_5->setWidget(3, QFormLayout::FieldRole, sor);

        label_15 = new QLabel(formLayoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        formLayout_5->setWidget(4, QFormLayout::LabelRole, label_15);

        relatation = new QSlider(formLayoutWidget_5);
        relatation->setObjectName(QStringLiteral("relatation"));
        relatation->setOrientation(Qt::Horizontal);

        formLayout_5->setWidget(4, QFormLayout::FieldRole, relatation);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        formLayout_5->setItem(1, QFormLayout::LabelRole, horizontalSpacer);

        label_22 = new QLabel(formLayoutWidget_5);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_22);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 601, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        linear->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        horizontal->setText(QApplication::translate("MainWindow", "horiontal", Q_NULLPTR));
        vertical->setText(QApplication::translate("MainWindow", "vertical", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "distance", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "voltage", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(linetab), QApplication::translate("MainWindow", "create line", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "x centre", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "y centre", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "radius", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "voltage", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        circle->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(circletab), QApplication::translate("MainWindow", "create circle", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Task2", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "spacing", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "width", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "height", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "distance", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "voltage", Q_NULLPTR));
        task22->setText(QApplication::translate("MainWindow", "Add", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Task2", Q_NULLPTR));
        complie->setText(QApplication::translate("MainWindow", "RUN", Q_NULLPTR));
        reset->setText(QApplication::translate("MainWindow", "RESET", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "PushButton", Q_NULLPTR));
        showimage->setText(QApplication::translate("MainWindow", "Create jpg", Q_NULLPTR));
        plot2->setText(QApplication::translate("MainWindow", "TextLabel", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "GroupBox", Q_NULLPTR));
        label_16->setText(QApplication::translate("MainWindow", "grid size", Q_NULLPTR));
        label_17->setText(QApplication::translate("MainWindow", "lloops", Q_NULLPTR));
        Jacobi->setText(QApplication::translate("MainWindow", "Jacobi", Q_NULLPTR));
        Gauss->setText(QApplication::translate("MainWindow", "Gauss", Q_NULLPTR));
        muligrid->setText(QApplication::translate("MainWindow", "Miltigrid", Q_NULLPTR));
        label_21->setText(QString());
        sor->setText(QApplication::translate("MainWindow", "S.O.R", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "w", Q_NULLPTR));
        label_22->setText(QApplication::translate("MainWindow", "Method:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
