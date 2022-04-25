#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float a[4][4]={7.2,2.3,-4.4,0.5,1.3,6.3,-3.5,2.8,5.6,0.9,8.1,-1.3,1.5,0.4,3.7,5.9};
float b[4]={15.1,1.8,16.6,36.9};

float a_0[4][4]={7.2,2.3,-4.4,0.5,1.3,6.3,-3.5,2.8,5.6,0.9,8.1,-1.3,1.5,0.4,3.7,5.9};
float b_0[4]={15.1,1.8,16.6,36.9};

void maxswap(){
    int i,j,k;
    float t;
    for(i=0;i<4;i++){
        k=i;
        for(j=i+1;j<4;j++){
            if(abs(a[k][i])<abs(a[j][i]))
            k=j;
        }
        for(j=i;j<4;j++){
            t=a[i][j];
            a[i][j]=a[k][j];
            a[k][j]=t;
        }
        t=b[i];
        b[i]=b[k];
        b[k]=t;

        for(j=i+1;j<4;j++){
            a[j][i]=a[j][i]/a[i][i];
            for(k=i+1;k<4;k++)
            a[j][k]=a[j][k]-a[j][i]*a[i][k];
            b[j]=b[j]-a[j][i]*b[i];
        }
    }

    for(i=1;i<4;i++){
        for(j=0;j<i;j++)
        a[i][j]=0;
    }
}

void solvetri(){
    int i;
    int j;
    for(i=3;i>-1;i--){
        for(j=i+1;j<4;j++)
        b[i]=b[i]-a[i][j]*b[j];
        b[i]=b[i]/a[i][i];
    }
}

float test(){
    int i,j;
    float x,y;
    y=0;
    for(i=0;i<4;i++){
        x=0;
        for(j=0;j<4;j++)
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
    for(i=0;i<4;i++){
        for(j=0;j<4;j++)
        printf("%f  ",a[i][j]);
        printf("\n");
    }
    printf("\n");

    solvetri();
    for(i=0;i<4;i++)
    printf("%f  ",b[i]);
    printf("\n");

    x=test();
    printf("列主元法误差为%f\n",x);

    finish=clock();
    total_time=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("运行时间为%f秒\n",total_time);

    return 0;
}
