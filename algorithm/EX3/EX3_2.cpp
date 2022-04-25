
#include<bits/stdc++.h>
using namespace std;


 
int MinMerge(int b[],int k) {
	int min=0;
	for(int i=0; i<k-1; i++) {
		sort(b+i,b+k);//升序排列
		b[i+1]=b[i]+b[i+1];
		min=min+b[i+1];
	}
	return min;
}
 
int main() {
	int k;
	cin>>k;
	int a[k],b[k];
	int x;
	for(int i=0; i<k; i++) {
		cin>>x;
		a[i]=x;
		b[i]=x;
	}
	cout<<MinMerge(b,k)<<endl;
	return 0;
}
