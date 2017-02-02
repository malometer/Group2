#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>
#include <QCoreApplication>
#include <iostream>
#include <QGroupBox>
using namespace std;

int grid,loop;
float i2, j2, w;
double values[10000][10000], values_new[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{


    setGeometry(200, 200, 500, 500);
    setWindowTitle("Electrostatic simulation");

    //group boxes
    QGroupBox *initial = new QGroupBox("Grid values", this);
    QGroupBox *initilisecircle = new QGroupBox("circle", this);
    QGroupBox *initiliseline = new QGroupBox("lines", this);
        //how does this work?

    // Create the button, make "this" the parent
    linear = new QPushButton("Create Line", initiliseline);
    circle = new QPushButton("Create Circle", initilisecircle);
    complie = new QPushButton("Complie", this);

    //create sliders
    resolution = new QSlider(Qt::Horizontal, initial);
    loops = new QSlider(Qt::Horizontal, initial);
    xcentre = new QSlider(Qt::Horizontal, initilisecircle);
    ycentre = new QSlider(Qt::Horizontal, initilisecircle);
    radius = new QSlider(Qt::Horizontal, initilisecircle);
    displacement = new QSlider(Qt::Horizontal, initiliseline);
    V01 = new QSlider(Qt::Horizontal, initilisecircle);
    V02 = new QSlider(Qt::Horizontal, initiliseline);
    relatation = new QSlider(Qt::Horizontal, initial);

    //create radio buttons
    Jacobi = new QRadioButton("Jacobi", initial);
    Gauss = new QRadioButton("Gauss Seidel", initial);
    sor = new QRadioButton("Succesive Seidel Relaxation", initial);
    hollow = new QRadioButton("Hollow", initilisecircle);
    filled = new QRadioButton("Filled",initilisecircle);
    horizontal = new QRadioButton("horizontal", initiliseline);
    vertical = new QRadioButton("vertical", initiliseline);

    //create labels
    QLabel *resl = new QLabel(initial);         resl->setText("REsolution");
    QLabel *loopl = new QLabel(initial);        loopl->setText("Number of loops");
    QLabel *xl = new QLabel(initilisecircle);   xl->setText("X position of \ncentre");
    QLabel *yl = new QLabel(initilisecircle);   yl->setText("Y position of centre");
    QLabel *rl = new QLabel(initilisecircle);   rl->setText("radius of circle");
    QLabel *sl = new QLabel(initiliseline);     sl->setText("displacement of line from edge");
    QLabel *v0l = new QLabel(initilisecircle);  v0l->setText("Voltage");
    QLabel *v0l2 = new QLabel(initiliseline);   v0l2->setText("Voltage");
    QLabel *methodl = new QLabel(initial);      methodl->setText("What method \nwould you \nlike to use \nto calculate \nthe numerical \nsolution");


    //set Groupboxes
    initial->move(0,0);             initial->resize(250, 250);
    initilisecircle->move(250, 0);  initilisecircle->resize(250, 250);
    initiliseline->move(250, 250);  initiliseline->resize(250, 250);

    //set labels
    resl->move(5, 60);      resl->setWordWrap(true);
    loopl->move(5, 90);     loopl->setWordWrap(true);
    xl->move(5, 40);        xl->setWordWrap(true);
    yl->move(5, 80);       yl->setWordWrap(true);
    rl->move(5, 120);       rl->setWordWrap(true);
    sl->move(5, 50);        sl->setWordWrap(true);
    v0l->move(5, 150);      v0l->setWordWrap(true);
    v0l2->move(5, 200);     v0l->setWordWrap(true);
    methodl->move(5, 150);  methodl->setWordWrap(true); //methodl->width(200);


    //set Radio Buttons
    Jacobi->move(110, 150); Jacobi->setChecked(true);
    Gauss->move(110, 180);
    sor->move(110, 210);
    hollow->move(110, 180); hollow->setChecked(true);
    filled->move(110, 210);
    horizontal->move(5, 100); horizontal->setChecked(true);
    vertical->move(5, 150);

    //check button checked
    cout << Jacobi->isChecked() << endl;
    cout << Gauss->isChecked() << endl;


    // set size and location of the buttons
    setGeometry(200, 200, 500, 500);    //of the window
    linear->setGeometry(QRect(QPoint(10, 20), QSize(100, 30)));
    circle->move(10,20); circle->resize(110, 30);
    complie->move(400,470);
 //   textin->move(80,80);

    //set postion on sliders
    resolution->move(110, 50);    resolution->setRange(1, 500);     resolution->setValue(500);
    loops->move(110, 100);        loops->setRange(1, 500);          loops->setValue(250);
    xcentre->move(110,40);        xcentre->setRange(1, 500);        xcentre->setValue((resolution->value())/2);
    ycentre->move(110,80);       ycentre->setRange(1, 500);        ycentre->setValue((resolution->value())/2);
    radius->move(110, 120);       radius->setRange(1, 500);         radius->setValue((resolution->value())/2);
    displacement->move(110, 50);  displacement->setRange(1, 500);
    V01->move(110, 150);          V01->setRange(-1, 1);
    V02->move(110, 200);          V02->setRange(-1, 1);
    relatation->move(150, 230);   relatation->setRange(0, 1);


    // Connect button signal to appropriate slot
    connect(linear, SIGNAL (released()), this, SLOT (create_line()));
    connect(circle, SIGNAL(released()), this, SLOT (create_circle()));
    connect(complie, SIGNAL(released()), this, SLOT(run_code()));

}

void MainWindow::create_line()
{
    cout << "create line" << endl;
    int grid = resolution->value();


            int line=0;
            int choice=0;
            int V0=0;

            if (horizontal->isChecked()) {
                choice = 2;
            }
            else if (vertical->isChecked()){
                choice = 1;
            }

            line = displacement->value();

            V0 = V02->value();

            for(int j=0; j<=grid-1; j++) {
                for(int i=0; i<=grid-1; i++) {

                        if( bounds[i][j]==true ) {
                            if (choice == 1) {
                        if ( i == line ) {
                                        values[i][j]=V0;
                                        bounds[i][j]=false;
                                }

                            } else if (choice == 2) {
                                if ( j == line ) {
                                        values[i][j]=V0;
                                        bounds[i][j]=false;
                                }

                            }
                        }
                        cout << bounds[i][j];
                }
                cout << endl;
            }
}

void MainWindow::create_circle()
{
    cout << "create circle" << endl;

    double V0=0, a=0;
    int cx=0,cy=0;
    int fill = 1;

    cx = xcentre->value();
    cy = ycentre->value();
    a = radius->value();
    V0 = V01->value();

    if (hollow->isChecked()) {
        fill = 6;
    }
    else if (filled->isChecked()) {
        fill = 7;
    }



/*	cx=50;
    cy=50;
    a=40;
    V0=1;
    fill=6;
*/
        for(int j=0; j<=grid; j++) {
            for(int i=0; i<=grid; i++) {

                    i2 = i - cx;
                    i2 = i2*i2;

                    j2 = j - cy;
                    j2 = j2*j2;

                    if (bounds[i][j] == true) {

                        if (i2+j2<a*a) {

                    if (fill == 7) {
                        values[i][j]=V0;
                                bounds[i][j]=false;
                    }

                        } else {

                            bounds[i][j]=true;

                            square_dist= i2 + j2;

                            dist = sqrt(square_dist);
                            closeness=abs(dist-a);

                            if( closeness < 0.4 ) {
                                    values[i][j]=V0;
                                    bounds[i][j]=false;
                            }
                        }
                    }
            }
        }
}

void MainWindow::JACOBI()
{

    cout << "Jacobi" << endl;

            int m=0;
            int i=0;
            int j=0;
            int c=0;

            ofstream datafile;
            datafile.open("Users/Honi/updated/lageneric_data.dat",ios::out);

        for(m=0; m<=(loop-1); m++) {
                for (j=1;j<=(grid-2);j++) {
                        for (i=1;i<=(grid-2);i++){
                            if( bounds[i][j]==true ) {

                                    values_new[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]);

                            }
                        }
                }





    ////////////////////////////////////////////////////////////////////////////////////////////////

            for (i=1;i<=(grid-2);i++){
                        j=grid-1;   // upper inner line
                if( bounds[i][j]==true ) {

                            values_new[i][j] = (1.0/4.0) * (values[i][j-1] + values[i+1][j] + values[i-1][j] + values[i][j]);
                        }

                j=0;  // lower inner line
                if( bounds[i][j]==true ) {

                                values_new[i][j] = (1.0/4.0) * (values[i][j+1] + values[i+1][j] + values[i-1][j] + values[i][j]);
                        }
                }

            for (j=1;j<=(grid-2);j++){
                    i=grid-1;   // right inner line
                        if( bounds[i][j]==true ) {

                                values_new[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i-1][j] + values[i][j]);
                        }

                i=0;  // left inner line
                        if( bounds[i][j]==true ) {

                                values_new[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i][j]);
                        }
                }

            // corner points
            c=grid-1;
            if( bounds[0][0]==true ) {
                values_new[0][0]=(1.0/4.0) * (values[1][0] + values[0][1] + values[0][0]  + values[0][0]);
            }

            if( bounds[0][c]==true ) {
                values_new[0][c]=(1.0/4.0) * (values[1][c] + values[0][c-1] + values[0][c]  + values[0][c]);
            }

            if( bounds[c][0]==true ) {
                values_new[c][0]=(1.0/4.0) * (values[c-1][0] + values[c][1]  + values[c][0]  + values[c][0]);
            }

            if( bounds[c][c]==true ) {
                values_new[c][c]=(1.0/4.0) * (values[c-1][c] + values[c][c-1] + values[c][c]  + values[c][c]);
            }

    ////////////////////////////////////////////////////////////////////////////////////////////
            for (j=0;j<=grid-1;j++) {
                        for (i=0;i<=grid-1;i++){
                            if( bounds[i][j]==true ) {
                                values[i][j]=values_new[i][j];
                    }
                        }
                }
        }

        for (i=(grid-1);i>=0;i--){
                for (j=0;j<=(grid-1);j++) {

                        datafile << i << "	" << j << "	" << values[i][j] << "	   " << "\n";
                }

                datafile << "\n";
            }

            datafile.close();
    }

