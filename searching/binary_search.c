#include<stdio.h>
int binarysearch(int a[],int n,int key){
    int low=0,high=n-1;
    int mid;
    while(low<=high){
        mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else{
            if(key<a[mid]){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
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
    b=binarysearch(a,n,key);
    if(b==-1){
        printf("element not found");
    }
    else{
        printf("element found at %d index",b);
    }
}
