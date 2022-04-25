#include<stdio.h>
#include<math.h>

float f_1(float x){
    double sum;
    sum=pow(x,3)-4*x*x+4*x-1;
    return sum;
}
float g_1(float x){
    double sum;
    sum=3*x*x-8*x+4;
    return sum;
}


float f_3(float x){
    double sum;
    sum=exp(x)*log(x)-x*x;
    return sum;
}
float g_3(float x){
    double sum;
    sum=exp(x)*(log(x)+1/x)-2*x;
    return sum;
}


int main(){
    float x_1;
    float x_2;
    float x_3;
    int k=0;
    x_1=2.5;
    x_2=2.7;

    for(k=0;fabs(x_2-x_1)>1e-5;k++){
        x_3=(x_1+x_2)/2;
         printf("f1第%d次二分法迭代的根为%f,函数值为%f\n",k,x_3,f_1(x_3));
        if(f_1(x_1)*f_1(x_3)<0)
        x_2=x_3;
        else
        x_1=x_3;
}

    x_1=2.6;
    x_2=2.7;
    k=0;
    for(k=0;fabs(x_2-x_1)>1e-5;k++){
        x_2=x_1-f_1(x_1)/g_1(x_1);
        printf("f1第%d次牛顿法迭代的根为%f,函数值为%f\n",k,x_2,f_1(x_2));
        x_3=x_1;
        x_1=x_2;
        x_2=x_3;
    }

    x_1=1.6;
    x_2=1.8;
    k=0;
    for(k=0;fabs(x_2-x_1)>1e-5;k++){
        x_3=(x_1+x_2)/2;
        printf("f3第%d次二分法迭代的根为%f,函数值为%f\n",k,x_3,f_3(x_3));
        if(f_3(x_1)*f_3(x_3)<0)
        x_2=x_3;
        else
        x_1=x_3;
}
    x_1=1.6;
    x_2=1.8;
    k=0;
    for(k=0;fabs(x_2-x_1)>1e-5;k++){
        x_2=x_1-f_3(x_1)/g_3(x_1);
        printf("f3第%d次牛顿法迭代的根为%f,函数值为%f\n",k,x_2,f_3(x_2));
        x_3=x_1;
        x_1=x_2;
        x_2=x_3;
    }
return 0;
}