#include "mainwindow.h"
using namespace std;

void MainWindow::create_line()
{
    cout << "create line" << endl;
    cout << resolution->value();
    cout << "did it crash?";
    int grid = resolution->value();     //crashes here


            int line=0;
            int choice=0;
            int V0=V02->value();

            if (horizontal->isChecked()) {
                choice = 2;
            }
            else if (vertical->isChecked()){
                choice = 1;
            }

            line = displacement->value();

            V0 = V02->value();
            cout << "voltage = " << V0 << endl;

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
