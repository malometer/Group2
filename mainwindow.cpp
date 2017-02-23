#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QMessageBox>
#include <QPainter>
#include <QProgressBar>
#include <unistd.h>
#include <QProcess>
#include <QPixmap>
#include <QCoreApplication>
#include <QMovie>

using namespace std;



int simpleDist=0;
int simpleVal=0;
float radialR=0;
int cX = 0;
int cY = 0;
float radialVal=0;
int widthVal = 0;
int lengthVal = 0;
int grid,loop,m;
float i2, j2, w;
double values[2000][2000], values_new[2000][2000];
double subBench [2000][2000];
bool bounds[2000][2000];
double closeness, square_dist;
double dist;
bool HorF;
bool XorY;
float digm, digc, digval, digval2;
int dix_1, dix_2, diy_1, diy_2;
float quad_a, quad_b, quad_c, quad_v0;

double init_clock=0, fin_clock=0, clock_dif=0;


//multigrid

int grid_num, coarse_loops, smoothing;






MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Electrostatic Boundaries");

    scene = new QGraphicsScene(this);
    //ui->graphicsView->setScene(scene);

    square = new MySquare();
    scene->addItem(square);

    ui->tab1->hide();
    ui->tab2->hide();
    ui->interact->hide();

    ui->coursness->hide();
    ui->gridLab->hide();
    ui->gridLab2->hide();
    ui->gridNumBox->hide();
    ui->loopsBox->hide();

    ui->looper->show();
    ui->noLoops->show();

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

    ui->origin->setText("0");
    ui->maxY->setText(ui->size->text());
    ui->maxX->setText(ui->size->text());


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


   ui->gavsLabel->resize(500,500);
   ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
   ui->gavsLabel->setScaledContents(true);
   ui->gavsLabel->setPixmap(pix);


}

//Simple Bound Button
void MainWindow::on_pushButton_clicked()
{

   simpleDist = ui->simple_axis->text().toInt();
   simpleVal = ui->simple_val->text().toInt();

   if(ui->radioY->isChecked()){
       XorY = true;    cX = ui->cX->text().toInt();
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

    progressBar();

    QMovie *radar = new QMovie("radar.gif");
    ui->radarLabel->setMovie(radar);
    ui->radarLabel->show();
    radar->start();



    init_clock = time(NULL);
    clock_t t;

    t = clock();


    if (ui->radioJ->isChecked()) {
        JACOBI(); ui->interact->hide();
        usleep(5000000);
        QPixmap plot("plot1.jpg");
        ui->gavsLabel->resize(500,500);
         ui->gavsLabel->setScaledContents(false);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
    } else if (ui->radioG->isChecked()) {
        GAUSS();
        QCoreApplication::processEvents();
        usleep(5000000);
        QCoreApplication::processEvents();
        QPixmap plot("plot1.jpg");
        ui->gavsLabel->resize(500,500);
         ui->gavsLabel->setScaledContents(false);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);


    } else if (ui->radioS->isChecked()) {
        SOR();
        usleep(5000000);
        QPixmap plot("plot1.jpg");
        ui->gavsLabel->resize(500,500);
         ui->gavsLabel->setScaledContents(false);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);

     } else if (ui->radioM->isChecked()) {


         grid_num = ui->gridNumBox->text().toInt();
         coarse_loops = ui->loopsBox->text().toInt();

         multigrid();
         usleep(5000000);
         QPixmap plot("plot1.jpg");
         ui->gavsLabel->resize(500,500);
         ui->gavsLabel->setScaledContents(false);
         ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
         ui->gavsLabel->setPixmap(plot);

   } else {
        GAUSS();
        QCoreApplication::processEvents();
        usleep(5000000);
        QCoreApplication::processEvents();
        QPixmap plot("plot1.jpg");
        ui->gavsLabel->resize(500,500);
         ui->gavsLabel->setScaledContents(false);
        ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        ui->gavsLabel->setPixmap(plot);
    }

    fin_clock = time(NULL);

    clock_dif = fin_clock - init_clock;


    t = clock()-t;

    cout<< "t is " << t << endl;

    ui->tab1->show();
    ui->tab2->show();
    stopBar();
    cout << "m = " << m << endl;
    ui->loopLabel->setText("#loops: " +(QString::number(m)));
    ui->timeLabel->setText("Elapsed time: " +(QString::number(clock_dif))+"s");
    ui->CPUlabel->setText("#CPU ticks: " +(QString::number(t)));
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
                painter.drawPoint(grid,grid);

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
                painter.drawPoint(i,grid-j);

            }
         }
    }

   ui->gavsLabel->resize(500,500);
   ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
   ui->gavsLabel->setScaledContents(true);
   ui->gavsLabel->setPixmap(pix);
   ui->interact->hide();

}




