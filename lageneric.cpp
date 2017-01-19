#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdint.h>
#include <iostream>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;


int grid,loop;
float i2,j2;
double values[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;



void circular_bound() {
    
    double V0=0, a=0;
    int cx=0,cy=0;
    

    
    
    cout << "Enter centre x" << endl;
    cin >> cx;
    cout << "Enter centre y" << endl;
    cin >> cy;
    cout << "Input radius" << endl;
    cin >> a;
    cout << "Input V0" << endl;
    cin >> V0;

    
    
    for(int i=0; i<=grid; i++) {
        for(int j=0; j<=grid; j++) {

            
            i2 = i - cx;
            i2 = i2*i2;
            
            j2 = j - cy;
            j2 = j2*j2;
            
            if (bounds[j][i] == true) {

            if (i2+j2<a*a) {
                
                bounds[j][i]=false;
                
            } else {
                
                bounds[j][i]=true;
                
                square_dist= i2 + j2;
                
                dist = sqrt(square_dist);
                closeness=abs(dist-a);

                if( closeness < 0.4 ) {
                    values[j][i]=V0;
                    bounds[j][i]=false;
                    
                }
                
            }
                
            }
        }
    }	
}

void simple_bound() {
    
    int line=0;
    int choice=0;
    int V0=0;
    
    
    cout << "1 for x parallel bound" << endl;
    cout << "2 for y parallel bound" << endl;
    cin >> choice;
    
    cout << "Input value along axis" << endl;
    cin >> line;
    
    cout << "Input V0" << endl;
    cin >> V0;
    
    
    for(int i=0; i<=grid; i++) {
        for(int j=0; j<=grid; j++) {
            
            if( bounds[j][i]==true ) {
            if (choice == 1) {
                
            
    
                if ( i == line ) {
                        values[j][i]=V0;
                        bounds[j][i]=false;
                }
                
            } else if (choice == 2) {
                
                if ( j == line ) {
                    values[j][i]=V0;
                    bounds[j][i]=false;
                }
                
                
            }
            
            }
            
        }
        
    }
   
	
}

int add_shapes() {
    
    int op=0;
    int done = 0;
    
    cout << "Press 1 to add a simple boundary to your grid." << endl;
    cout << "Press 2 to add a radial boundary to your grid." << endl;
    cout << "Press 3 when done" << endl;
    cin >> op;
    
    
    switch(op) {
        case 1:
            simple_bound();
            break;
        case 2:
            circular_bound();
            break;
        case 3:
            done = 1;
            break;
            
    }
    
    return done;
    
    
}


void jacobi() {
    
    int j=0;
    int c=0;
    
    
    
    ofstream datafile;
    datafile.open("lageneric_data.dat",ios::out);

    
    for(long int k=0; k<=loop; k++) {

        
        for (c=1;c<=(grid-1);c++) {
            
            for (j=1;j<=(grid-1);j++){
                if( bounds[j][c]==true ) {
                    
                    values[j][c] = (1.0/4.0) * (values[j][c+1] + values[j][c-1] + values[j+1][c] + values[j-1][c]);
                    
                }
            }
            
        }
        
        
    }
    
    
    for (j=(grid-1);j>=0;j--){
        
        for (c=0;c<=(grid-1);c++) {
            
            datafile << c << "	" << j << "	" << values[j][c] << "	   " << "\n";
            
        }
        datafile << "\n";
    }
    
    datafile.close();
}



int main() {

    int done;
    
    cout << "Enter grid size (resolution)" << endl;
    
    cin >> grid;
    
    
    for(int i=0; i<=grid; i++) {
        for(int j=0; j<=grid; j++) {
            
            bounds[j][i] = true;
            
        }
    }
    
    cout << "Enter # of loops" << endl;
    
    cin >> loop;
    
    do {
        
        done = add_shapes();
        
    } while (done == 0);
    
    jacobi();
    
    cout << "All done! please run 'laplotter.sh'" << endl;


    return 0;
}


















