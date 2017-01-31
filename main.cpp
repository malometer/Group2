#include "mainwindow.h"
#include <QString>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <iostream>


int main(int argc, char *argv[])
{
    //create user interface
    QApplication app(argc, argv);
    MainWindow mainWindow;


    mainWindow.show();
    return app.exec();
 //   std::cout << "Complete" << std::endl;

}
