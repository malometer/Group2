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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>


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

private:
    Ui::MainWindow *ui;

    QPushButton *push;

    //buttons
    QPushButton *linear;
    QPushButton *circle;
    QPushButton *complie;
    QPushButton *plot1;
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

// /* task two
    QSlider *a2;
    QSlider *w2;
    QSlider *h2;
    QSlider *d2;
    QSlider *V2;
//    */

    //radiobuttons
    QRadioButton *Jacobi;
    QRadioButton *Gauss;
    QRadioButton *sor;
    QRadioButton *horizontal;
    QRadioButton *vertical;
    QRadioButton *hollow;
    QRadioButton *filled;

    //image
    QLabel *plot2;
    QPixmap *plotone;
    QGraphicsScene *scene;
    QPixmap image;
    QImage *plottwo;

    //progress
    QProgressBar *prog;

};

#endif // MAINWINDOW_H
