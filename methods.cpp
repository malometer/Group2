

#include "methods.hpp"
#include "lageneric.hpp"

using namespace std;

void jacobi() {
    
    int j=0;
    int c=0;
    
    cout << "here int eh jacobi" << endl;
    
    
    ofstream datafile;
    datafile.open("lageneric_data.dat",ios::out);
    if (datafile.is_open()) {
        cout << "Apparently it exists... somewhere" << endl;
    }

    
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
            cout << "here in the loop" << endl;
            
            datafile << c << "	" << j << "	" << values[j][c] << "	   " << "\n";
            
        }
        datafile << "\n";
    }
    
    datafile.close();
    cout << "here at the end of Jacobi" << endl;
}

