#include "mainwindow.h"
using namespace std;


void MainWindow::SOR()
{
    cout << "sor" << endl;
    cout << loop << "   " << grid << endl;


        int m=0;
        int i=0;
        int j=0;

        ofstream datafile;
        datafile.open("../THIS-FILE-HERE-WORKS/lageneric_data.dat",ios::out);

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
            cout << bounds[1][1] << endl;
            cout << values[1][1] << endl;
}
