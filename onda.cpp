#include <iostream>
#include <cmath>

double valor_u(double x);

int main(){
  double x = 0.0;
  float c = 0.1;
  double delta_x = 0.01;
  double delta_t = 0.0001;
  double k = ((c*c)*(delta_t * delta_t)) /(delta_x*delta_x);

  int N_x = 1.0/delta_x +1 ;
  
  double *u_i = new double[N_x];
  double *u_ip = new double[N_x];
  double *u_j = new double[N_x];
  double *u_jp = new double[N_x];

  double *u_1 = new double[N_x];
  double *u_2 = new double[N_x];
  double *u_3 = new double[N_x];
  double *u_4 = new double[N_x];

  for(int i=0; i<N_x ; i++){
    u_ip[i] = valor_u(x);
    u_1[i] = valor_u(x);
    u_j[i] = valor_u(x);
    u_i[i] = valor_u(x);
    u_jp[i] = valor_u(x);
    
    x =i*delta_x;
  }

  for(int j = 1; j<N_x-1 ; j++){
    for( int i=1; i<N_x-1 ; i++){
	if(j==1){
	  u_i[i] = (k/2)*(u_ip[i+1] - 2*u_ip[i] + u_ip[i-1]) + u_ip[i]; 
	}
	else{
	  u_i[i] = k * (u_ip[i+1] - 2*u_ip[i] + u_ip[i-1]) - u_jp[j-1] + 2*u_ip[i] ;
	}
	u_ip[i] = u_i[i];
      }
    u_jp[j] = u_i[j]; 
    
  }

	x = 0;

     for(int i = 0; i<N_x; i++){
    std::cout << x << " " << u_i[i] << std::endl;
    x += delta_x;
  }
  return 0;
}


double valor_u(double x){
  if(x==0 || x == 1){
    return 0;
  }
  else{
    return sin(2*3.141592654*x);
  }
}
