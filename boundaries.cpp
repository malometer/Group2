

#include "boundaries.hpp"
#include "lageneric.hpp"

using namespace std;


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
                
		values[j][i]=V0;
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
