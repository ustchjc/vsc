#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int i=0;
    int j=0;
    int k=0;
    int m=0;
    long int n=0;
    int a[10000]={0};
    double x;
    srand((unsigned)time(NULL));
    for(n=0;n<100000;n++){
        x=rand()/32767.0*10000.0;
        i=(int)x;
        j=a[i];
        if(j==0)
        a[i]=1;
        else if(j==1)
        a[i]=0;
        if(n%500==0){
            k=0;
            for(m=0;m<10000;m++){
                if(a[m]==1)
                k++;
            }
            printf("已进行%d次变化，有个%d粒子在右边。\n",n,k);
        }
    }
    return 0;
}