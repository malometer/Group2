#include<iostream>
#include<cmath>
#include<math.h>
#include<fstream>

using namespace std;
float electro(float V_o,float a,float b,float x,float y)
{
  float r,t,answer;
  r=sqrt(x*x+y*y);
  if(x>=0){
  t=atan(y/x)+M_PI/2;
  }
  else if(x<0){
    t=atan(y/x)+3*M_PI/2;
  }
  // cout<<sin(t)<<"  ";
  answer= V_o/(b-(pow(a,3)/pow(b,2))*pow(abs(sin(t)),3))*(r-(pow(a,3)/(r*r)))*sin(t);
  if(r<a){
    answer=0;
      }
  return answer;
}

int main(){
    float V_intial,a,b,dx,x,y;
    
    
    cout<<"Enter intial voltage"<<endl;
    cin>>V_intial;
    cout<<"enter grid size"<<endl;
    cin>>dx;
    cout<<"Enter width(origin to plate)"<<endl;
    cin>>b;
    cout<<"Enter radius"<<endl;
    cin>>a;
    ofstream file;
    file.open("analytical_potential.dat");
    for(int i=0;i<(2*b+1)/dx+1;i++){
	x=i*dx-b;
	  for(int j=0;j<(2*b)/dx+1;j++){
	      y=j*dx-b;
	      file<<x<<"  "<<y<<"  "<<electro(V_intial,a,b,x,y)<<"  "<<endl;
		}
	  file<<endl;
      }
	  
    file.close();

    return 0;
}
