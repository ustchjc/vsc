#include<stdio.h>

int mian(){
    int T;
    int N;
    int i;
    int j;
    int m;
    int n;
    int s;
    int a[100000];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        s=0;
        scanf("%d",&N);
        for(j=0;j<N;j++)
        scanf("%d",&a[j]);

        for(m=0;m<N;m++){
            for(n=0;n<N;n++){
                if(a[m]==a[n])
                s++;
                else
                s--;
            }
            if(s>0){
                printf("%d\n",s);
            }
        }
    if(s<=0)
    printf("-1\n");
    }

    return 0;
}