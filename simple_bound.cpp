#include "mainwindow.h"
#include "ui_mainwindow.h"
using namespace std;

void MainWindow::create_line()
{
    cout << "create line" << endl;
    cout << ui->size->text().toInt();
    int grid = ui->size->text().toInt();


            int line=0;
            int choice=0;
            int V0;

            if (ui->radioX->isChecked()) {
                choice = 2;
            }
            else if (ui->radioY->isChecked()){
                choice = 1;
            }

            line = ui->simple_axis->text().toInt();

            V0 = ui->simple_val->text().toInt();
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
            cout << bounds[1][1] << endl;
            cout << values[1][1] << endl;
}
