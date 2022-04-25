#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
using namespace std;

int a[2000000];

int i=0;

int find(int x){
    int m,n,j;
    m=1000000000;
    for(j=0;j<i+1;j++){
        if(a[j]<=x){
        n=x-a[j];
        if(n<m)
        m=n;}
    }

    return x-m;
}

int main(){
    int j,k;

    string c;
    int t;
  
    
    cin>>c;
    while(c!="EXIT"){
        if(c=="INSERT"){
            cin>>t;
            a[i]=t;
            i++;
        }
        else if(c=="FIND"){
            cin>>j;
            k=find(j);
            printf("%d\n",k);
        }

        cin>>c;
    }

    return 0;

}

