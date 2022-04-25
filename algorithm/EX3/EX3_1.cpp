#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch<='9'&&ch>='0')s=s*10+ch-'0',ch=getchar();
    return s*w;
}

const int sea=1e5+7;
struct hit{int x,y;}a[sea];
int n,lb,b[sea],c[sea];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read(),b[i]=a[i].y;
    sort(b+1,b+n+1); lb=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++) a[i].y=lower_bound(b+1,b+lb+1,a[i].y)-b;
    sort(a+1,a+n+1,cmp);
    int ans=0;



}