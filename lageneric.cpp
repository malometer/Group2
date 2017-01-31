


#include "methods.hpp"
#include "boundaries.hpp"
#include "lageneric.hpp"


using namespace std;

int grid,loop;
float i2,j2;
double values[10000][10000];
bool bounds[10000][10000];
double closeness, square_dist;
double dist;






int add_shapes() {
    
    int op=0;
    int done = 0;

    cout << "\n(for best results - try and have the voltage range from -n to n)\n" << endl;
    
    cout << "Press 1 to add a simple boundary to your grid." << endl;
    cout << "Press 2 to add a radial boundary to your grid." << endl;
    cout << "Press 0 when done" << endl;
   // cin >> op;
    
    
    switch(op) {
        case 1:
            simple_bound();
            break;
        case 2:
            circular_bound();
            break;
        case 0:
            done = 1;
            break;
            
    }
    
    return done;
    
    
}
























