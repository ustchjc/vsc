#include<stdio.h>

int a[5][10000000];
int k;
int N;

int equal(int i,int j){
    int m;
    int s=0;
    for(m=0;m<5;m++){
        if(a[m][i]==a[m][j])
            s++;
    }
    if(s==5)
    return 1;
    else
    return 0;
}

int yesorno(int i,int j){
    int m,n,p,q;
    for(m=i-1;m<j-1;m++){
        for(n=m+1;n<j;n++){
            if(equal(m,n)==1)
                p++;
        }
        if(p==0)
            q++;
    }
    if(q==k-1)
        return 1;
    else
        return 0;
}

int main(){
    int i;
    int j;
    scanf("%d%d",&N,&k);
    for(i=0;i<N;i++){
        for(j=0;j<5;j++)
        scanf("%d",&a[j][i]);
    }

    
}