#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 20
#define e 2.71828

float X[N+1];
float Y[N+1];
float h[N];
float lambda[N];
float mu[N];
float d[N];
float M[N+1];
float m[N+1];

float a[N];
float b[N];
float c[N];
float u[N];
float v[N];
float F[N];
float y[N];
float x[N+1];

float f(float x){
    float y;
    y=(x+sinf(2*x))/(1+pow(e,-x));
    return y;
}

void sample(){
    int i,j,k;
    float s;

    srand((unsigned)time(NULL));
    X[0]=-2;
    X[N]=4;

    for(i=1;i<N;i++){
        X[i]=rand()/32767.0*6.0-2.0;
    }

    for(i=0;i<N-1;i++){
        s=5;
        for(j=i;j<N;j++){
            if(X[j]<s){
                s=X[j];
                k=j;
            }
        }
        X[k]=X[i];
        X[i]=s;
    }
}

void value(){
    int i;
    for(i=0;i<N+1;i++){
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
    M[0]=-0.167157;
    M[N]=0.784373;
}

void solve(){
    int i,j;
    
    for(i=0;i<N;i++){
        a[i]=2;
        b[i]=lambda[i];
        c[i]=mu[i];
        F[i]=d[i];
    }
    a[0]=0;
    F[0]=0;
    F[1]=d[i]-mu[1]*M[0];
    F[N-1]=d[N-1]-lambda[N-1]*M[N];
    v[0]=0;
    y[0]=0;
    x[N]=0;

    for(i=1;i<N;i++){
        u[i]=a[i]-c[i]*v[i-1];
        v[i]=b[i]/u[i];
        y[i]=(F[i]-c[i]*y[i-1])/u[i];
    }
    for(i=N-1;i>0;i--)
        x[i]=y[i]-v[i]*x[i+1];
}

int main(){
    int i;

    sample();
    for(i=0;i<=N;i++)
    printf("%f\n",X[i]);

    printf("\n\n");

    value();
    solve();

    for(i=1;i<N;i++)
    M[i]=x[i];

    for(i=0;i<=N;i++)
    printf("%f\n",M[i]);

    return 0;

}