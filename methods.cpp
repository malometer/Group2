

#include "methods.hpp"
#include "lageneric.hpp"

using namespace std;

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

