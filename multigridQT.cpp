#include <QProcess>
#include <QCoreApplication>
#include "mainwindow.h"

using namespace std;

void approx_interpolate();
void approx_solve();
void create_grids();
void gauss_sweep();
void res_sweep();
void prolongation();
void restriction();
void fill_multi_bounds();
void initialize();

vector<vector<vector<double> > > residual;
vector<vector<vector<double> > > error;
vector<vector<vector<double> > > approx;
vector<vector<vector<bool> > > multi_bounds;

//weighting factor
float p=1;

int  grid_size, gauss_solves,current_grid,current_length;
int i, j,k, I, J,n,N,R,P,G;



void MainWindow::multigrid() {



    smoothing = 10;
        
	//initialise
	i=0;
	j=0;
	k=0;
	I=0;
	J=0;
	n=0;
	N=0;
    		            
    //open datafile: containing (x,y) & potential value
	ofstream datafile;
	datafile.open("lageneric_data.dat",ios::out);	
	
	//initialise all grids including fixed values (i.e plates)
    create_grids();
    fill_multi_bounds();
    initialize();
		
	//Solve exactly on smallest grid
	//Smallest grid is 0, then 1... all the way to the largest grid (grid_num-1)
	 current_grid=0;
	 current_length=approx[current_grid].size()-2;
	 gauss_solves=coarse_loops;
	 approx_solve();
	 	 	     					
	//switch to using a small number of iterations of gauss_seidel				
	gauss_solves=smoothing;	
	
	//Begin full multigrid method proper
	//Starting and the second coarsest grid
	for(G=1;G<=grid_num-1;G++){
	
		//define current grid number and length
		current_grid=G;
		current_length=approx[current_grid].size()-2;
		
		//interpolate previous solution
		approx_interpolate();
		
		//smooth
		approx_solve();
		
		
		//find residual of approximate solution
		//residual calculation		
		for(J=2;J<=(current_length-1);J++){
		  	for(I=2;I<=(current_length-1);I++){
			  	if(multi_bounds[current_grid][I][J]==true){
					residual[current_grid][I][J] += approx[current_grid][I+1][J]+approx[current_grid][I-1][J]+approx[current_grid][I][J+1]+approx[current_grid][I][J-1]-4*approx[current_grid][I][J];
			  	}

			}
		  
		} //residual end
	
    			
		//restriction + smoothing run
		//restrict the residual(above) to coarsest grid
		//smoothing on residual applied at each step
		for(R=G-1; R>=0; R--) {
	
			current_grid=R;
			current_length=approx[current_grid].size()-2;
			
			//Solves exactly on coarsest grid
			if(R==0){
				gauss_solves=coarse_loops;
			}
	
			//applies restriction + smoothing on residual
			restriction();
		}

	
		gauss_solves=smoothing;
		

		//Interpolates error back to finest grid
		for(P=1; P<=G;P++){
		
			current_grid=P;
			current_length=approx[current_grid].size()-2;
			
			//prolongation + smoothing
			prolongation();
	  
		}
  
		//adds errors to smoothest grid	
		current_grid=grid_num-1;
		current_length=approx[current_grid].size()-2;
		
		//add error to intial approximation of potential values
		for(j=1; j<=current_length; j++) {
			for(i=1; i<=current_length; i++) {
			  if( multi_bounds[current_grid][i][j]==true ) {
				approx[current_grid][i][j]+=error[current_grid][i][j];
			  }
			  
			}
			
		}
		
		//post smoothing
		approx_solve();
    	   
    }
   
    
    //print results to file
		for(j=1; j<=current_length; j++) {
			for(i=1; i<=current_length; i++) {
			
					datafile << i << "	" << j << "	" << approx[current_grid][i][j] << "	   " << "\n";
			
			}
			datafile << "\n";
		}	     

		datafile.close();
        QProcess::startDetached("./laplotter.sh");
        //QCoreApplication::processEvents();
}


////////////////////////////////////////////////////////////////////////////////////

