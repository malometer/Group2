


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
    cin >> op;
    
    
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





int main() {

    int done,op;
    
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

    cout << "Specify your numerical method" << endl;
    cout << "1: Jacobi" << endl;
    cin >> op;
    
    
    switch(op) {
        case 1:
            jacobi();
            break;
            
    }
    
    cout << "All done! please run 'laplotter.sh'" << endl;


    return 0;
}


















