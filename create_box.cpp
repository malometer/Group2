#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

void MainWindow::create_box()
{
    //set position, length, width
    int xcorner = cX;      //need to set these to input on the GUI
    int ycorner = cY;
    int length = lengthVal;
    int width = widthVal;
    int V0 = radialVal;
    //grid = ui->size->text().toInt();


    int fill;
    if (HorF == true) {
        fill = 7;
    } else {
        fill = 6;
    }


    for(int j=0; j<=grid-1; j++) {
        for(int i=0; i<=grid-1; i++) {

               // if( bounds[i][j]==true ) {
                    if (fill == 7) {
                if ( i > xcorner && i < xcorner + length ) {
                    if (j > ycorner && j < ycorner + width) {
                                cout << "i: " << i << ",  j: " << j << endl;
                                values[i][j]=V0;
                                bounds[i][j]=false;
                        }

                }} else if (fill == 6) {
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
