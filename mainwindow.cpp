#include "mainwindow.h"
//#include "/Users/Honi/Documents/Group2/GRoup2/boundaries.hpp"
#include <QCoreApplication>
#include <iostream>
#include "window2.h"
#include "methods.hpp"
#include "boundaries.hpp"
#include "lageneric.hpp"
#include <QGroupBox>
using namespace std;

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
    QPushButton *output = new QPushButton("Output", this); output->move(10, 470);

    textin = new QLabel(this);

    //create sliders
//    size = new QSlider(Qt::Horizontal, this );
    resolution = new QSlider(Qt::Horizontal, initial);
    loops = new QSlider(Qt::Horizontal, initial);
    xcentre = new QSlider(Qt::Horizontal, initilisecircle);
    ycentre = new QSlider(Qt::Horizontal, initilisecircle);
    radius = new QSlider(Qt::Horizontal, initilisecircle);
    displacement = new QSlider(Qt::Horizontal, initiliseline);
    V01 = new QSlider(Qt::Horizontal, initilisecircle);
    V02 = new QSlider(Qt::Horizontal, initiliseline);

    //create radio buttons
    Jacobi = new QRadioButton("JAcobi", initial);
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
    QLabel *methodl = new QLabel(initial);      methodl->setText("What method \nwould you \nlike to use \nto calculate the \nnumerical solution");


    //set Groupboxes
    initial->move(0,0);             initial->resize(250, 250);
    initilisecircle->move(250, 0);  initilisecircle->resize(250, 250);
    initiliseline->move(250, 250);  initiliseline->resize(250, 250);

    //set labels
    resl->move(5, 60);      resl->setWordWrap(true);
    loopl->move(5, 90);     loopl->setWordWrap(true);
    xl->move(5, 50);        xl->setWordWrap(true);
    yl->move(5, 100);       yl->setWordWrap(true);
    rl->move(5, 150);       rl->setWordWrap(true);
    sl->move(5, 50);        sl->setWordWrap(true);
    v0l->move(5, 200);      v0l->setWordWrap(true);
    v0l2->move(5, 200);     v0l->setWordWrap(true);
    methodl->move(5, 150);  methodl->setWordWrap(true); //methodl->width(200);

    cout << "x" << xl->x();
    cout << "y" << xl->y();

    //set Radio Buttons
    Jacobi->move(110, 150); Jacobi->setChecked(true);
    horizontal->move(5, 100); horizontal->setChecked(true);
    vertical->move(5, 150);


    // set size and location of the buttons
    setGeometry(200, 200, 500, 500);    //of the window
    linear->setGeometry(QRect(QPoint(10, 20), QSize(100, 30)));
    circle->move(10,220); circle->resize(100, 30);
    complie->move(400,470);
 //   textin->move(80,80);

    //set postion on sliders
//    size->move(100,40);
    resolution->move(110, 50);    resolution->setRange(1, 500);     resolution->setValue(500);
    loops->move(110, 100);        loops->setRange(1, 500);          loops->setValue(250);
    xcentre->move(110,50);        xcentre->setRange(1, 500);        xcentre->setValue((resolution->value())/2);
    ycentre->move(110,100);       ycentre->setRange(1, 500);        ycentre->setValue((resolution->value())/2);
    radius->move(110, 150);       radius->setRange(1, 500);         radius->setValue((resolution->value())/2);
    displacement->move(110, 50);  displacement->setRange(1, 500);
    V01->move(110, 200);          V01->setRange(-1, 1);
    V02->move(110, 200);          V02->setRange(-1, 1);

    //output sizes of the buttons
    cout << "PBwidth" << complie->width() << endl;
    cout << "PBhieght" << complie->height() << endl;

    //lables
//    QLabel *label = new QLabel(this);
//    label->setText("first line\nsecond line");
//    label->setAlignment(Qt::AlignTop);



//    size->setRange(1, 500);
//    label->setText(size->value());

    // Connect button signal to appropriate slot
    connect(linear, SIGNAL (released()), this, SLOT (create_line()));
    connect(circle, SIGNAL(released()), this, SLOT (create_circle()));
    connect(complie, SIGNAL(released()), this, SLOT(run_code()));
//    connect(Jacobi, SIGNAL(checked()), this, SLOT(choosemethod()));
//    connect(horizontal, SIGNAL(checked()), this, SLOT(aligment()));
//    connect(size, SIGNAL(valueChanged(int)), this, SLOT(changedsize())); //does not work

    //create button that produces second window--- does not work as needed