void approx_interpolate(){

	//interpolate to finer grid
    for(J=1; J<=(approx[current_grid-1].size()-2); J++) {
        j=(2*J)-1;
        
        for(I=1; I<=(approx[current_grid-1].size()-2); I++) {
            i=(2*I)-1;
			
			if( multi_bounds[current_grid][i][j]==true ) {
					approx[current_grid][i][j] = approx[current_grid-1][I][J];
				}    
					// side points
				if( multi_bounds[current_grid][i][j+1]==true ) {
			        
				    approx[current_grid][i][j+1] = approx[current_grid][i][j];
				  
				}
				if( multi_bounds[current_grid][i][j-1]==true ) {
								approx[current_grid][i+1][j] = approx[current_grid][i][j];
				 }
				if( multi_bounds[current_grid][i+1][j]==true ) {
								approx[current_grid][i+1][j+1] = approx[current_grid][i][j];
				 }
										
        }
        
        
    }
          
	
}
////////////////////////////////////////////////////////////////////////////////////
void approx_solve(){

	for(n=0; n<=gauss_solves; n++) {
			for (j=2; j<=current_length-1; j++) {
					for (i=2; i<=current_length-1; i++) {
                        //QCoreApplication::processEvents();
							if( multi_bounds[current_grid][i][j]==true ) {
				
									approx[current_grid][i][j] = (1.0/4.0) * (approx[current_grid][i][j+1] + approx[current_grid][i][j-1] + approx[current_grid][i+1][j] + approx[current_grid][i-1][j]);
							}
							
					}
					
			}		
			gauss_sweep();	
	}



}


///////////////////////////////////////////////////////////////////////////////////////


void restriction() {
    
    
    //res_sweep();
    
    // restrict to coarse grid
    for(J=1; J<=current_length; J++) {
        //lower case used to index finer grid
        j=(2*J)-1;
        for(I=1; I<=current_length; I++) {
            i=(2*I)-1;
            //change bellow
            if( multi_bounds[current_grid][I][J]==true ) {
                
               residual[current_grid][I][J]= 0.25*(residual[current_grid+1][i][j]+residual[current_grid+1][i+1][j]+residual[current_grid+1][i+1][j+1]+residual[current_grid+1][i][j+1]) ;
                
            }
        }

    } // end coarse conversion
    
    //smoothing correction on coarser grid
    for(N=0; N<(gauss_solves); N++) {
        for (J=2; J<=(current_length-1); J++) {
            
            for (I=2; I<=(current_length-1); I++) {

                //QCoreApplication::processEvents();
               
                if( multi_bounds[current_grid][I][J]==true ) {
                    
                    error[current_grid][I][J] = ((1.0/4.0) * (error[current_grid][I][J+1] + error[current_grid][I][J-1] + error[current_grid][I+1][J] + error[current_grid][I-1][J])+residual[current_grid][I][J]);
                    
                }
            }
        }
	// gauss end
    }
		
	//res_sweep();  
    //residual calculation
    for(J=2;J<=(current_length-1);J++){
        for(I=2;I<=(current_length-1);I++){
        	if(multi_bounds[current_grid][I][J]==true){
		  		residual[current_grid][I][J]+=error[current_grid][I+1][J]+error[current_grid][I-1][J]+error[current_grid][I][J+1]+error[current_grid][I][J-1]-4*error[current_grid][I][J];
            }
        }
    } //residual end
    
    
    
    
}

//////////////////////////////////////////////////////////////////////////////////////////////

