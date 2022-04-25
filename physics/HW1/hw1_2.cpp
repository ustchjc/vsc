#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#define pi 3.1415926536

int main(){
    int k;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    int i=0;
    int j=0;
    double x;
    double y;
    double z=0.0;
    srand((unsigned)time(NULL));
    for(k=0;k<10000;k++){
        x=rand()/(2.0*32767.0+1);
        y=tanf(pi*x);
        z=z+pi*pow(y,0.5)/2;
        //printf("%f\n",y);
        if(y<1) a++;
        else if(y<2) b++;
        else if(y<3) c++;
        else if(y<4) d++;
        else if(y<5) e++;
        else if(y<6) f++;
        else if(y<7) g++;
        else if(y<8) h++;
        else if(y<9) i++;
        else j++;
    }
    printf("积分结果为%f\n",z/10000.0);
    printf("%d  %d  %d  %d  %d  %d  %d  %d  %d  %d\n",a,b,c,d,e,f,g,h,i,j);
}