#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

void gauss_sweep();
void correction_sweep();
void course_sweep();
void res_sweep();

float ERR[500][500], err[500][500], hr[500][500], Hr[500][500];

float p=1;
int c;
int word;
 
int GRID2;
int i, j, I, J, n,N, m;

void two_grid();

int smoothing=10;       //set elsewhere?
int coarse_loops=10000; //set elsewhere?

void MainWindow::multigrid() {

    	i=0;
    	j=0;
        I=0;
    	J=0;
    	n=0;
    	N=0;
    	m=0;
    	c=0;
    smoothing=10;
    coarse_loops=10000;

	ofstream datafile;
    datafile.open("./linuxUiUpdate/lageneric_data.dat",ios::out);
    if (datafile.is_open() == 1) {cout << "OPEN!" << endl;} else {cout << "NOOOO" << endl;}

    //manually set values, need to include these in GUI
    int grid_num = 4;
    grid_num = ui->spinBox->value();

	for(m=1; m<=grid_num; m++) {

     		GRID2 = grid/pow(2,m);
	     
	}
	     
	for(j=1; j<=grid-2; j++) {
		for(i=1; i<=grid-2; i++) {
                        
				datafile << i << "	" << j << "	" << values[i][j] << "	   " << "\n";
			
		}
		datafile << "\n";
	}	     

	datafile.close();
}


void MainWindow::gauss_sweep() {
  


		for (i=1;i<=(grid-2);i++){
             		j=grid-1;   // upper inner line
			if( bounds[i][j]==true ) {
				
                		values[i][j] = (1.0/4.0) * (values[i][j-1] + values[i+1][j] + values[i-1][j] + (p*values[i][j]));
               		}	

			j=0;  // lower inner line
			if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i+1][j] + values[i-1][j] + (p*values[i][j]));
                	}
    		}
        
		for (j=1;j<=(grid-2);j++){
          		i=grid-1;   // right inner line
                	if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i-1][j] + (p*values[i][j]));
              		}

			i=0;  // left inner line
                	if( bounds[i][j]==true ) {
				
                    		values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + (p*values[i][j]));
                	}
    		}

		// corner points
		c=grid-1;
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

}

void MainWindow::correction_sweep() {
  

		for (I=1;I<=(GRID2-1);I++){
             		J=GRID2;
			j=(2*J)-1;
			 i=(2*I)-1;
			
			// upper inner line
			if( bounds[i][j]==true ) {
				
                		ERR[I][J] = ((1.0/4.0) * (ERR[I][J] + ERR[I][J-1] + ERR[I+1][J] + ERR[I-1][J])) + Hr[I][J];
               		}	

			J=0;
			j=0;// lower inner line
			if( bounds[i][j]==true ) {
				
                    		ERR[I][J] = ((1.0/4.0) * (ERR[I][J+1] + ERR[I][J] + ERR[I+1][J] + ERR[I-1][J])) + Hr[I][J];
                	}
    		}
        
		for (J=1;J<=GRID2-1;J++){
          		I=GRID2;
			j=(2*J)-1;
			 i=(2*I)-1;  // right inner line
                	if( bounds[i][j]==true ) {
				
                    		ERR[I][J] = ((1.0/4.0) * (ERR[I][J+1] + ERR[I][J-1] + ERR[I][J] + ERR[I-1][J])) + Hr[I][J];
              		}

			I=0; 
			i=0;  // left inner line
                	if( bounds[i][j]==true ) {
				
                    		ERR[I][J] = ((1.0/4.0) * (ERR[I][J+1] + ERR[I][J-1] + ERR[I+1][J] + ERR[I][J])) + Hr[I][J];
                	}
    		}

		// corner points
		c=GRID2;
        word = (2*c)-1;
    
		if( bounds[0][0]==true ) {
			ERR[0][0] = ((1.0/4.0) * (ERR[0][1] + ERR[1][0] + ERR[0][0] + ERR[0][0])) + Hr[0][0];
		}		

		if( bounds[0][word]==true ) {
			ERR[0][c] = ((1.0/4.0) * (ERR[0][c-1] + ERR[1][c] + ERR[0][c] + ERR[0][c])) + Hr[0][c];
		}		

		if( bounds[word][0]==true ) {
			ERR[c][0] = ((1.0/4.0) * (ERR[c-1][0] + ERR[c][1] + ERR[c][0] + ERR[c][0])) + Hr[c][0];
		}	

		if( bounds[word][word]==true ) {
			ERR[c][c] = ((1.0/4.0) * (ERR[c-1][c] + ERR[c][c-1] + ERR[c][c] + ERR[c][c])) + Hr[c][c];
		}	
}