void prolongation(){

    //interpolate back to finer grid
    for(J=1; J<=(residual[current_grid-1].size()-2); J++) {
        j=(2*J)-1;
        for(I=1; I<=(residual[current_grid-1].size()-2); I++) {
            i=(2*I)-1;
            
           
            	if( multi_bounds[current_grid][i][j]==true ) {
					error[current_grid][i][j] = error[current_grid-1][I][J];
				}    
					// side points
				if( multi_bounds[current_grid][i][j+1]==true ) {
			        
				    error[current_grid][i][j+1] = error[current_grid][i][j];
				  
				}
				if( multi_bounds[current_grid][i][j-1]==true ) {
								error[current_grid][i+1][j] = error[current_grid][i][j];
				 }
				if( multi_bounds[current_grid][i+1][j]==true ) {
								error[current_grid][i+1][j+1] = error[current_grid][i][j];
				 }
            
        }
    }
   
    
    
    
    // smoothing residual equation
    for(n=0; n<=smoothing; n++) {         		
        for (j=2; j<=(current_length-1); j++) {
            for (i=2; i<=(current_length-1); i++) {
                if( multi_bounds[current_grid][i][j]==true ) {                    
                    error[current_grid][i][j] = (1.0/4.0) * (error[current_grid][i][j+1] + error[current_grid][i][j-1] + error[current_grid][i+1][j] + error[current_grid][i-1][j])+residual[current_grid][i][j];
                }
            }
        }         
        // gauss end
    }
    
}	



///////////////////////////////////////////////////////////////////////////////////
void gauss_sweep() {
  
    int c;


		for (i=2;i<=(current_length-1);i++){
             		j=current_length;   // upper inner line
			if( multi_bounds[current_grid][i][j]==true ) {
				
                		approx[current_grid][i][j] = (1.0/4.0) * (approx[current_grid][i][j-1] + approx[current_grid][i+1][j] + approx[current_grid][i-1][j] + (p*approx[current_grid][i][j]));
               		}	

			j=1;  // lower inner line
			if( multi_bounds[current_grid][i][j]==true ) {
				
                    		approx[current_grid][i][j] = (1.0/4.0) * (approx[current_grid][i][j+1] + approx[current_grid][i+1][j] + approx[current_grid][i-1][j] + (p*approx[current_grid][i][j]));
                	}
    		}
        
		for (j=2;j<=(current_length-1);j++){
          		i=current_length;   // right inner line
                	if( multi_bounds[current_grid][i][j]==true ) {
				
                    		approx[current_grid][i][j] = (1.0/4.0) * (approx[current_grid][i][j+1] + approx[current_grid][i][j-1] + approx[current_grid][i-1][j] + (p*approx[current_grid][i][j]));
              		}

				i=1;  // left inner line
                	if( multi_bounds[current_grid][i][j]==true ) {
				
                    		approx[current_grid][i][j] = (1.0/4.0) * (approx[current_grid][i][j+1] + approx[current_grid][i][j-1] + approx[current_grid][i+1][j] + (p*approx[current_grid][i][j]));
                	}
    		}

        // corner points
        c= current_length;
        if( multi_bounds[current_grid][1][1]==true ) {
			approx[current_grid][1][1]=(1.0/4.0) * (approx[current_grid][2][1] + approx[current_grid][1][2] + (p*approx[current_grid][1][1])  + (p*approx[current_grid][1][1]));
		}		

        if( multi_bounds[current_grid][1][c]==true ) {
            approx[current_grid][1][c]=(1.0/4.0) * (approx[current_grid][1][c] + approx[current_grid][1][c-1] + (p*approx[current_grid][1][c])  + (p*approx[current_grid][1][c]));
		}		

        if( multi_bounds[current_grid][c][1]==true ) {
            approx[current_grid][c][1]=(1.0/4.0) * (approx[current_grid][c-1][1] + approx[current_grid][c][1]  + (p*approx[current_grid][c][1])  + (p*approx[current_grid][c][1]));
		}	

		if( multi_bounds[current_grid][c][c]==true ) {
			approx[current_grid][c][c]=(1.0/4.0) * (approx[current_grid][c-1][c] + approx[current_grid][c][c-1] + (p*approx[current_grid][c][c])  + (p*approx[current_grid][c][c]));
        }

}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void create_grids(){

//Initialise residual grids
    //create vector of (grid_num) grids, halfing in size each time
    for(i=0;i<grid_num;i++){
        vector <vector<double> > r_twoD;
        grid_size=grid*(pow(2,i));
        for(j=0;j<grid_size+2;j++){
            vector<double> r_oneD;
            for(k=0;k<grid_size+2;k++){
                r_oneD.push_back(0);
            }
            r_twoD.push_back(r_oneD);
        }
        residual.push_back(r_twoD);
    }
    
    //initialise error grids
    for(i=0;i<grid_num;i++){
        vector <vector<double> > e_twoD;
        grid_size=grid*(pow(2,i));
        for(j=0;j<grid_size+2;j++){
            vector<double> e_oneD;
            for(k=0;k<grid_size+2;k++){
                e_oneD.push_back(0);
            }
            e_twoD.push_back(e_oneD);
        }
        error.push_back(e_twoD);
    }
    
      //initialise error grids
    for(i=0;i<grid_num;i++){
        vector <vector<double> > a_twoD;
        grid_size=grid*(pow(2,i));
        for(j=0;j<grid_size+2;j++){
            vector<double> a_oneD;
            for(k=0;k<grid_size+2;k++){
                a_oneD.push_back(0);
            }
            a_twoD.push_back(a_oneD);
        }
        approx.push_back(a_twoD);
    }
    
     for(i=0;i<grid_num;i++){
        vector <vector<bool> > b_twoD;
        grid_size=grid*(pow(2,i));
        for(j=0;j<grid_size+2;j++){
            vector<bool> b_oneD;
            for(k=0;k<grid_size+2;k++){
                b_oneD.push_back(true);
            }
            b_twoD.push_back(b_oneD);
        }
        multi_bounds.push_back(b_twoD);
    }
    

	
}


