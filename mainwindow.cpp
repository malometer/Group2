#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;


int grid,loop;
float i2, j2, w;
double values[10000][10000], values_new[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //inserting from twoparter
    setWindowTitle("Electrostatic simulation");

    //group boxes
    QGroupBox *initial = new QGroupBox("", this);        //grid values
    QGroupBox *initilisecircle = new QGroupBox("", this);     //circle
    QGroupBox *initiliseline = new QGroupBox("", this);        //lines
    QGroupBox *tasktwo = new QGroupBox("", this);             //task 2

    // Create the button, make "this" the parent
    linear = new QPushButton("Create Line", initiliseline);
    circle = new QPushButton("Create Circle", initilisecircle);
    complie = new QPushButton("RUN", this);
    reset = new QPushButton("Reset", this);
    task22 = new QPushButton("Task 2", tasktwo);
    showline = new QPushButton("Create a line", this);
    showcircle = new QPushButton("Create circles", this);
    showtask2 = new QPushButton("Create Task 2", this);

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

        //task two
    a2 = new QSlider(Qt::Horizontal,tasktwo);
    w2 = new QSlider(Qt::Horizontal,tasktwo);
    h2 = new QSlider(Qt::Horizontal,tasktwo);
    d2 = new QSlider(Qt::Horizontal,tasktwo);
    V2 = new QSlider(Qt::Horizontal,tasktwo);

    //create radio buttons
    Jacobi = new QRadioButton("Jacobi", initial);
    Gauss = new QRadioButton("Gauss Seidel", initial);
    sor = new QRadioButton("Succesive Seidel Relaxation", initial);
    hollow = new QRadioButton("Hollow", initilisecircle);
    filled = new QRadioButton("Filled",initilisecircle);
    horizontal = new QRadioButton("horizontal", initiliseline);
    vertical = new QRadioButton("vertical", initiliseline);


    //create labels
    QLabel *resl = new QLabel(initial);             resl->setText("Grid size");
    QLabel *loopl = new QLabel(initial);            loopl->setText("Number of loops");
    QLabel *xl = new QLabel(initilisecircle);       xl->setText("X position of \ncentre");
    QLabel *yl = new QLabel(initilisecircle);       yl->setText("Y position of centre");
    QLabel *rl = new QLabel(initilisecircle);       rl->setText("radius of circle");
    QLabel *sl = new QLabel(initiliseline);         sl->setText("displacement of line from edge");
    QLabel *v0l = new QLabel(initilisecircle);      v0l->setText("Voltage");
    QLabel *v0l2 = new QLabel(initiliseline);       v0l2->setText("Voltage");
    QLabel *methodl = new QLabel(initial);          methodl->setText("What method \nwould you \nlike to use \nto calculate \nthe numerical \nsolution");
    QLabel *wl = new QLabel(initial);               wl->setText("relaxation value");
    QLabel *text = new QLabel(initial);             text->setText("");

    QLabel *vmin1 = new QLabel(initilisecircle);    vmin1->setText("-1");
    QLabel *vmax1 = new QLabel(initilisecircle);    vmax1->setText("+1");
    QLabel *vmin2 = new QLabel(initiliseline);      vmin2->setText("-1");
    QLabel *vmax2 = new QLabel(initiliseline);      vmax2->setText("+1");
    QLabel *resmax = new QLabel(initial);           resmax->setText("500");
    QLabel *resmin = new QLabel(initial);           resmin->setText("1");
    QLabel *lmax = new QLabel(initial);             lmax->setText("10000");
    QLabel *lmin = new QLabel(initial);             lmin->setText("500");
    QLabel *xmax = new QLabel(initilisecircle);     xmax->setText("499");
    QLabel *xmin = new QLabel(initilisecircle);     xmin->setText("1");
    QLabel *ymax = new QLabel(initilisecircle);     ymax->setText("499");
    QLabel *ymin = new QLabel(initilisecircle);     ymin->setText("1");
    QLabel *rmax = new QLabel(initilisecircle);     rmax->setText("250");
    QLabel *rmin = new QLabel(initilisecircle);     rmin->setText("1");
    QLabel *smax = new QLabel(initiliseline);       smax->setText("499");
    QLabel *smin = new QLabel(initiliseline);       smin->setText("1");
    QLabel *relmax = new QLabel(initial);           relmax->setText("1");
    QLabel *relmin = new QLabel(initial);           relmin->setText("0");

    //box
    bx = new QSlider(Qt::Horizontal, tasktwo);
    by = new QSlider(Qt::Horizontal, tasktwo);
    blength = new QSlider(Qt::Horizontal, tasktwo);
    bwidth = new QSlider(Qt::Horizontal, tasktwo);
    V3 = new QSlider(Qt::Horizontal, tasktwo);
    box = new QPushButton("create box", this);
    connect(box, SIGNAL(released()), this, SLOT(create_box()));
    boxfill = new QRadioButton("filled box", tasktwo);
    boxempty = new QRadioButton("empty box", tasktwo);

    bx->move(200, 50);
    by->move(200, 100);
    blength->move(200, 150);
    bwidth->move(200, 200);
    V3->move(200, 250);
    box->move(200, 300);
    boxfill->move(210, 340);
    boxempty->move(210, 380);

    QLabel *bxl = new QLabel(tasktwo);      bxl->setText("xcorner");        bxl->move(150, 50);
    QLabel *byl = new QLabel(tasktwo);      byl->setText("ycorner");        byl->move(150, 100);
    QLabel *bll = new QLabel(tasktwo);      bll->setText("length");         bll->move(150, 150);
    QLabel *bwl = new QLabel(tasktwo);      bwl->setText("width");          bwl->move(150, 200);
    QLabel *bvl = new QLabel(tasktwo);      bvl->setText("voltage");        bvl->move(150, 250);
    QLabel *bfl = new QLabel(tasktwo);      bfl->setText("xcorner");        bfl->move(150, 300);

    //set Groupboxes
    initial->move(0,0);             initial->resize(350, 400);
    initilisecircle->move(370, 0);  initilisecircle->resize(300, 400);      initilisecircle->hide();
    initiliseline->move(370, 0);    initiliseline->resize(300, 400);        initiliseline->hide();
    tasktwo->move(370, 0);          tasktwo->resize(300, 400);              tasktwo->hide();


    //set labels
    resl->move(5, 50);      resl->setWordWrap(true);
    loopl->move(5, 100);     loopl->setWordWrap(true);
    xl->move(5, 40);        xl->setWordWrap(true);
    yl->move(5, 80);       yl->setWordWrap(true);
    rl->move(5, 120);       rl->setWordWrap(true);
    sl->move(5, 50);        sl->setWordWrap(true);
    v0l->move(5, 150);      v0l->setWordWrap(true);
    v0l2->move(5, 200);     v0l->setWordWrap(true);
    methodl->move(5, 150);  methodl->setWordWrap(true);
    wl->move(140, 240);     wl->setWordWrap(true);
    vmin1->move(110, 165);
    vmax1->move(180, 165);
    vmin2->move(110, 215);
    vmax2->move(180, 215);
    resmax->move(180, 70);
    resmin->move(110, 70);
    lmax->move(180, 120);
    lmin->move(110, 120);
    xmax->move(180, 60);
    xmin->move(110, 60);
    ymax->move(180, 100);
    ymin->move(110, 100);
    smax->move(180, 70);
    smin->move(110, 70);
    rmax->move(180, 140);
    rmin->move(110,140);
    relmax->move(240,270);
    relmin->move(170, 270);


    //set Radio Buttons
    Jacobi->move(110, 150); Jacobi->setChecked(true);
    Gauss->move(110, 180);
    sor->move(110, 210);
    hollow->move(110, 180); hollow->setChecked(true);
    filled->move(110, 210);
    horizontal->move(5, 100); horizontal->setChecked(true);
    vertical->move(5, 150);


    // set size and location of the buttons
    //setGeometry(200, 200, 500, 500);    //of the window
    linear->setGeometry(QRect(QPoint(5, 20), QSize(100, 30)));
    circle->move(5,20); circle->resize(110, 30);
    complie->move(600,420);
    task22->move(150, 150);
    showline->move(220, 420);
    showcircle->move(110, 420);
    showtask2->move(330, 420);
    reset->move(5, 420);


    //set postion on sliders
    resolution->move(110, 50);    resolution->setRange(1, 500);         resolution->setValue(499);
    loops->move(110, 100);        loops->setRange(500, 10000);          loops->setValue(1000);
    xcentre->move(110,40);        xcentre->setRange(1, 499);            xcentre->setValue((resolution->value())/2);
    ycentre->move(110,80);        ycentre->setRange(1, 499);            ycentre->setValue((resolution->value())/2);
    radius->move(110, 120);       radius->setRange(1, 250);             radius->setValue((resolution->value())/2);
    displacement->move(110, 50);  displacement->setRange(1, 499);
    V01->move(110, 150);          V01->setRange(-1, 1);
    V02->move(110, 200);          V02->setRange(-1, 1);
    relatation->move(170, 250);   relatation->setRange(0, 1);           relatation->hide();
        //task two
    a2->move(110, 5);
    w2->move(110, 40);
    h2->move(110, 70);
    d2->move(110, 100);
    V2->move(110, 130);

    cout << "AAAAAAAAHHHHHHHHH" << endl;

    //create image
    showimage = new QPushButton("image", this); showimage->move(500, 420);  showimage->hide();
    plot2 = new QLabel(this); plot2->hide();

    // Connect button signal to appropriate slot
    connect(linear, SIGNAL (released()), this, SLOT (create_line()));
    connect(circle, SIGNAL(released()), this, SLOT (create_circle()));
    connect(complie, SIGNAL(released()), this, SLOT(run_code()));
    connect(task22, SIGNAL(released()), this, SLOT(task2()));
    connect(reset, SIGNAL(released()), this, SLOT(wipe()));

    connect(showimage, SIGNAL(released()), this, SLOT(image()));
        connect(sor, SIGNAL(clicked(bool)), relatation, SLOT(show()));

    //Hide/show sections
    connect(showcircle, SIGNAL(released()), initilisecircle, SLOT(show()));
    connect(showcircle, SIGNAL(released()), initiliseline, SLOT(hide()));
    connect(showcircle, SIGNAL(released()), tasktwo, SLOT(hide()));

    connect(showline, SIGNAL(released()), initiliseline, SLOT(show()));
    connect(showline, SIGNAL(released()), initilisecircle, SLOT(hide()));
    connect(showline, SIGNAL(released()), tasktwo, SLOT(hide()));

    connect(showtask2, SIGNAL(released()), tasktwo, SLOT(show()));
    connect(showtask2, SIGNAL(released()), initilisecircle, SLOT(hide()));
    connect(showtask2, SIGNAL(released()), initiliseline, SLOT(hide()));

    connect(showimage, SIGNAL(released()), initiliseline, SLOT(hide()));
    connect(showimage, SIGNAL(released()), initilisecircle, SLOT(hide()));
    connect(showimage, SIGNAL(released()), tasktwo, SLOT(hide()));
    //end

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::image()
{
    //call forth the gnuplot here... please?
    /*
    gnuplot << "set terminal postscript colour \n"
               "set term jpeg\n"
               "set output 'plot1.jpg'\m"
               "";
    */

    //place the graph into the GUI

    //QPixmap pix("/Users/Honi/THIS-FILE-HERE-WORKS/plot1.jpg"); //works
    //QPixmap pix("../THIS-FILE-HERE-WORKS/plot1.jpg"); //works
    QPixmap pix("plot1.jpg");   //works when linked (which it is)
    //pix.setDevicePixelRatio(2);
    plot2->show();
    plot2->setPixmap(pix);
    plot2->setGeometry(-50,15,600,400);

    cout << "inputed image" << endl;
    showimage->hide();
    linear->hide();
    circle->hide();
    complie->hide();
    task22->hide();


}

void MainWindow::run_code() {

cout << "run" << endl;


int op = 0;

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
        showimage->show();

}

void MainWindow::wipe() {

    //undo/reset
    plot2->hide();
    task22->show();
    linear->show();
    circle->show();
    complie->show();

    //reset global varibles here, loop through and set everything to zero?
    /*
    values[10000][10000] = {};      //everything is null?
    values_new[10000][10000] = {};  //everything is null?
    bounds[10000][10000]  = {};     //everythign is null?
    */
        //is that good enough?
}

void MainWindow::create_box()
{
    //set position, length, width
    int xcorner = bx->value();
    int ycorner = by->value();
    int length = blength->value();
    int width = bwidth->value();
    int filled = 0;
    int V0 = V3->value();
    grid = resolution->value();
    cout << "you are building the box "<< endl;

    for(int j=0; j<=grid-1; j++) {
        for(int i=0; i<=grid-1; i++) {

                //if( bounds[i][j]==true ) {
                    //cout << "I'm in, standby" << endl;
                    if (filled == 1) {
                if ( i > xcorner && i < xcorner + length ) {
                    if (j > ycorner && j < ycorner + width) {
                                cout << "i: " << i << ",  j: " << j << endl;
                                values[i][j]=V0;
                                bounds[i][j]=false;
                        }

                }} else if (filled == 0) {
                        //cout << "here we go" << endl;
                        if ( i == xcorner || i == xcorner + length ) {
                                //cout << "target in my sights" << endl;
                            if (j > ycorner && j < ycorner + width){
                                cout << "i: " << i << ",  j: " << j << endl;
                                values[i][j]=V0;
                                bounds[i][j]=false;
                        }
                    }
                        if (j == ycorner || j == ycorner + width){
                            //cout << "do you read?" << endl;
                            if (i > xcorner && i < xcorner + length){
                                cout << "i: " << i << ",  j: " << j << endl;
                                values[i][j]=V0;
                                bounds[i][j]=false;
                            }
                        }
                }
        }
    }
       // }
    }




