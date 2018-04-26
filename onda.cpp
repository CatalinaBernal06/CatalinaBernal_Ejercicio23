#include <iostream>
#include <cmath>

double valor_u(double x);

int main(){
    double x = 0.0;
    float c = 0.1;
    double delta_x = 0.001;
    double delta_t = 0.0001;
    
    double k = ((c*c)*(delta_t * delta_t)) /(delta_x*delta_x);
    int N_x = 1.0/delta_x +1 ;
    
    double *u = new double[N_x];
    double *u_past = new double[N_x];
    double *u_jp = new double[N_x];
    
    double  **evo = new double*[4];
    
    for(int i=0; i<N_x ; i++){
        u[i] = valor_u(x);
        u_past[i] = valor_u(x);
        u_jp[i] = valor_u(x);
        
        x =i*delta_x;
    }
    
    for(int t=0; t<4; t++){
        evo[t] = new double[N_x];
    }
    
    
    int j = 1;
    int t = 0;
    while(t<4){
        for( int i=1; i<N_x-1 ; i++){
            if(j==1){
                u[i] = (k/2)*(u_past[i+1] - 2*u_past[i] + u_past[i-1]) + u_past[i];
            }
            else{
                u[i] = k * (u_past[i+1] - 2*u_past[i] + u_past[i-1]) - u_jp[i] + 2*u_past[i] ;
            }
        }

        if((t==0 && (u[N_x/4] <= 1.0)) || (t==1 && (u[N_x/4] <=0.5)) || (t==2 && (u[N_x/4] <= -0.5)) || (t == 3 && (u[N_x/4] <= -1.0))){
            for(int i = 0; i<N_x ; i++){
            evo[t][i] = u[i];
        }
         t +=1;
        }
        
        for (int i = 1; i<N_x - 1 ; i++){
            u_jp[i] = u_past[i];
            u_past[i] = u[i];
            
    }
        j +=1;
    }
    
    x = 0;
    
    for(int i = 0; i<N_x; i++){
        std::cout << x << " " << evo[0][i] << " " << evo[1][i] << " " << evo[2][i] << " " << evo[3][i] << std::endl;
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
