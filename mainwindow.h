#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QImage>
#include <QRadioButton>
#include <QWindow>
#include "window2.h"


extern QSlider size;

//#include "/Users/Honi/Button/testing.cpp"
void tester();

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
private slots:
    void create_line();
    void create_circle();
    void changedsize();
    void changewin();
    void run_code();
    void debug();
//    void aligment();
//    void choosemethod();
private:
    //buttons
    QPushButton *linear;
    QPushButton *circle;
    QPushButton *complie;
    //labels
    QLabel *textin;
    QLabel *label;
    //sliders
    QSlider *size;
    QSlider *resolution;
    QSlider *loops;
    QSlider *xcentre;
    QSlider *ycentre;
    QSlider *radius;
    QSlider *displacement;
    QSlider *V01;
    QSlider *V02;
    //radiobuttons
    QRadioButton *Jacobi;
    QRadioButton *horizontal;
    QRadioButton *vertical;
    //others
    QPushButton *win2;
    Window2 *window2;
};


#endif // MAINWINDOW_H