void MainWindow::course_sweep() {
    
    
    
    for (I=1;I<=(GRID2-1);I++){
        J=GRID2;
        j=(2*J)-1;
        i=(2*I)-1;
        
        // upper inner line
        if( bounds[i][j]==true ) {
            
            
            Hr[I][J]=(hr[i][j]*1.0/4.0) + (hr[i+1][j]*1.0/8.0) + (hr[i-1][j]*1.0/8.0) + (hr[i][j]*1.0/8.0) + (hr[i][j-1]*1.0/8.0) + (hr[i-1][j]*1.0/16.0) + (hr[i+1][j]*1.0/16.0) + (hr[i-1][j-1]*1.0/16.0) + (hr[i+1][j-1]*1.0/16.0);
        }
        
        J=0;
        j=0;// lower inner line
        if( bounds[i][j]==true ) {
            
             Hr[I][J]=(hr[i][j]*1.0/4.0) + (hr[i+1][j]*1.0/8.0) + (hr[i-1][j]*1.0/8.0) + (hr[i][j+1]*1.0/8.0) + (hr[i][j]*1.0/8.0) + (hr[i-1][j+1]*1.0/16.0) + (hr[i+1][j+1]*1.0/16.0) + (hr[i-1][j]*1.0/16.0) + (hr[i+1][j]*1.0/16.0);
        }
    }
    
    for (J=1;J<=GRID2-1;J++){
        I=GRID2;
        j=(2*J)-1;
        i=(2*I)-1;  // right inner line
        if( bounds[i][j]==true ) {
            
             Hr[I][J]=(hr[i][j]*1.0/4.0) + (hr[i][j]*1.0/8.0) + (hr[i-1][j]*1.0/8.0) + (hr[i][j+1]*1.0/8.0) + (hr[i][j-1]*1.0/8.0) + (hr[i-1][j+1]*1.0/16.0) + (hr[i][j+1]*1.0/16.0) + (hr[i-1][j-1]*1.0/16.0) + (hr[i][j-1]*1.0/16.0);
        }
        
        I=0;
        i=0;  // left inner line
        if( bounds[i][j]==true ) {
            
             Hr[I][J]=(hr[i][j]*1.0/4.0) + (hr[i+1][j]*1.0/8.0) + (hr[i][j]*1.0/8.0) + (hr[i][j+1]*1.0/8.0) + (hr[i][j-1]*1.0/8.0) + (hr[i][j+1]*1.0/16.0) + (hr[i+1][j+1]*1.0/16.0) + (hr[i][j-1]*1.0/16.0) + (hr[i+1][j-1]*1.0/16.0);
        }
    }
    
    // corner points
    c=GRID2;
    word = (2*c)-1;
    
    if( bounds[0][0]==true ) {
         Hr[0][0]=(hr[0][0]*1.0/4.0) + (hr[1][0]*1.0/8.0) + (hr[0][0]*1.0/8.0) + (hr[0][1]*1.0/8.0) + (hr[0][0]*1.0/8.0) + (hr[0][1]*1.0/16.0) + (hr[1][1]*1.0/16.0) + (hr[0][0]*1.0/16.0) + (hr[1][0]*1.0/16.0);
    }
    
    if( bounds[0][word]==true ) {
         Hr[0][c]=(hr[0][word]*1.0/4.0) + (hr[1][word]*1.0/8.0) + (hr[0][word]*1.0/8.0) + (hr[0][word]*1.0/8.0) + (hr[0][word-1]*1.0/8.0) + (hr[0][word]*1.0/16.0) + (hr[1][word]*1.0/16.0) + (hr[0][word-1]*1.0/16.0) + (hr[1][word-1]*1.0/16.0);
    }
    
    if( bounds[word][0]==true ) {
         Hr[c][0]=(hr[word][0]*1.0/4.0) + (hr[word][0]*1.0/8.0) + (hr[word-1][0]*1.0/8.0) + (hr[word][1]*1.0/8.0) + (hr[word][0]*1.0/8.0) + (hr[word-1][1]*1.0/16.0) + (hr[word][1]*1.0/16.0) + (hr[word-1][0]*1.0/16.0) + (hr[word][0]*1.0/16.0);
    }
    
    if( bounds[word][word]==true ) {
         Hr[c][c]=(hr[i][j]*1.0/4.0) + (hr[word][word]*1.0/8.0) + (hr[word-1][word]*1.0/8.0) + (hr[word][word]*1.0/8.0) + (hr[word][word-1]*1.0/8.0) + (hr[word-1][word]*1.0/16.0) + (hr[word][word]*1.0/16.0) + (hr[word-1][word-1]*1.0/16.0) + (hr[word][word-1]*1.0/16.0);
    }	
}


