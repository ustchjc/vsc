#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float a[5][5]={1.0/9.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1};
float b[5]={1,1,1,1,1};

float a_0[5][5]={1.0/9.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1};
float b_0[5]={1,1,1,1,1};

void maxswap(){
    int i,j,k;
    float t;
    for(i=0;i<5;i++){
        k=i;
        for(j=i+1;j<5;j++){
            if(abs(a[k][i])<abs(a[j][i]))
            k=j;
        }
        for(j=i;j<5;j++){
            t=a[i][j];
            a[i][j]=a[k][j];
            a[k][j]=t;
        }
        t=b[i];
        b[i]=b[k];
        b[k]=t;

        for(j=i+1;j<5;j++){
            a[j][i]=a[j][i]/a[i][i];
            for(k=i+1;k<5;k++)
            a[j][k]=a[j][k]-a[j][i]*a[i][k];
            b[j]=b[j]-a[j][i]*b[i];
        }
    }

    for(i=1;i<5;i++){
        for(j=0;j<i;j++)
        a[i][j]=0;
    }
}

void solvetri(){
    int i;
    int j;
    for(i=4;i>-1;i--){
        for(j=i+1;j<5;j++)
        b[i]=b[i]-a[i][j]*b[j];
        b[i]=b[i]/a[i][i];
    }
}

float test(){
    int i,j;
    float x,y;
    y=0;
    for(i=0;i<5;i++){
        x=0;
        for(j=0;j<5;j++)
        x=x+a_0[i][j]*b[j];
        y=y+(x-b_0[i])*(x-b_0[i]);
    }
    y=sqrt(y);
    return y;
}

int main(){
    int i,j;
    float x,y;

    clock_t start,finish;
    double total_time;
    start=clock();
    
    maxswap();
    for(i=0;i<5;i++){
        for(j=0;j<5;j++)
        printf("%f  ",a[i][j]);
        printf("\n");
    }
    printf("\n");
    for(i=0;i<5;i++)
    printf("%f  ",b[i]);
    printf("\n");


    solvetri();
    for(i=0;i<5;i++)
    printf("%f  ",b[i]);
    printf("\n");

    x=test();
    printf("列主元法误差为%f\n",x);

    finish=clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("运行时间为%f秒\n",total_time);

    return 0;
}
