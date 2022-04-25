#include<stdio.h>

int main(){
    int N;
    int a[1000000];
    int i,j;
    int m,n;
    long int x;

    scanf("%d",&N);
    for(i=0;i<N;i++)
        scanf("%d",&a[i]);
    
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            m=a[i];
            n=a[j];
            if(m<n)
            x++;
        }
    }
    printf("%d\n",x%10000007);
    
    return 0;
}