void initialize(){

  int multiplier=0;


 for(k=0;k<=(grid_num-1);k++){
            multiplier=pow(2,k);
        grid_size=grid*multiplier;
            for(J=1;J<=grid_size;J++){

              for(I=1;I<=grid_size;I++){
                  if(multi_bounds[k][I][J]==true){
              approx[k][I][J]=0;																								}
              }
         }
    }

  for(k=0;k<=(grid_num-1);k++){
            multiplier=pow(2,k);
        grid_size=grid*multiplier;
            for(J=1;J<=grid_size;J++){

                for(I=1;I<=grid_size;I++){

              residual[k][I][J]=0;
            }
         }
    }

 for(k=0;k<=(grid_num-1);k++){
            multiplier=pow(2,k);
        grid_size=grid*multiplier;
            for(J=1;J<=grid_size;J++){

                     for(I=1;I<=grid_size;I++){
                         error[k][I][J]=0;
              }
           }
    }


}





void fill_multi_bounds(){
    int multiplier;
for(k=0;k<=(grid_num-1);k++){
            multiplier=pow(2,k);
        grid_size=grid*multiplier;
            for(J=1;J<=grid_size;J++){

                     for(I=1;I<=grid_size;I++){
                         multi_bounds[k][I][J]=true;
              }
           }
    }


    //copy everything from values grid to coarsest grid
        k=0;

        for(j=1;j<=grid;j++){
             for(i=1;i<=grid;i++){

                      multi_bounds[k][i][j] = bounds[i-1][j-1];
                      approx[k][i][j]=values[i-1][j-1];


             }

        }

    //fill all grids with initial values and the equivalent bounds array
    for(k=0;k<grid_num-1;k++){
            multiplier=pow(2,k);
            grid_size=grid*multiplier;
            for(J=1;J<=grid_size;J++){
                     j=2*J-1;
                     for(I=1;I<=grid_size;I++){
                              i=2*I-1;


                              //use simple injection
                              //trasfer to origin centered grid
                              multi_bounds[k+1][i][j]=multi_bounds[k][I][J];
                              multi_bounds[k+1][i+1][j]=multi_bounds[k][I][J];
                              multi_bounds[k+1][i][j+1]=multi_bounds[k][I][J];
                              multi_bounds[k+1][i+1][j+1]=multi_bounds[k][I][J];

                              approx[k+1][i][j]=approx[k][I][J];
                              approx[k+1][i+1][j]=approx[k][I][J];
                              approx[k+1][i][j+1]=approx[k][I][J];
                              approx[k+1][i+1][j+1]=approx[k][I][J];


                    }

            }

    }





}







