#include<stdio.h>
#include<math.h>
int indexsequentialsearch(int a[],int n,int key){
    int bs=sqrt(n);
    int x=0;
    int start,end;
    int index[n/bs];
    for(int i=0;i<n;i=i+bs){
        index[x++]=i;
    }
    if(key<a[index[0]]||key>a[index[x-1]]){
        return -1;
    }
    else{
        for(int i=0;i<x;i++){
            if(key<=a[index[i]]){
                start=index[i-1];
                end=start+bs;
                break;
            }
        }
        for(int i=0;i<end;i++){
            int flag=-1;
            if(a[i]==key){
                flag=i;
                break;
            }
        }
    }
}
int main(){
    int n,a[100];
    int b;
    printf("enter the elements in array");
    scanf("%d",&n);
    printf("enter the elemnts of array");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int key;
    printf("enter th elements to be searched");
    scanf("%d",&key);
    b=indexsequentialsearch(a,n,key);
    if(b==-1){
        printf("element not found");
    }
    else{
        printf("element found at %d index",b);
    }
}

