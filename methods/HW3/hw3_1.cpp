#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float a[5][5]={1.0/9.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/8.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/7.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/6.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1.0/5.0,1.0/4.0,1.0/3.0,1.0/2.0,1};
float b[5]={1,1,1,1,1};

float l[5][5]={0};
float u[5][5]={0};
float x[5]={0};
float y[5]={0};

void doolittle(){
    int i,j,k,r;
    for(k=0;k<5;k++){
        for(j=k;j<5;j++){
            u[k][j]=a[k][j];
                for(r=0;r<k;r++)
                u[k][j]=u[k][j]-l[k][r]*u[r][j];
        }
        for(i=k+1;i<5;i++){
            l[i][k]=a[i][k];
            for(r=0;r<k;r++)
            l[i][k]=l[i][k]-l[i][r]*u[r][k];
            l[i][k]=l[i][k]/u[k][k];
        }
    }
}

void solvedoo(){
    int i,j;
    for(i=0;i<5;i++){
        y[i]=b[i];
        for(j=0;j<i;j++)
        y[i]=y[i]-l[i][j]*y[j];
    }
    for(i=4;i>-1;i--){
        x[i]=y[i];
        for(j=i+1;j<5;j++)
        x[i]=x[i]-u[i][j]*x[j];
        x[i]=x[i]/u[i][i];
    }
}

float normalized(){
    float m=0;
    int i;
    for(i=0;i<5;i++){
        if(abs(x[i])>abs(m))
        m=x[i];
    }
    for(i=0;i<5;i++)
    x[i]=x[i]/m;

    return m;
}

int main(){
    int i,j,k;
    k=1;
    float m,n,p,q;
    p=1;
    m=1;

    doolittle();

    while(p>pow(10,-5)){

        solvedoo();
        printf("X_%d=(%f,%f,%f,%f,%f)\n",k,x[0],x[1],x[2],x[3],x[4],x[5]);

        q=normalized();
        p=abs(m-q);
        m=q;
        printf("Y_%d=(%f,%f,%f,%f,%f)\n",k,x[0],x[1],x[2],x[3],x[4],x[5]);
        printf("第%d次迭代求得特征值为%f，误差为%f。\n",k,1/m,p);

        for(i=0;i<5;i++)
        b[i]=x[i];

        k++;
    }

    return 0;
}