void MainWindow::GAUSS()
{
    cout << "gauss" << endl;


        int m=0;
        int i=0;
        int j=0;
        int c=0;

        ofstream datafile;
        datafile.open("Users/Honi/updated/lageneric_data.dat",ios::out);

        for(m=0; m<=(loop-1); m++) {
                for (j=1; j<=(grid-2); j++) {
                for (i=1; i<=(grid-2); i++) {
                            if( bounds[i][j]==true ) {

                                    values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]);
                    }
                }
            }


    ////////////////////////////////////////////////////////////////////////////////////////////////

            for (i=1;i<=(grid-2);i++){
                        j=grid-1;   // upper inner line
                if( bounds[i][j]==true ) {

                            values[i][j] = (1.0/4.0) * (values[i][j-1] + values[i+1][j] + values[i-1][j] + values[i][j]);
                        }

                j=0;  // lower inner line
                if( bounds[i][j]==true ) {

                                values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i+1][j] + values[i-1][j] + values[i][j]);
                        }
                }

            for (j=1;j<=(grid-2);j++){
                    i=grid-1;   // right inner line
                        if( bounds[i][j]==true ) {

                                values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i-1][j] + values[i][j]);
                        }

                i=0;  // left inner line
                        if( bounds[i][j]==true ) {

                                values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i][j]);
                        }
                }

            // corner points
            c=grid-1;
            if( bounds[0][0]==true ) {
                values[0][0]=(1.0/4.0) * (values[1][0] + values[0][1] + values[0][0]  + values[0][0]);
            }

            if( bounds[0][c]==true ) {
                values[0][c]=(1.0/4.0) * (values[1][c] + values[0][c-1] + values[0][c]  + values[0][c]);
            }

            if( bounds[c][0]==true ) {
                values[c][0]=(1.0/4.0) * (values[c-1][0] + values[c][1]  + values[c][0]  + values[c][0]);
            }

            if( bounds[c][c]==true ) {
                values[c][c]=(1.0/4.0) * (values[c-1][c] + values[c][c-1] + values[c][c]  + values[c][c]);
            }

    ////////////////////////////////////////////////////////////////////////////////////////////

    }

            for (i=(grid-1); i>=0; i--) {
                for (j=0; j<=(grid-1); j++) {

                        datafile << i << "	" << j << "	" << values[i][j] << "	   " << "\n";
                }

                datafile << "\n";
            }

            datafile.close();
    }

