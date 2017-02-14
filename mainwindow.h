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
#include <QGridLayout>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>

/*
#include "circle.cpp"
#include "gauss.cpp"
#include "jacobi.cpp"
#include "line.cpp"
#include "sor.cpp"
#include "task2.cpp"
*/


extern int grid,loop;
extern float i2, j2, w;
extern double values[10000][10000], values_new[10000][10000];
extern bool bounds[10000][10000];
extern double closeness, square_dist;
extern double dist;

/*
//global varibles
int grid,loop;
float i2, j2, w;
double values[10000][10000], values_new[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;
*/

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void create_line();
    void create_circle();
    void run_code();
    void JACOBI();
    void GAUSS();
    void SOR();
    void task2();
    void image();
    void wipe();
    void create_box();

private:
    Ui::MainWindow *ui;

    //buttons
    QPushButton *linear;
    QPushButton *circle;
    QPushButton *complie;
    QPushButton *reset;
    QPushButton *task22;
    QPushButton *showline;
    QPushButton *showcircle;
    QPushButton *showtask2;


    //group boxes
    QGroupBox *initial;
    QGroupBox *initilisecircle;
    QGroupBox *initiliseline;
    QGroupBox *tasktwo;

    //sliders
    QSlider *size;
    QSlider *resolution;
    QSlider *loops;
    QSlider *relatation;

    QSlider *xcentre;
    QSlider *ycentre;
    QSlider *radius;
    QSlider *V01;

    QSlider *displacement;
    QSlider *V02;

//  task two
    QSlider *a2;
    QSlider *w2;
    QSlider *h2;
    QSlider *d2;
    QSlider *V2;
//

    //radiobuttons
    QRadioButton *Jacobi;
    QRadioButton *Gauss;
    QRadioButton *sor;
    QRadioButton *horizontal;
    QRadioButton *vertical;
    QRadioButton *hollow;
    QRadioButton *filled;
    QRadioButton *boxfill;
    QRadioButton *boxempty;

    //image
    QLabel *plot2;
    QPushButton *showimage;

    //box
    QSlider *bx;
    QSlider *by;
    QSlider *blength;
    QSlider *bwidth;
    QSlider *V3;
    QPushButton *box;


};

#endif // MAINWINDOW_H
