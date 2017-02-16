#include "mainwindow.h"
using namespace std;

void MainWindow::create_circle()
{


    double V0;
    V0 = radialVal;
    double a;
    a=radialR;
    int cx;
    cx = cX;
    int cy;
    cy = cY;

    int fill;

        if (HorF == true) {
            fill = 7;
        }


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

                            if( closeness < 0.6 ) {
                                    values[i][j]=V0;
                                    bounds[i][j]=false;
                            }
                        }
                    }
            }
        }
}
