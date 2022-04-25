#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float a[4][4]={7.2,2.3,-4.4,0.5,1.3,6.3,-3.5,2.8,5.6,0.9,8.1,-1.3,1.5,0.4,3.7,5.9};
float b[4]={15.1,1.8,16.6,36.9};

float l[4][4]={0};
float u[4][4]={0};
float x[4]={0};
float y[4]={0};

void doolittle(){
    int i,j,k,r;
    for(k=0;k<4;k++){
        for(j=k;j<4;j++){
            u[k][j]=a[k][j];
                for(r=0;r<k;r++)
                u[k][j]=u[k][j]-l[k][r]*u[r][j];
        }
        for(i=k+1;i<4;i++){
            l[i][k]=a[i][k];
            for(r=0;r<k;r++)
            l[i][k]=l[i][k]-l[i][r]*u[r][k];
            l[i][k]=l[i][k]/u[k][k];
        }
    }
}

void solvedoo(){
    int i,j;
    for(i=0;i<4;i++){
        y[i]=b[i];
        for(j=0;j<i;j++)
        y[i]=y[i]-l[i][j]*y[j];
    }
    for(i=3;i>-1;i--){
        x[i]=y[i];
        for(j=i+1;j<4;j++)
        x[i]=x[i]-u[i][j]*x[j];
        x[i]=x[i]/u[i][i];
    }
}

float test(){
    int i,j;
    float z,k;
    k=0;
    for(i=0;i<4;i++){
        z=0;
        for(j=0;j<4;j++)
        z=z+a[i][j]*x[j];
        k=k+(z-b[i])*(z-b[i]);
    }
    k=sqrt(k);
    return k;
}

int main(){
    int i,j;
    float z,k;

    clock_t start,finish;
    double total_time;
    start=clock();

    doolittle();
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        printf("%f  ",u[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        printf("%f  ",l[i][j]);
        printf("\n");
    }
    printf("\n");

    solvedoo();
    for(i=0;i<4;i++)
    printf("%f  ",x[i]);
    printf("\n");

    z=test();
    printf("doolittle法误差为%f\n",z);

    finish=clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("运行时间为%f秒\n",total_time);

    return 0;

}