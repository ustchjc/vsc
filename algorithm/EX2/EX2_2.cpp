#include <stdio.h>
#include <string.h>
#include<string>
#include<iostream>
using namespace std;

string a[100000];
int b[100000];

int i=0;

int find(string x){
    int k=-1;
    int j;
    for(j=0;j<i+1;j++){
        if(x==a[j]){
            k=b[j];
            break;
        }
    }

    return k;
}

int main(){
    int j,k;
    string c;

    cin>>c;
    while(c!="EXIT"){
        if(c=="INSERT"){
            cin>>j;
            b[i]=j;
            cin>>c;
            a[i]=c;
            i++;
        }
        else if(c=="FIND"){
            cin>>c;
            k=find(c);
            printf("%d\n",k);
        }

        cin>>c;
    }

    return 0;
}