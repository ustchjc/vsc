#include <stdio.h>
#include <math.h>

#define T 3;

int main(){
    int N;
    double x=2;
    double x_2=2;
    double t;
    double K_1,K_2,K_3,K_4;
    long int i;
    for(N=2;N<7;N++){
        t=3/pow(10,N);
        for(i=0;i<pow(10,N);i++){
            x=x_2;
            K_1=10.0-3.0*x;
            K_2=10.0-3.0*(x+0.5*t*K_1);
            K_3=10.0-3.0*(x+0.5*t*K_2);
            K_4=10.0-3.0*(x+t*K_3);
            x_2=x+t*(K_1+2*K_2+2*K_3+K_4)/6.0;
        }
        
        printf("当区间平均划分为10的%d次方块时，近似解为%.15f\n",N,x_2);
    }
}
