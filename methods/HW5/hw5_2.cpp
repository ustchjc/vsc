#include <stdio.h>
#include <math.h>

#define N 3
#define e pow(10,-6)
#define pi 3.1415926536

float a[10][10]={0};

float f(float x){
    float y;
    y=sqrt(2-sin(x)*sin(x));
    return y;
}

float T(int k){
    int n;
    n=N*pow(2,k-1);

    int i;
    float y=0;
    for(i=1;i<n;i++)
        y=y+f(-pi/(float)6+11*i*pi/(float)(12*n));
    y=y+0.5*(f(-pi/(float)6)+f(0.75*pi));
    y=y*11*pi/(float)(n*12);

    return y;
}

int Romberg(){
    int i=1;
    int j;

    a[1][1]=T(1);
    a[2][1]=T(2);
    a[2][2]=T(2)+(T(2)-T(1))/3.0;

    while(abs(a[i][i]-a[i+1][i+1])>e){
        i++;
        a[i+1][1]=T(i+1);
        for(j=2;j<=i+1;j++)
        a[i+1][j]=a[i+1][j-1]+(a[i+1][j-1]-a[i][j-1])/(float)(pow(4,j-1)-1);
    }

    return i++;
}

int main(){
    int i,j,n;
    n=Romberg();

    for(i=1;i<=(n+1);i++){
        for(j=1;j<=i;j++)
        printf("%f  ",a[i][j]);
        printf("\n");
    }

    return 0;
}