void MainWindow::SOR()
{
    cout << "sor" << endl;


        int m=0;
        int i=0;
        int j=0;

        ofstream datafile;
        datafile.open("Users/Honi/updated/lageneric_data.dat",ios::out);

        for(m=0; m<=(loop-1); m++) {
                for (j=1; j<=(grid-1); j++) {
                for (i=1; i<=(grid-1); i++) {
                            if( bounds[i][j]==true ) {

                                    values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]));
                    }
                }
            }
        }

            for (i=(grid-1); i>=0; i--) {
                for (j=0; j<=(grid-1); j++) {

                        datafile << i << "	" << j << "	" << values[i][j] << "	   " << "\n";
                }

                datafile << "\n";
            }

            datafile.close();
}

void MainWindow::run_code()
{
    cout << "run" << endl;


    int op;

        grid = resolution->value();

        for(int i=0; i<=grid-1; i++) {
            for(int j=0; j<=grid-1; j++) {

                bounds[i][j] = true;
            }
        }


            loop = loops->value();

cout << "past grid creation" << endl;
// would not finish compilation after this point/ does not enter loop
            if (Jacobi->isChecked() == 1){
                op = 1;
                cout << "jackie!"<< endl;
                JACOBI();
                cout << "jackie!"<< endl;
            }
            else if (Gauss->isChecked() == 1){
                op = 2;
                cout << "gauss" << endl;
                GAUSS();
                cout << "gauss" << endl;
            }
            else if (sor->isChecked() == 1){
                op = 3;
                cout << "soar!" << endl;
                w = relatation->value();
                SOR();
                cout << "soar!" << endl;
            }
            else {cout << "there is a problem with your code :(" << endl;}


            cout << "All done! please run 'laplotter.sh'" << endl;

}