void MainWindow::res_sweep() {
    
    // hr[i][j]+=values[i+1][j]+values[i-1][j]+values[i][j+1]+values[i][j-1]-4*values[i][j];
    
    for (i=1;i<=(grid-2);i++){
        j=grid-1;   // upper inner line
        if( bounds[i][j]==true ) {
            
            hr[i][j]+=values[i+1][j]+values[i-1][j]+values[i][j]+values[i][j-1]-4*values[i][j];
        }
        
        j=0;  // lower inner line
        if( bounds[i][j]==true ) {
            
            hr[i][j]+=values[i+1][j]+values[i-1][j]+values[i][j+1]+values[i][j]-4*values[i][j];
        }
    }
    
    for (j=1;j<=(grid-2);j++){
        i=grid-1;   // right inner line
        if( bounds[i][j]==true ) {
            
            hr[i][j]+=values[i][j]+values[i-1][j]+values[i][j+1]+values[i][j-1]-4*values[i][j];
        }
        
        i=0;  // left inner line
        if( bounds[i][j]==true ) {
            
            hr[i][j]+=values[i+1][j]+values[i][j]+values[i][j+1]+values[i][j-1]-4*values[i][j];
        }
    }
    
    // corner points
    c=grid-1;
    if( bounds[0][0]==true ) {
        hr[0][0]+=values[1][0]+values[0][0]+values[0][1]+values[0][0]-4*values[0][0];
    }
    
    if( bounds[0][c]==true ) {
       hr[0][c]+=values[1][c]+values[0][c]+values[0][c]+values[0][c-1]-4*values[0][c];
    }
    
    if( bounds[c][0]==true ) {
        hr[c][0]+=values[c][0]+values[c-1][0]+values[c][1]+values[c][0]-4*values[c][0];
    }
    
    if( bounds[c][c]==true ) {
        hr[c][c]+=values[c][c]+values[c-1][c]+values[c][c]+values[c][c-1]-4*values[c][c];
    }	
    
}

void MainWindow::two_grid() {

	// gauss start
		for(n=0; n<=smoothing; n++) {         		
			for (j=1; j<=(grid-2); j++) {
				for (i=1; i<=(grid-2); i++) {
                			if( bounds[i][j]==true ) {
                    
                    				values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]);
					}
				}
			} 
			
			gauss_sweep();
			// gauss end
		}


		//residual calculation
		for(j=1;j<=(grid-2);j++){
		  	for(i=1;i<=(grid-2);i++){
		     		hr[i][j]+=values[i+1][j]+values[i-1][j]+values[i][j+1]+values[i][j-1]-4*values[i][j];

		    	}
		} //residual end
        
        res_sweep();
		
		// coarse grid
		for(J=1; J<=GRID2-1; J++) {
			j=(2*J)-1;
			for(I=1; I<=GRID2-1; I++) {
				i=(2*I)-1;
                		if( bounds[i][j]==true ) {

					Hr[I][J]=(hr[i][j]*1.0/4.0) + (hr[i+1][j]*1.0/8.0) + (hr[i-1][j]*1.0/8.0) + (hr[i][j+1]*1.0/8.0) + (hr[i][j-1]*1.0/8.0) + (hr[i-1][j+1]*1.0/16.0) + (hr[i+1][j+1]*1.0/16.0) + (hr[i-1][j-1]*1.0/16.0) + (hr[i+1][j-1]*1.0/16.0);
					//ERR[I][J] = ((1.0/4.0) * (ERR[I][J+1] + ERR[I][J-1] + ERR[I+1][J] + ERR[I-1][J])) + Hr[I][J];
				        
				}
			}
            //course_sweep();
		} // end coarse conversion


		//correction on coarse grid
		for(N=0; N<=(coarse_loops); N++) {         		
			for (J=1; J<=(GRID2-1); J++) {
			  j=(2*J)-1;
				for (I=1; I<=(GRID2-1); I++) {
				  i=(2*I)-1;
                			if( bounds[i][j]==true ) {
					  j=(2*J)-1;
                    			        ERR[I][J] = ((1.0/4.0) * (ERR[I][J+1] + ERR[I][J-1] + ERR[I+1][J] + ERR[I-1][J])) + Hr[I][J];
				        
					}
				}
			}
            correction_sweep();// gauss end
		}
		  
		for(J=1; J<=(GRID2-1); J++) {
			j=(2*J)-1;
			for(I=1; I<=(GRID2-1); I++) {
				i=(2*I)-1;

                		if( bounds[i][j]==true ) {
					err[i][j] = ERR[I][J];	

					// side points
					err[i][j+1] += err[i][j]*1.0/2.0;
					err[i][j-1] += err[i][j]*1.0/2.0;
					err[i+1][j] += err[i][j]*1.0/2.0;
					err[i-1][j] += err[i][j]*1.0/2.0;
				
					// corner points
					err[i-1][j+1] += err[i][j]*1.0/4.0;
					err[i+1][j+1] += err[i][j]*1.0/4.0;
					err[i-1][j-1] += err[i][j]*1.0/4.0;
					err[i+1][j-1] += err[i][j]*1.0/4.0;
				}
			}
		}
	

	for(j=1; j<=grid-2; j++) {
		for(i=1; i<=grid-2; i++) {
                	if( bounds[i][j]==true ) {
				values[i][j] += err[i][j];
			        
			}
		}
	        
	}

	// gauss start
		for(n=0; n<=smoothing; n++) {         		
			for (j=1; j<=(grid-1); j++) {
				for (i=1; i<=(grid-1); i++) {
                			if( bounds[i][j]==true ) {
                    
                    				values[i][j] = (1.0/4.0) * (values[i][j+1] + values[i][j-1] + values[i+1][j] + values[i-1][j]);
					}
				}
			} 
			
		      gauss_sweep();
			// gauss end
		}
	}	








