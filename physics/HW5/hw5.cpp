#include <stdio.h>
#include <math.h>

#define PI 3.1415926536
#define Omega 1.75

float a[91][91]={0};
float b[91][91]={0};

float GS(int c,int d)
{
    float y;
    y=0.25*(a[c+1][d]+a[c][d+1]+a[c-1][d]+a[c][d-1]);
    return y;
}

void SOR(int e,int f)
{
    a[e][f]=(1-Omega)*a[e][f]+Omega*0.25*(a[e+1][f]+a[e][f+1]+a[e-1][f]+a[e][f-1]);
}

void Edge(){
    int m;
    int n;
    for(m=0;m<91;m++){
        a[m][90]=sinf(PI*m/90.0);
        a[m][0]=0;
        b[m][90]=sinf(PI*m/90.0);
        b[m][0]=0;
    }
    for(n=0;n<91;n++){
        a[0][n]=0;
        a[90][n]=0;
        b[0][n]=0;
        b[90][n]=0;
    }
}

int main(){
    int i,j,k;
    for(k=0;k<1000;k++){
        Edge();
        for(i=1;i<90;i++){
            for(j=1;j<90;j++)
            SOR(j,i);
        }
        
    }

    for(j=0;j<10;j++){
            for(i=0;i<10;i++)
            printf("%f  ",a[i*10][j*10]);
            printf("\n");
    }
}