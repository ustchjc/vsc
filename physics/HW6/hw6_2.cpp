#include <stdio.h>
#include <time.h>
#include <math.h>

#define PI 3.1415926536
#define m 1.0
#define h 0.02

int a[64];
int c[10]={0};
float position[3][64];
float speed[3][64];
float v[64];
float p[3][64];
float E;

void sample(){
    int i,j,k,t;
    float x,y;

    i=1;
    srand((unsigned)time(NULL));
    x=rand()/32.768;
    a[0]=(int)x;

    while(i<64){
        x=rand()/32.801;//抽取999个数
        k=(int)x;
        if(k>=a[i-1])
        k=k+1;

        t=0;
        for(j=0;j<i;j++){
            if(k==a[j])
            t=-1;//是否有重复数
        }

        if(t==0){
            a[i]=k;
            i++;
        }//存入a中
    }
}

void state(){
    int i,j,k;
    float x,y,z;

    for(i=0;i<64;i++){
        position[2][i]=float(a[i]%10);
        position[1][i]=float(((a[i]-a[i]%10)%100)/10);
        position[0][i]=float((a[i]-10*position[1][i]-position[2][i])/100);//三位数各位表示各点坐标
    }

    srand((unsigned)time(NULL));
    for(i=0;i<64;i++){
        x=rand()/32767.0*2.0-1.0;//速率
        y=rand()/32767.0*2.0*PI;//\phi
        z=rand()/32767.0*2.0-1.0;//cos\theta
        speed[0][i]=x*cosf(y)*sqrtf(1-z*z);
        speed[1][i]=x*sinf(y)*sqrtf(1-z*z);
        speed[2][i]=x*z;
    }
}

float force(int i,int k,int t){
    float f,r;
    int j;
    f=0;
    
    if(t==0){
        for(j=0;j<64;j++){
            if(j!=i){
                r=sqrtf((position[0][i]-position[0][j])*(position[0][i]-position[0][j])+(position[1][i]-position[1][j])*(position[1][i]-position[1][j])+(position[2][i]-position[2][j])*(position[2][i]-position[2][j]));
                f=f+48.0*(position[k][i]-position[k][j])*(pow(r,-14)-0.5*pow(r,-8));
            }
        }
    }
    else if(t==1){
        for(j=0;j<64;j++){
            if(j!=i){
                r=sqrtf((p[0][i]-p[0][j])*(p[0][i]-p[0][j])+(p[1][i]-p[1][j])*(p[1][i]-p[1][j])+(p[2][i]-p[2][j])*(p[2][i]-p[2][j]));
                f=f+48.0*(p[k][i]-p[k][j])*(pow(r,-14)-0.5*pow(r,-8));
            }
        }
    }//if用来判断用p还是position计算

    return f;
}

void verlet_position(){
    float x,y,z;
    int i;

    for(i=0;i<64;i++){
            x=position[0][i];
            y=position[1][i];
            z=position[2][i];

            x=(x+h*speed[0][i]+force(i,0,0)*h*h/(2.0*m));
            while(x>10)
            x=x-10;
            while(x<0)
            x=x+10;//周期性边界条件

            y=(y+h*speed[1][i]+force(i,1,0)*h*h/(2.0*m));
            while(y>10)
            y=y-10;
            while(y<0)
            y=y+10;

            z=(z+h*speed[2][i]+force(i,2,0)*h*h/(2.0*m));
            while(z>10)
            z=z-10;
            while(z<0)
            z=z+10;
            
            p[0][i]=x;
            p[1][i]=y;
            p[2][i]=z;
        }
}

void verlet_speed(){
    int i;
    for(i=0;i<64;i++){
            speed[0][i]=speed[0][i]+h*(force(i,0,0)+force(i,0,1))/(2.0*m);
            speed[1][i]=speed[1][i]+h*(force(i,1,0)+force(i,1,1))/(2.0*m);
            speed[2][i]=speed[2][i]+h*(force(i,2,0)+force(i,2,1))/(2.0*m);
    }
}

int main(){
    float x,y,z;
    int i,j,k;

    sample();
    state();

    for(j=0;j<500;j++){
        verlet_position();
        verlet_speed();

        for(i=0;i<64;i++){
            position[0][i]=p[0][i];
            position[1][i]=p[1][i];
            position[2][i]=p[2][i];
        }


    }

    E=0;
    for(i=0;i<64;i++){
        v[i]=sqrt(speed[0][i]*speed[0][i]+speed[1][i]*speed[1][i]+speed[2][i]*speed[2][i]);
        E=E+0.5*v[i]*v[i];
        }
    printf("energy%f\n",E);

    for(i=0;i<64;i++){
        for(j=0;j<10;j++){
            if(position[0][i]<(j+1)){
                c[j]=c[j]+1;
                break;
            }
        }
    }

    for(i=0;i<10;i++)
    printf("%d\n",c[i]);
    printf("\n");
    

    int d[10]={0};
    for(i=0;i<64;i++){
        for(j=0;j<10;j++){
            if(position[1][i]<(j+1)){
                d[j]=d[j]+1;
                break;
            }
        }
    }

    for(i=0;i<10;i++)
    printf("%d\n",d[i]);
    printf("\n");


    int e[10]={0};
    for(i=0;i<64;i++){
        for(j=0;j<10;j++){
            if(position[2][i]<(j+1)){
                e[j]=e[j]+1;
                break;
            }
        }
    }

    for(i=0;i<10;i++)
    printf("%d\n",e[i]);

    return 0;
}