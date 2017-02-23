#include "mainwindow.h"
#include <QProcess>
using namespace std;


void MainWindow::SOR()
{
    cout << "sor" << endl;


        int m=0;
        int i=0;
        int j=0;
        float w = 1.6;
        double p =0.99999;
        int c;

        ofstream datafile;
        datafile.open("/Users/Honi/Documents/SelfEnclosedGUI/HERE/new/lageneric_data.dat",ios::out);

        for(m=0; m<=(loop-1); m++) {
            QCoreApplication::processEvents();
                for (j=1; j<=(grid-2); j++) {
                for (i=1; i<=(grid-2); i++) {
                            if( bounds[i][j]==true ) {

                                    values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]));
                    }
                }
            }

                ////////////////////////////////////////////////////////////////////////////////////////////////

                        for (i=1;i<=(grid-2);i++){
                                    j=grid-1;

                            if( bounds[i][j]==true ) {

                                        values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j-1] + values[i+1][j] + values[i-1][j] + (p*values[i][j])));
                                    }

                            j=0;

                            if( bounds[i][j]==true ) {

                                            values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j+1] + values[i+1][j] + values[i-1][j] + (p*values[i][j])));
                                    }
                            }

                        for (j=1;j<=(grid-2);j++){
                                i=grid-1;

                                    if( bounds[i][j]==true ) {

                                            values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j+1] + values[i][j-1] + values[i-1][j] + (p*values[i][j])));
                                    }

                            i=0;

                                    if( bounds[i][j]==true ) {

                                            values[i][j] = ((1-w)*values[i][j]) + ((w/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + (p*values[i][j])));
                                    }
                            }

                        // corner points
                        c=grid-1;






                        if( bounds[0][0]==true ) {
                            values[0][0]=((1-w)*values[i][j]) + ((w/4.0) * (values[1][0] + values[0][1] + (p*values[0][0])  + (p*values[0][0])));
                        }

                        if( bounds[0][c]==true ) {
                            values[0][c]=((1-w)*values[i][j]) + ((w/4.0) * (values[1][c] + values[0][c-1] + (p*values[0][c])  + (p*values[0][c])));
                        }

                        if( bounds[c][0]==true ) {
                            values[c][0]=((1-w)*values[i][j]) + ((w/4.0) * (values[c-1][0] + values[c][1]  + (p*values[c][0])  + (p*values[c][0])));
                        }

                        if( bounds[c][c]==true ) {
                            values[c][c]=((1-w)*values[i][j]) + ((w/4.0) * (values[c-1][c] + values[c][c-1] + (p*values[c][c])  + (p*values[c][c])));
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


       QProcess::startDetached("/Users/Honi/Documents/SelfEnclosedGUI/HERE/new/laplotter.sh");
}
