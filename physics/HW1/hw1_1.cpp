#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i;
    int k;
    int a=0;
    int b=0;
    int c=0;
    int d=0;
    int e=0;
    int f=0;
    int g=0;
    int h=0;
    double x;
    double y;
    double z=0.0;
    srand((unsigned)time(NULL));
    for(k=0;k<10000;k++){
        x=rand()/32767.0;
        y=-log(1-x);
        z=z+pow(y,1.5);
        //printf("%f\n",y);
        if(y<1) a++;
        else if(y<2) b++;
        else if(y<3) c++;
        else if(y<4) d++;
        else if(y<5) e++;
        else if(y<6) f++;
        else if(y<7) g++;
        else h++;
    }
    printf("积分结果为%f\n",z/10000.0);+
    printf("%d  %d  %d  %d  %d  %d  %d  %d\n",a,b,c,d,e,f,g,h);
}