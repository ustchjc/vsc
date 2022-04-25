#include <stdio.h>
#include <math.h>

#define lambda 0.25

float a[101];
float b[101];

void phi(){
    int i;
    for(i=0;i<101;i++){
        if(i<50)
        a[i]=20.0*i/100.0;
        else
        a[i]=20.0-20.0*i/100.0;
    }
}

float laplace(int i){
    float y;
    y=a[i-1]+a[i+1]-2.0*a[i];
    return y;
}

void Crank_Nicolson(){
    int j;
    b[0]=0;
    b[100]=0;
    for(j=1;j<100;j++){
        b[j]=(a[j]+lambda*laplace(j));
    }
    for(j=0;j<101;j++)
        a[j]=b[j];
}

int main(){
    int i,j;
    phi();

    for(i=0;i<4000;i++)
    Crank_Nicolson();

    for(j=0;j<101;j++){
        //if(j%10==0)
        printf("%f\n",a[j]);
        //if(j%10==0)
        //printf("\n");
    }

    return 0;
}