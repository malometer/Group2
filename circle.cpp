#include "mainwindow.h"
using namespace std;

void MainWindow::create_circle()
{
    cout << "create circle" << endl;

    double V0=0, a=0;
    int cx=0,cy=0;
    int fill = 1;

    cx = xcentre->value();
    cy = ycentre->value();
    a = radius->value();
    V0 = V01->value();

    if (hollow->isChecked() ==1) {
        fill = 6;
    }
    else if (filled->isChecked() ==1) {
        fill = 7;
    }



/*	cx=50;
    cy=50;
    a=40;
    V0=1;
    fill=6;
*/
        for(int j=0; j<=grid; j++) {
            for(int i=0; i<=grid; i++) {

                    i2 = i - cx;
                    i2 = i2*i2;

                    j2 = j - cy;
                    j2 = j2*j2;

                    if (bounds[i][j] == true) {

                        if (i2+j2<a*a) {

                    if (fill == 7) {
                        values[i][j]=V0;
                                bounds[i][j]=false;
                    }

                        } else {

                            bounds[i][j]=true;

                            square_dist= i2 + j2;

                            dist = sqrt(square_dist);
                            closeness=abs(dist-a);

                            if( closeness < 0.4 ) {
                                    values[i][j]=V0;
                                    bounds[i][j]=false;
                            }
                        }
                    }
            }
        }
}
