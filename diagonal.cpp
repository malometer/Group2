#include "mainwindow.h"
using namespace std;

void MainWindow::create_diagonal1(){
    //interface varibles
    double V0;
    float m, c, y;
    V0 = digval;
    m = digm;
    c = digc;
    grid = grid;

     cout << "marker 1" << endl;

    //by equation
    for (int j=0; j < grid-1; j++){
        for (int i=0; i < grid-1; i++){

            y = i*m+c;

            if (j == y){

                bounds[i][j] = false;
                values[i][j] = V0;
            }
            else if (abs(y-j) < 1){
                bounds[i][j] = false;
                values[i][j] = V0;

            }
            else if (i == ((j-c)/m)){
                bounds[i][j] = false;
                values[i][j] = V0;
            }
        }
    }

}

void MainWindow::create_diagonal2(){



    float x1, x2, y1, y2, a, b, m, V0, y;
    float lowx, lowy, highx, highy;

    x1 = dix_1;
    x2 = dix_2;
    y1 = diy_1;
    y2 = diy_2;

    V0 = digval2;

    m = (y2-y1)/(x2-x1);
    a = x1;
    b = y1;


    lowx = x1;
    lowy = y1;
    highx = x2;
    highy = y2;

    if (x2 < lowx){
        lowx = x2;
    }
    if (y2 < lowy){
        lowy = y2;
    }
    if (x1 > highx){
        highx = x1;
    }
    if (y1 > highy){
        highy = y1;
    }


    for (int j = 0; j < grid-1; j++){
        for (int i = 0; i < grid-1; i++){
            if ((j >= lowy) && (j <= highy)){
                if ((i >= lowx) && (i <= highx)){
                    y = m*(i-a)+b;

                 if (j == y){
                     bounds[i][j] = false;
                     values[i][j] = V0;


                  }
                 else if (abs(abs(y)- abs(j)) < 1) {
                     bounds[i][j] = false;
                     values[i][j] = V0;

            }
                 else if (x1 == x2) {
                     if (i == x1){
                         bounds[i][j] = false;
                         values[i][j] = V0;
                     }
                 }

        }
    }
        }
    }

}

void MainWindow::create_diagonal_quad(){
    //interface varibles
    double V0;
    float y,a,b,c;
    V0 = quad_v0;
    a = quad_a;
    b = quad_b;
    c = quad_c;
    grid = grid;

    int lower = -((grid+1)/2);
    int upper = (grid-1)/2;
    int scale = grid/2;


    //by equation
    for (int j=lower; j < upper; j++){
        for (int i=lower; i < upper; i++){

            y = (a*i*i) + (b*i) + c;

            if (j == y){

                bounds[i+scale][j+scale] = false;
                values[i+scale][j+scale] = V0;
            }
            else if (abs(y-j) < 1){
                bounds[i+scale][j+scale] = false;
                values[i+scale][j+scale] = V0;

            }
        }
    }

}
