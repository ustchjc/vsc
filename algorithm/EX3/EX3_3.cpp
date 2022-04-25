#include <iostream>
#include <algorithm>
#define N 1002
using namespace std;

int f[N];
int w[N];
int v[N];
int s[N];

int main(){
    int n,W;
    int i,j,k;
    cin>>n>>W;

    for(i=1;i<=n;i++){
        cin>>w[i]>>v[i]>>s[i];
    }

    for(i=1;i<=n;i++){
        for(j=W;j>w[i];j--){
            for(k=0;k<=s[i]&&k*w[i]<=j;k++)
            f[j]=max(f[j],f[j-k*w[i]]+k*v[i]);
        }
    }

    cout<<f[W]<<endl;
    
    return 0;
}