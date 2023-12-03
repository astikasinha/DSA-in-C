#include<stdio.h>
void Arrayreversal(int a[],int n){
    int i=0,j=n-1,t;
    while(i<j){
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i=i+1;
        j=j-1;
    }
}
void printarray(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}
void main(){
    int a[10],i,n,c[10];
    printf("enter the array number of elements of array");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(i=0;i<=n;i++){
        scanf("%d",&a[i]);
    }
    Arrayreversal(a[100],n);
    printarray(a[100],n);
}