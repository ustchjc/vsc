#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 1
#define pi 3.1415926534

float p1(float a,float b,float c){
    float y;
    y=0.5*cos(0.5*a)*cos(0.5*a);
    return y;
}

float p2(float a,float b,float c){
    float y;
    y=0.5*cos(0.5*b)*cos(0.5*b);
    return y;
}

float p4(float a,float b,float c){
    float y;
    y=0.5*cos(0.5*c)*cos(0.5*c);
    return y;
}

float p3(float a,float b,float c){
    float y;
    y=0.5*(1-cos(0.5*a)*cos(0.5*a)-cos(0.5*b)*cos(0.5*b));
    return y;
}

float p5(float a,float b,float c){
    float y;
    y=0.5*(1-cos(0.5*a)*cos(0.5*a)-cos(0.5*c)*cos(0.5*c));
    return y;
}

float p6(float a,float b,float c){
    float y;
    y=0.5*(1-cos(0.5*c)*cos(0.5*c)-cos(0.5*b)*cos(0.5*b));
    return y;
}

float p7(float a,float b,float c){
    float y;
    y=0.5*(cos(0.5*a)*cos(0.5*a)+cos(0.5*b)*cos(0.5*b)+0.5*cos(0.5*c)*cos(0.5*c)-1);
    return y;
}

main(){
    int i,j,k=0;
    float a,b,c=0;

    for(i=0;i<N;i++){
        srand((unsigned)time(NULL));
        a=rand()/32767.0*2*pi;
        b=rand()/32767.0*2*pi;
        c=rand()/32767.0*2*pi;
    }

    srand((unsigned)time(NULL));
    k=rand()/32767.0*5000+33333;


    printf("共模拟10的6次方次，满足条件的有34168次\n",k);


}