//    win2 = new QPushButton("2nd Window", this);
//    win2->move(60, 60);
//    connect(win2, SIGNAL(released()), this, SLOT(changewin()));


}

//void MainWindow::choosemethod() {
    //op
//}



void MainWindow::changewin() {
    window2 = new Window2(this);
    //hide();
    window2->show();
}

void MainWindow::create_line()
{
    //run the line function
    cout << "You have entered the line" << endl;

    int line= displacement->value();
    int choice=1;
    int V0=V01->value();

    if (horizontal->isChecked()){
        choice = 1;
    }
    else {
        choice = 2;
    }


    for(int i=0; i<=grid; i++) {
        for(int j=0; j<=grid; j++) {

            if( bounds[j][i]==true ) {
            if (choice == 1) {



                if ( i == line ) {
                        values[j][i]=V0;
                        bounds[j][i]=false;
                }

            } else if (choice == 2) {

                if ( j == line ) {
                    values[j][i]=V0;
                    bounds[j][i]=false;
                }


            }

            }

        }

    }
}

void MainWindow::create_circle() {
    //create circle

    cout << "you have entered the circle" << endl;
    int cx = xcentre->value();
    int cy = ycentre->value();
    int a = radius->value();
    int V0 = V02->value();


    for(int i=0; i<=grid; i++) {
        for(int j=0; j<=grid; j++) {


            i2 = i - cx;
            i2 = i2*i2;

            j2 = j - cy;
            j2 = j2*j2;

            if (bounds[j][i] == true) {

            if (i2+j2<a*a) {

        values[j][i]=V0;
                bounds[j][i]=false;

            } else {

                bounds[j][i]=true;

                square_dist= i2 + j2;

                dist = sqrt(square_dist);
                closeness=abs(dist-a);

                if( closeness < 0.4 ) {
                    values[j][i]=V0;
                    bounds[j][i]=false;

                }

            }

            }
        }
    }
}

void MainWindow::changedsize(){
//    std::cout << size->value() << std::endl;
//    label->setText( QString::number( size->value() ) );
}

void MainWindow::run_code() {
    //the running of the code
    //stuff from lageneric.cpp
        //place into mainwindow.cpp?

//        int done;

        cout << "Enter grid size (resolution)" << endl;

//        cin >> grid;
        int grid;
        grid = resolution->value();


        for(int i=0; i<=grid; i++) {
            for(int j=0; j<=grid; j++) {

                bounds[j][i] = true;
                cout << i << " " << j << endl;

            }
        }

        cout << "Enter # of loops" << endl;
        int loop = loops->value();

//        do {

  //          done = add_shapes();

    //    } while (done == 0);

        cout << "Specify your numerical method" << endl;
        cout << "1: Jacobi" << endl;
        //cin >> op;
        int op = 1;

        if (Jacobi->isChecked()) {
            op = 1;
            cout << "is checked" << endl;
        }


        switch(op) {
            case 1:
                cout << "JAbobiii" << endl;
//                jacobi();

                int j=0;
                int c=0;



                ofstream datafile;
                datafile.open("Users/Honi/Button/lageneric_data.dat",ios::out);
                if (datafile.is_open()) {
                    cout << "Apparently it exists... somewhere" << endl;
//***********DATA FILE DOES NOT OPEN, NEED TO FIX THIS!!!!!!!!**********....fixed?
                }

//problem now lies here, with the value of the value
                for(long int k=0; k<=loop; k++) {


                    for (c=1;c<=(grid-1);c++) {
                        cout << endl;

                        for (j=1;j<=(grid-1);j++){
                            if( bounds[j][c]==true ) {

                                values[j][c] = (1.0/4.0) * (values[j][c+1] + values[j][c-1] + values[j+1][c] + values[j-1][c]);
                                //cout << values[j][c] << "   ";
                            }
                        }

                    }


                }


                for (j=(grid-1);j>=0;j--){

                    for (c=0;c<=(grid-1);c++) {
//                        cout << "in grid" << endl;

                        datafile << c << "	" << j << "	" << values[j][c] << "	   " << "\n";
                        cout << c << "	" << j << "	" << values[j][c] << "	   " << "\n";
                    }
                    datafile << "\n";
                }

                datafile.close();
                break;

        }

        cout << "All done! please run 'laplotter.sh'" << endl;


     //end

}

void MainWindow::debug() {
    //output the data collected
    //for
}

