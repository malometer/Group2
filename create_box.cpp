#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

void MainWindow::create_box()
{
    //set position, length, width
    int xcorner = ui->bx->text().toInt();      //need to set these to input on the GUI
    int ycorner = ui->by->text().toInt();
    int length = ui->blength->text().toInt();
    int width = ui->bwidth->text().toInt();
    int filled;
    int V0 = ui->V3->text().toInt();
    grid = ui->size->text().toInt();
    cout << "you are building the box "<< endl;

    if(ui->radioFilled_5->isChecked()){
        filled = 1;
    } else if(ui->radioHollow_5->isChecked()){
        filled = 0;
    }

    for(int j=0; j<=grid-1; j++) {
        for(int i=0; i<=grid-1; i++) {

                //if( bounds[i][j]==true ) {        //do I need this here?
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
}
