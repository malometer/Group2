#include "mainwindow.h"

using namespace std;

void MainWindow::gauss_seidel() {

	int m=0;    
	int i=0;
	int j=0;
	int c=0;  
	float p = 1;  // maybe add
    
	ofstream datafile;
    datafile.open("lageneric_data.dat",ios::out);
    if (datafile.is_open() == 1) {cout << "OPEN!" << endl;} else {cout << "NOOOO" << endl;}
    datafile << "#are you using the right file?" << endl;
	for(m=0; m<=(loop-1); m++) {
        
        
        
        
        
        
        
        	for (j=1; j<=(grid-2); j++) {
			for (i=1; i<=(grid-2); i++) {
                
                subBench[i][j] = values[i][j];
                
                
                		if( bounds[i][j]==true ) {
                    
                    			values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]);
				}
			}
		}
	

////////////////////////////////////////////////////////////////////////////////////////////////

		for (i=1;i<=(grid-2);i++){
             		j=grid-1;
            subBench[i][j] = values[i][j];// upper inner line
			if( bounds[i][j]==true ) {
				
                		values[i][j] = (1.0/4.0) * (values[i][j-1] + values[i+1][j] + values[i-1][j] + (p*values[i][j]));
               		}	

			j=0;
            subBench[i][j] = values[i][j];
			if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i+1][j] + values[i-1][j] + (p*values[i][j]));
                	}
    		}
        
		for (j=1;j<=(grid-2);j++){
          		i=grid-1;
            subBench[i][j] = values[i][j];// right inner line
                	if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i-1][j] + (p*values[i][j]));
              		}

			i=0;
            subBench[i][j] = values[i][j];
                	if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + (p*values[i][j]));
                	}
    		}

		// corner points
		c=grid-1;
        subBench[0][0] = values[0][0];
        subBench[0][c] = values[0][c];
        subBench[c][0] = values[c][0];
        subBench[c][c] = values[c][c];
        
		if( bounds[0][0]==true ) {
			values[0][0]=(1.0/4.0) * (values[1][0] + values[0][1] + (p*values[0][0])  + (p*values[0][0]));
		}		

		if( bounds[0][c]==true ) {
			values[0][c]=(1.0/4.0) * (values[1][c] + values[0][c-1] + (p*values[0][c])  + (p*values[0][c]));
		}		

		if( bounds[c][0]==true ) {
			values[c][0]=(1.0/4.0) * (values[c-1][0] + values[c][1]  + (p*values[c][0])  + (p*values[c][0]));
		}	

		if( bounds[c][c]==true ) {
			values[c][c]=(1.0/4.0) * (values[c-1][c] + values[c][c-1] + (p*values[c][c])  + (p*values[c][c]));
		}
        
        
        

////////////////////////////////////////////////////////////////////////////////////////////
 /*
        if  (m == floor(loop/6) )  {
            cout << "£££££££";
        } else if (m == floor((2*loop)/6)) {
            cout << "£££££££";
        }else if  (m == floor((3*loop)/6))  {
                cout << "£££££££";
        } else if (m == floor((4*loop)/6)) {
                cout << "£££££££";
        } else if (m == floor((5*loop)/6)) {
            cout << "£££££££" << endl;
        } else if (m == (loop-1)) {
            cout << "£££££££" << endl;
        }
 */

        if (doCheck() == true) {
            cout << "accuracy reached, breaking out, loop is at: " << m << endl;
            break;

        }

}
    
    
    
    
    
    
    	for (i=(grid-1); i>=0; i--) {
        	for (j=0; j<=(grid-1); j++) {
            
            		datafile << i << "	" << j << "	" << values[i][j] << "	   " << "\n";
        	}

        	datafile << "\n";
    	}
    
    	datafile.close();
    
    
    
}

