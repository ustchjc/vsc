#include <stdio.h>
#include <math.h>

#define k 1.0
#define m 1.0
#define h 0.01

float ax[100]={0};
float ay[100]={0};
float az[100]={0};
float avx[100]={0};
float avy[100]={0};
float avz[100]={0};//储存状态

float force_x(float x,float y,float z){
    float f;
    f=-k*x*pow(x*x+y*y+z*z,-1.5);
    return f;
}

float force_y(float x,float y,float z){
    float f;
    f=-k*y*pow(x*x+y*y+z*z,-1.5);
    return f;
}

float force_z(float x,float y,float z){
    float f;
    f=-k*z*pow(x*x+y*y+z*z,-1.5);
    return f;
}//三个分量的力

int main(){
    float x,y,z;
    float x1,y1,z1;
    float v_x,v_y,v_z;
    int i,j;

    j=0;

    x=0.0;
    y=1.0;
    z=0.0;

    v_x=1.0;
    v_y=0.0;
    v_z=0.0;//初值

    for(i=0;i<1000;i++){
        if(i%10==0){
            ax[j]=x;
            ay[j]=y;
            az[j]=z;
            avx[j]=v_x;
            avy[j]=v_y;
            avz[j]=v_z;
            j++;
        }

        x1=x+h*v_x+force_x(x,y,z)*h*h/(2.0*m);
        y1=y+h*v_y+force_y(x,y,z)*h*h/(2.0*m);
        z1=z+h*v_z+force_z(x,y,z)*h*h/(2.0*m);

        v_x=v_x+h*(force_x(x,y,z)+force_x(x1,y1,z1))/(2.0*m);
        v_y=v_y+h*(force_y(x,y,z)+force_y(x1,y1,z1))/(2.0*m);
        v_z=v_z+h*(force_z(x,y,z)+force_z(x1,y1,z1))/(2.0*m);

        x=x1;
        y=y1;
        z=z1;
    }//迭代过程

    for(i=0;i<100;i++)
    printf("%f\n",ax[i]);//输出

}
