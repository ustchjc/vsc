#include <stdio.h>
#include <math.h>

#define N 20

float X[N+1];
float Y[N+1];
float h[N];
float lambda[N];
float mu[N];
float d[N];
float M[N+1];

float a[N+2];
float b[N+2];
float c[N+2];
float u[N+2];
float v[N+2];
float F[N+2];
float y[N+2];
float x[N+3];

float f(float x){
    float y;
    y=x/(x*x+x+1.0);
    return y;
}

void value(){
    int i;
    for(i=0;i<N+1;i++){
        X[i]=-2.0+0.2*i;
        Y[i]=f(X[i]);
    }
    for(i=0;i<N;i++){
        h[i]=X[i+1]-X[i];
        if(i==0){
            lambda[i]=0;
            d[i]=0;
        }
        else{
            lambda[i]=h[i]/(h[i]+h[i-1]);
            d[i]=6.0*((Y[i+1]-Y[i])/h[i]-(Y[i]-Y[i-1])/h[i-1])/(h[i]+h[i-1]);
        }
        mu[i]=1.0-lambda[i];
    }
}

void solve(){
    int i,j;
    
    for(i=0;i<N+1;i++){
        a[i]=2;
        b[i]=lambda[i-1];
        c[i]=mu[i];
        F[i]=d[i-1];
    }
    a[0]=0;
    F[0]=0;
    b[1]=1;
    c[N]=1;
    a[N+1]=2;
    F[1]=6.0*((Y[1]-Y[0])/h[0]-1.0)/h[0];
    F[N+1]=6.0*(-(Y[N]-Y[N-1])/h[N-1]+17.0/49.0)/h[N-1];
    v[0]=0;
    y[0]=0;
    x[N+2]=0;

    for(i=1;i<N+2;i++){
        u[i]=a[i]-c[i]*v[i-1];
        v[i]=b[i]/u[i];
        y[i]=(F[i]-c[i]*y[i-1])/u[i];
    }
    for(i=N+1;i>0;i--)
        x[i]=y[i]-v[i]*x[i+1];
}

int main(){
    int i;

    value();
    solve();

    for(i=1;i<=N+1;i++)
    printf("%f\n",x[i]);

    return 0;

}