void MainWindow::progressBar()
{
    ui->gavsBar->setMinimum(0);
    ui->gavsBar->setMaximum(0);
}

void MainWindow::stopBar()
{
    ui->gavsBar->setMinimum(0);
    ui->gavsBar->setMaximum(100);
    ui->gavsBar->setValue(24);
}

void MainWindow::on_tab1_clicked()
{
    QPixmap plot("plot1.jpg");
    ui->gavsLabel->resize(500,500);
    ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gavsLabel->setPixmap(plot);
    ui->interact->hide();
}

void MainWindow::on_tab2_clicked()
{
    QPixmap plot("contour.jpg");
    ui->gavsLabel->resize(500,500);
    ui->gavsLabel->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    ui->gavsLabel->setPixmap(plot);
    ui->interact->show();

}

void MainWindow::on_interact_clicked()
{
     QProcess::startDetached("./test.sh");

}



void MainWindow::on_recButoon_clicked()
{

    cX = ui->rX->text().toInt();
    cY = ui->rY->text().toInt();

    lengthVal = ui->length->text().toInt();
    widthVal = ui->width->text().toInt();

    radialVal = ui->recV0->text().toInt();

    if(ui->radioFilled_2->isChecked()){
        HorF = true;
    } else if(ui->radioHollow_2->isChecked()){
        HorF = false;
    }



    create_box();
    myPainter();


}

void MainWindow::on_digButton_clicked()
{
    digm = ui->dm->text().toFloat();
    digc = ui->dc->text().toFloat();
    digval = ui->digV0->text().toFloat();
    grid = ui->size->text().toFloat();
    cout << "y = " << digm << "x + " << digc << endl;
    create_diagonal1();
    myPainter();
}

void MainWindow::on_digButton_2_clicked()
{
    dix_1 = ui->dx_2->text().toInt();
    dix_2 = ui->dx_3->text().toInt();
    diy_1 = ui->dy_1->text().toInt();
    diy_2 = ui->dy_2->text().toInt();
    grid = ui->size->text().toFloat();
    digval2 = ui->digV0_2->text().toFloat();
    cout << diy_2 << " - " << diy_1 << " = m( " << dix_2 << " - " << dix_1 << " )" << endl;

    create_diagonal2();
    myPainter();

}

void MainWindow::on_pushButton_5_clicked()
{
    quad_a = ui->quadA->text().toFloat();
    quad_b = ui->quadB->text().toFloat();
    quad_c = ui->quadC->text().toFloat();
    quad_v0 = ui->quadV0->text().toFloat();

    create_diagonal_quad();
    myPainter();
}

void MainWindow::on_pushButton_6_clicked()
{
    cX = ui->pX->text().toFloat();
    cY = ui->pY->text().toFloat();
    radialVal = ui->pV0->text().toFloat();

    point_source();
    myPainter();
}

void MainWindow::on_radioM_clicked()
{
    ui->coursness->show();
    ui->gridLab->show();
    ui->gridLab2->show();
    ui->gridNumBox->show();
    ui->loopsBox->show();

    ui->looper->hide();
    ui->noLoops->hide();
}

void MainWindow::on_radioJ_clicked()
{
    ui->coursness->hide();
    ui->gridLab->hide();
    ui->gridLab2->hide();
    ui->gridNumBox->hide();
    ui->loopsBox->hide();

    ui->looper->show();
    ui->noLoops->show();
}

void MainWindow::on_radioG_clicked()
{
    ui->coursness->hide();
    ui->gridLab->hide();
    ui->gridLab2->hide();
    ui->gridNumBox->hide();
    ui->loopsBox->hide();

    ui->looper->show();
    ui->noLoops->show();
}

void MainWindow::on_radioS_clicked()
{
    ui->coursness->hide();
    ui->gridLab->hide();
    ui->gridLab2->hide();
    ui->gridNumBox->hide();
    ui->loopsBox->hide();

    ui->looper->show();
    ui->noLoops->show();
}
