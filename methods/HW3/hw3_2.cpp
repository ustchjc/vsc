#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

float a[4][4]={4,-1,1,3,16,-2,-2,5,16,-3,-1,7,6,-4,2,9};
float b[4]={1,1,1,1};

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

float normalized(){
    float m=0;
    int i;
    for(i=0;i<4;i++){
        if(abs(x[i])>abs(m))
        m=x[i];
    }
    for(i=0;i<4;i++)
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
        printf("X_%d=(%f,%f,%f,%f)\n",k,x[0],x[1],x[2],x[3],x[4]);

        q=normalized();
        p=abs(m-q);
        m=q;
        printf("Y_%d=(%f,%f,%f,%f)\n",k,x[0],x[1],x[2],x[3],x[4]);
        printf("第%d次迭代求得特征值为%f，误差为%f。\n",k,1/m,p);

        for(i=0;i<4;i++)
        b[i]=x[i];

        k++;
    }

    return 0;
}