#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSlider>
#include <QImage>
#include <QRadioButton>
#include <QWindow>

extern int grid,loop;
extern float i2, j2, w;
extern double values[10000][10000], values_new[10000][10000];
extern bool bounds[10000][10000];
extern double closeness, square_dist;
extern double dist;

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
    void run_code();
    void JACOBI();
    void GAUSS();
    void SOR();

private:
    //buttons
    QPushButton *linear;
    QPushButton *circle;
    QPushButton *complie;

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
    QSlider *relatation;

    //radiobuttons
    QRadioButton *Jacobi;
    QRadioButton *Gauss;
    QRadioButton *sor;
    QRadioButton *horizontal;
    QRadioButton *vertical;
    QRadioButton *hollow;
    QRadioButton *filled;

};

#endif // MAINWINDOW_H
