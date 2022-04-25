#include <stdio.h>
#include <math.h>

int a[2][1000000]={-1};

int judge(int m,int n){
    int i;
    int j=0;
    for(i=0;a[0][i]!=-1;i++){
        if(((m>a[0][i])&&(m<a[1][i]))||((n>a[0][i])&&(n<a[1][i]))){
            j=-1;
            break;
        }
    }

    return j;
}

int main(){
    int m,n;
    int i,j;
    int N;
    int k=0;
    scanf("%d",&N);

    for(i=0;i<N;i++){
        scanf("%d%d",&m,&n);
        j=judge(m,n);
        printf("%d\n",j);

        if(j==0){
            a[0][k]=m;
            a[1][k]=n;
        }
    }

    return 0;

}