#include<stdio.h>
#include<stdlib.h>


int a[10000000];

int partition(int arr[], int low, int high){
    int key;
    key = arr[low];
    while(low<high){
        while(low <high && arr[high]>= key )
            high--;
        if(low<high)
            arr[low++] = arr[high];
        while( low<high && arr[low]<=key )
            low++;
        if(low<high)
            arr[high--] = arr[low];
    }
    arr[low] = key;
    return low;
}

void quick_sort(int arr[], int start, int end){
    int pos;
    if (start<end){
        pos = partition(arr, start, end);
        quick_sort(arr,start,pos-1);
        quick_sort(arr,pos+1,end);
    }
    return;
}

int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%ld",&a[i]);

        quick_sort(a,0,n-1);
         printf("%d\n",a[m-1]);
    
    return 0;
}
