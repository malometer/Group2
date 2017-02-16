#include "mainwindow.h"

using namespace std;

//double subBench [10000][10000];


bool MainWindow::doCheck() {
    
    int i,j;
    bool finalCheck = true;
    
    for (j=0; j<=grid-1; j++) {
        for (i=0; i<=grid-1; i++) {
            
            if (abs(values[i][j] - subBench[i][j]) > 0.0000001) {
                //cout << "false: " << abs(values[i][j] - subBench[i][j]) << endl;
                finalCheck = false;
            }
            
            
        }
    }
    
    return finalCheck;

    }
