#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QCoreApplication>
#include <QtGui>
#include <QtCore>
#include <QMainWindow>
#include <QApplication>

using namespace std;


void MainWindow::GAUSS()
{
    cout << "gauss" << endl;


        int m=0;
        int i=0;
        int j=0;
        int c=0;

        ofstream datafile;
        datafile.open("lageneric_data.dat",ios::out);
        cout << datafile.is_open() << endl;

        for(m=0; m<=(loop-1); m++) {

                //ui->gavsBar->setValue(m);
                QCoreApplication::processEvents();

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

            cout << "done m8" << endl;

            QProcess::startDetached("./laplotter.sh");
            QCoreApplication::processEvents();

    }
