#include "window2.h"
#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <QWidget>
#include <QMainWindow>

Window2::Window2(QWidget *parent)
: QWidget(parent)
{
    Button1 = new QPushButton("one", this);
//    plot = new QImage;
//    plot->
/*
    QGraphicsScene scene;
        QGraphicsView view(&scene);
        QGraphicsPixmapItem item(QPixmap("/Users/Honi/Documents/Group2/GRoup2/plot1.jpg"));
        scene.addItem(&item);
        view.show();
*/
}

