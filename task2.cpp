#include "mainwindow.h"
using namespace std;


void MainWindow::task2()
{
    //the second task here

    //input values
    float V, d, a, w, h;// N;

    V = V2->value();
    d = d2->value();
    a = a2->value();
    w = w2->value();
    h = h2->value();

    cout << "attempting task two" << endl;

    for (int i = 0; i < (grid-1); i++) {
        for (int j = 0; j < (grid-1); j++) {
            if (j < h) {
                //placement within the hieght of the box
                if ((i > a && i<a+w) || (i > 2*a+w && i < 2*(a+w)) || (i > 3*a+2*w && i < 3*(a+w))) {
                    //within the first 3 boxes
                    values[i][j] = 0;
                    bounds[i][j] = false;
                }
            }
            if (j == d) {
                //value at the V+ line
                values[i][j] = V;
                bounds[i][j] = false;
            }
        }
    }

}



