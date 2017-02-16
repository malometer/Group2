#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QPainter>
#include <QProgressBar>
#include <unistd.h>
#include <QProcess>

using namespace std;



int simpleDist=0;
int simpleVal=0;
float radialR=0;
int cX = 0;
int cY = 0;
float radialVal=0;
int grid,loop;
float i2, j2, w;
double values[10000][10000], values_new[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;
bool HorF;
bool XorY;
double subBench [10000][10000];





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    square = new MySquare();
    scene->addItem(square);

    ui->tab1->hide();
    ui->tab2->hide();
    ui->interact->hide();
    ui->spinBox->hide();

     ui->gavsBar->setValue(0);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::run_code() {





    grid = 100;

    for(int i=0; i<=grid-1; i++) {
        for(int j=0; j<=grid-1; j++) {

            bounds[i][j] = true;
        }
    }


        loop = 100;
        simpleDist = 0;
        simpleVal = 0;

}

//Create Grid Button
void MainWindow::on_pushButton_2_clicked()
{
    grid = ui->size->text().toInt();
    loop = ui->looper->text().toInt();

    ui->tab1->hide();
    ui->tab2->hide();

    ui->interact->hide();

    for (int i = 0; i < grid; i++) {
        for(int j=0; j < grid; j++) {

            values [i][j] = 0;
            bounds[i][j] = true;


        }
        }

   // QImage image(grid,grid,QImage::Format_RGB32);

    QPixmap pix(grid,grid);
    QPainter painter(&pix);
    QColor myPenColor;
    myPenColor = QColor(0,0,0,255);
    QPen pen;
    pen.setColor(myPenColor);
    painter.setPen(pen);

    for (int i = 0; i < grid; i++) {
        for(int j=0; j < grid; j++) {
                painter.drawPoint(i,j);

         }
    }

   ui->gavsLabel->resize(grid,grid);
   ui->gavsLabel->setPixmap(pix);









}

//Simple Bound Button
void MainWindow::on_pushButton_clicked()
{

   simpleDist = ui->simple_axis->text().toInt();
   simpleVal = ui->simple_val->text().toInt();

   if(ui->radioY->isChecked()){
       XorY = true;
   } else if(ui->radioX->isChecked()){
       XorY = false;
   }

   create_line();
   myPainter();




}

void MainWindow::on_pushButton_3_clicked()
{

    cX = ui->cX->text().toInt();
    cY = ui->cY->text().toInt();
    radialR = ui->radiusBox->text().toInt();
    radialVal = ui->rV0_Box->text().toInt();

    if(ui->radioFilled->isChecked()){
        HorF = true;
    } else if(ui->radioHollow->isChecked()){
        HorF = false;
    }



    create_circle();
    myPainter();



}


void MainWindow::on_pushButton_4_clicked()
{

   // ui->gavsBar->setMinimum(0);
    //ui->gavsBar->setMaximum(0);



    if (ui->radioJ->isChecked()) {
        JACOBI(); ui->interact->hide();
        usleep(5000000);
        QPixmap plot("../LinuxUiUpdate/plot1.jpg");
        ui->gavsLabel->resize(grid,grid);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
        cout << "should have plot" << endl;
    } else if (ui->radioG->isChecked()) {
        gauss_seidel();
        usleep(5000000);
        QPixmap plot("/Users/Honi/LinuxUiUpdate/plot1.jpg");
        ui->gavsLabel->resize(grid,grid);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
        cout << "should have plot" << endl;

    } else if (ui->radioS->isChecked()) {
        w = ui->spinBox->value();
        SOR();
        usleep(5000000);
        QPixmap plot("plot1.jpg");
        ui->gavsLabel->resize(grid,grid);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
        cout << "should have plot" << endl;
    } else if (ui->radioM->isChecked()){
        multigrid();
        usleep(5000000);
        QPixmap plot("../LinuxUiUpdate/plot1.jpg");
        ui->gavsLabel->resize(grid,grid);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
    }else {
        gauss_seidel();
        usleep(5000000);
        QPixmap plot("../LinuxUiUpdate/plot1.jpg");
        ui->gavsLabel->resize(grid,grid);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
        cout << "should have plot" << endl;
    }

    ui->tab1->show();
    ui->tab2->show();
}

void MainWindow::myPainter() {

   // QImage image(grid,grid,QImage::Format_RGB32);

    QPixmap pix(grid,grid);
    QPainter painter(&pix);
    QColor myPenColor;
    QColor positive = QColor(64,224,208,255);
    QColor negative = QColor(255,105,180,255);
    QColor ground = QColor(255,255,255,255);
    myPenColor = QColor(0,0,0,255);
    QPen pen;
    pen.setColor(myPenColor);
    painter.setPen(pen);

    for (int i = 0; i < grid; i++) {
        for(int j=0; j < grid; j++) {
                painter.drawPoint(i,j);

         }
    }


    myPenColor = QColor(255,105,180,255);
    pen.setColor(myPenColor);
    painter.setPen(pen);



    for (int i = 0; i < grid; i++) {
        for(int j=0; j < grid; j++) {

            if (bounds[i][j] == false) {
                    if (values[i][j] > 0) {
                        myPenColor = positive;
                        pen.setColor(myPenColor);
                        painter.setPen(pen);
                    } else if (values[i][j] < 0) {
                        myPenColor = negative;
                        pen.setColor(myPenColor);
                        painter.setPen(pen);
                    } else {
                        myPenColor = ground;
                        pen.setColor(myPenColor);
                        painter.setPen(pen);
                    }
                painter.drawPoint(i,j);

            }
         }
    }

   ui->gavsLabel->resize(grid,grid);
   ui->gavsLabel->setPixmap(pix);
   ui->interact->hide();

}




void MainWindow::on_pushButton_4_released()
{
    ui->gavsBar->setMinimum(0);
    ui->gavsBar->setMaximum(0);
}

void MainWindow::on_tab1_clicked()
{
    QPixmap plot("../LinuxUiUpdate/plot1.jpg");
    ui->gavsLabel->resize(grid,grid);
    ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gavsLabel->setPixmap(plot);
    cout << "should have plot" << endl;
    ui->interact->hide();
}

void MainWindow::on_tab2_clicked()
{
    QPixmap plot("../LinuxUiUpdate/contour.jpg");
    ui->gavsLabel->resize(grid,grid);
    ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gavsLabel->setPixmap(plot);
    cout << "should have plot" << endl;
     ui->interact->show();

}

void MainWindow::on_interact_clicked()
{
     QProcess::startDetached("../LinuxUiUpdate/test.sh");
     cout << "should interact" << endl;
}



void MainWindow::on_pushButton_5_clicked()
{
    //create the box
    /*
    bx = ui->bx->text().toInt();
    by = ui->by->text().toInt();
    blength= ui->blength->text().toInt();
    bwidth= ui->bwidth->text().toInt();
    V3 = ui->V3->text().toInt();


    if(ui->radioFilled_2->isChecked()){
        filled = 1;
    } else if(ui->radioHollow_2->isChecked()){
        filled = 0;
    }
    */


    create_box();
    myPainter();

}



void MainWindow::on_radioS_clicked()
{
    ui->spinBox->show();
}

void MainWindow::on_radioM_clicked()
{
    ui->spinBox->show();
}
