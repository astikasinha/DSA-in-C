#include<stdio.h>
int linearsearch(int a[],int n,int key){
    for(int i=0;i<n-1;i++){
        if(a[i]==key){
            return i;
        }
    }
    return -1;

}
void main(){
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
    b=linearsearch(a,n,key);
    if(b==-1){
        printf("element not found");
    }
    else{
        printf("element found at %d index",b);
    }
}
