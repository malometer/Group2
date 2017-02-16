#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QWidget>
#include <QPushButton>

#include <QLabel>
#include <QSlider>
#include <QImage>
#include <QRadioButton>
#include <QWindow>
#include <QGraphicsScene>
#include <QProgressBar>
#include <QGroupBox>
#include <QBitArray>


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>

#include <QtGui>
#include <QtCore>
#include "mysquare.h"

extern int grid,loop;
extern float i2, j2, w;
extern double values[10000][10000], values_new[10000][10000];
extern bool bounds[10000][10000];
extern double closeness, square_dist;
extern double dist;
extern int simpleDist;
extern int simpleVal;
extern float radialR;
extern int cX ;
extern int cY;
extern float radialVal;
extern bool HorF;
extern bool XorY;
extern int widthVal;
extern int lengthVal;


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:





    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

     void progressBar();
     void stopBar();



private slots:
    void create_line();
    void create_circle();
    void create_box();
    void run_code();
    void JACOBI();
    void GAUSS();
    void SOR();


    void myPainter();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();



    void on_tab1_clicked();

    void on_tab2_clicked();

    void on_interact_clicked();

    void on_recButoon_clicked();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    MySquare *square;

};



#endif // MAINWINDOW_H
