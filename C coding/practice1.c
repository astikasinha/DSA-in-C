//traversing array elements
#include<stdio.h>
void printarray(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void main(){
    int n,a[10],i;
    printf("enter the number of elements in array");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printarray(a,n);
}

//insert an element in an array
#include<stdio.h>
void insertarray(int a[],int n){
    int i,pos,num;
    printf("enter the position in which element is to ber inserted");
    scanf("%d",&pos);
    printf("enter the element to be inserted");
    scanf("%d",&num);
    n++;
    for(i=n-1;i>=pos;i--){
        a[i]=a[i-1];
    }
    a[pos-1]=num;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void main(){
    int n,a[10],i;
    printf("enter the number of elements in array");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    insertarray(a,n);
}

//delete an element in a sorted array
#include<stdio.h>
int binarysearch(int a[],int low,int high,int num){
    int mid=(high+low)/2;
    if(num==a[mid]){
        return mid;
    }
    if(num>a[mid]){
        return binarysearch(a,(mid+1),high,num);
    }
    if(num<a[mid]){
        return binarysearch(a,low,(mid-1),num);
    }

}
void deletesortedarray(int a[],int n,int num){
    int i,pos;
    pos=binarysearch(a,0,(n-1),num);
    for(i=pos;i<n-1;i++){
        a[i]=a[i+1];
    }
    n--;
    for(i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void main(){
    int n,a[10],i,num;
    printf("enter the number of elements in array");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("enter the element to be deleted");
    scanf("%d",&num);
    deletesortedarray(a,n,num);
}

//missing number in array
#include<stdio.h>
int missingnumber(int a[],int n){
    int total=((n+1)*(n+2))/2;
    for(int i=0;i<n;i++){
        total-=a[i];
    }
    return total;
}
int main(){
    int n,z;
    int a[]={1,2,3,4,6,7,8,9,10};
    n=sizeof(a)/sizeof(a[0]);
    z=missingnumber(a,n);
    printf("%d",z);
}

//missing number in array
#include<stdio.h>
int repeatingnumber(int a[],int n){
    int temp[n];
    temp[n]={ };
    int repeating_number,non_repeating_number;
    for(int i=0;i<n;i++){
        temp[a[i]-1]++;
    }
    for(int i=0;i<n;i++){
        if(temp[a[i]-1]>1){
            repeating_number=a[i];
            printf("repeating number is %d",repeating_number);
        }
        else{
            non_repeating_number=a[i];
            printf("non repeating number is %d",non_repeating_number);
        }
    }
}
void main(){
    int n;
    int a[]={3,1,2,3};
    n=sizeof(a)/sizeof(a[0]);
    repeatingnumber(a,n);
}