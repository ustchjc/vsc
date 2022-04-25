#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define PI 3.1415926536

int main(){
    int i=0;
    int j=0;
    long int k=0;
    double a[3][1000];
    double v_1x;
    double v_1y;
    double v_1z;
    double v_2x;
    double v_2y;
    double v_2z;
    double v_cx;
    double v_cy;
    double v_cz;
    double v_c1;
    double v_c2;
    double x;
    double y;
    srand((unsigned)time(NULL));

    for(k=0;k<1000;k++){
        a[0][k]=0.1*(double)(k+1);//v
        a[1][k]=rand()/32767.0*2*PI;//phi
        a[2][k]=2.0*rand()/32767.0-1;//costheta
    }//初始化数组

    for(k=0;k<1000000;k++){
        i=(int)rand()/32.767;
        j=(int)rand()/32.767;//选择碰撞的粒子
        v_1x=a[0][i]*sqrt(1-a[2][i]*a[2][i])*cosf(a[1][i]);
        v_1y=a[0][i]*sqrt(1-a[2][i]*a[2][i])*sinf(a[1][i]);
        v_1z=a[0][i]*a[2][i];
        v_2x=a[0][j]*sqrt(1-a[2][j]*a[2][j])*cosf(a[1][j]);
        v_2y=a[0][j]*sqrt(1-a[2][j]*a[2][j])*sinf(a[1][j]);
        v_2z=a[0][j]*a[2][j];;
        v_cx=(v_1x+v_2x)/2.0;
        v_cy=(v_1y+v_2y)/2.0;
        v_cz=(v_1z+v_2z)/2.0;
        v_c1=sqrt((v_1x-v_cx)*(v_1x-v_cx)+(v_1y-v_cy)*(v_1y-v_cy)+(v_1z-v_cz)*(v_1z-v_cz));
        v_c2=sqrt((v_2x-v_cx)*(v_2x-v_cx)+(v_2y-v_cy)*(v_2y-v_cy)+(v_2z-v_cz)*(v_2z-v_cz));//碰撞前参数
        x=rand()/32767.0*2.0*PI;
        y=2.0*rand()/32767.0-1;//碰撞后角度
        a[0][j]=sqrt((v_c1*sqrt(1-y*y)*cosf(x)+v_cx)*(v_c1*sqrt(1-y*y)*cosf(x)+v_cx)+(v_c1*sqrt(1-y*y)*sinf(x)+v_cy)*(v_c1*sqrt(1-y*y)*sinf(x)+v_cy)+(v_c1*y+v_cz)*(v_c1*y+v_cz));
        a[0][i]=sqrt((v_c2*sqrt(1-y*y)*cosf(x)+v_cx)*(v_c2*sqrt(1-y*y)*cosf(x)+v_cx)+(v_c2*sqrt(1-y*y)*sinf(x)+v_cy)*(v_c2*sqrt(1-y*y)*sinf(x)+v_cy)+(v_c2*y+v_cz)*(v_c2*y+v_cz));
    }

    for(k=0;k<1000;k++){
        printf("%f  ",a[0][k]);
        if(k%10==0)
        printf("\n");
    }

    for(k=0;k<200;k++){
        j=0;
        if(k%5==0){
            for(i=0;i<1000;i++){
                if(a[0][i]>k-5&&a[0][i]<k)
                j++;
            }
            printf("%d\n",j);
        }
    }

    return 0;
}