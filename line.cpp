#include "mainwindow.h"
using namespace std;

void MainWindow::create_line()
{

            int line =  simpleDist;

            int V0 = simpleVal;

            int choice;

            cout << "grid: " << grid << endl;

            if (XorY == true) {
                choice = 1;
            } else {
                choice = 2;
            }



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
                        //cout << bounds[i][j] << " " << values[i][j] << " ";
                }
                //cout << endl;
            }
}
