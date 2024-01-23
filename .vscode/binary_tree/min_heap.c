#include<stdio.h>
#include<stdlib.h>
void minheapify(int a[],int i,int n){
    while((2*i+1)<=n){
        int l=2*i+1;
        int r=l+1;
        int t;
        int max=l;
        if(r<=n){
            if(a[r]<a[l]){
                max=r;
            }
        }
        if(a[max]<a[i]){
            t=a[max];
            a[max]=a[i];
            a[i]=t;
        }
        else{
            break;
        }
        i=max;
    }
}
void buildminheap(int a[],int n){
    int i;
    for(i=(n-1)/2;i>=0;i--){
        minheapify(a,i,n);
    }
}
void main(){
    int n,a[100],i;
    printf("enter the number of elements of array");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    buildminheap(a,n);
     for(int j=0;j<n;j++){
        printf("%d ",a[j]);
    }

}