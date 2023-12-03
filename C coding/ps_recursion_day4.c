//whether a number is palindrome or not
#include<stdio.h>
int rev(int n,int z){
    if(n==0){
        return z;
    }
    z=(z*10)+(n%10);
    return rev(n/10,z);
}
int main(){
    int n,z;
    printf("enter the number");
    scanf("%d",&n);
    z=rev(n,0);
    if(n==z){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
}

//mean and median of 5 numbers
#include<stdio.h>  
void swap (int * p,int * q){  
   int t ;   
   t=*p;   
   *p=*q ;   
   *q=t ;  
}  
void sort (int a[ ] ,int n){   
   int i,j,temp;   
   for (i=0 ;i<n-1;i++){  
      for (j=0;j<n-i-1;j++) {  
         if (a[j]>a[j+1])  
            swap ( & a [ j ] , & a [ j + 1 ] ) ;  
      }  
   }  
}  
int main(int a[],int n){
    int sum,i;
    for(i=0;i<n;i++){
        sum=sum+a[i];
    }
    return(sum,n);
}
int main ( ) {  
   int a[10],n,i;
   printf("enter the elements of arraY");
   scanf("%d",&n);
   printf("enter the elements of array");
   for(i=0;i<n;i++){
    scanf("%d",&a[i]);
   }   
   sort ( a , n ) ;   
   n = ( n + 1 ) / 2 - 1 ;      // -1 as array indexing in C starts from 0  
   printf ( " Median = % d " , a [ n ] ) ; 
   int z=mean(a,n);
   printf("mean",z); 
   return 0 ;  
}  

//binary exponentiation
#include<stdio.h>
long long power(int a,int n){
    if(n==0){
        return 1;
    }
    else{
        long long p=power(a,n/2);
        if(n%2==0){
            return(p*p);
        }
        else{
            return(p*p*a);
        }
    }
}
void main(){
    int n,a;
    printf("enterr the number");
    scanf("%d",&a);
    printf("enter the power");
    scanf("%d",&n);
    long long z;
    z=power(a,n);
    printf("%d",z);

    
}


//modular exponentiation
#include<stdio.h>
#define m 1000000007
long long power(int a,int n){
    if(n==0){
        return 1;
    }
    else{
        long long p=power(a,n/2)%m;
        if(n%2==0){
            return(p*p)%m;
        }
        else{
            return(((p*p)%m)*a)%m;
        }
    }
}
int main(){
    int n,a;
    printf("enterr the number");
    scanf("%d",&a);
    printf("enter the power");
    scanf("%d",&n);
    long long z;
    z=power(a,n);
    printf("%d",z);
}


//armstrong number
#include<stdio.h>
#include<math.h>
int power(int t,int c){
    if(c==0){
        return 1;
    }
    else{
        return power(t,c-1);
    }
}
int armstrong(int n,int c){
    int t,sum=0,z;
    while(n>0){
        t=n%10;
        z=power(t,c);
        sum=sum+z;
        n=n/10;
    }
    return sum;
}
int order(int n){
    int c;
    while(n>0){
        c++;
        n=n/10;
    }
    return c;
}

int main(){
    int n,z,k,x;
    x=n;
    printf("enter the number");
    scanf("%d",&n);
    k=order(n);
    z=armstrong(n,k);
    if(x==z){
        printf("armstrong");
    }
    else{
        printf("not armstrong");
    }

}

//clockwise rotation of matrix
#include<stdio.h>
int clockwise(int *a[][],int m,int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=m-1;j<=0;j--){
            return a[i][j];
        }
    }

}
int main(){
    int a[50][50],b[50][50],m,n,i,j;
    printf("enter the number of rows and columns of matrix A");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix A");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }

b[50][50] = clockwise(a,m,n);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            printf("%d",b[i][j]);
        }
    }
}



//clockwise rotation of ninety degrees
#include<stdio.h>
void main(){
    int a[50][50],m,n,i,j;
    printf("enter the number of rows and columns of matrix A");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix A");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=0;i<n;i++){
        for(j=m-1;j>=0;j--){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    
}


//anticlockwise rotation of ninety degrees
#include<stdio.h>
void main(){
    int a[50][50],m,n,i,j;
    printf("enter the number of rows and columns of matrix A");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix A");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=n-1;i>=0;i--){
        for(j=0;j<m;j++){
            printf("%d ",a[j][i]);
        }
        printf("\n");
    }
    
}

//anticlockwise or clockwise rotation in 180 degrees
#include<stdio.h>
void main(){
    int a[50][50],m,n,i,j;
    printf("enter the number of rows and columns of matrix A");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix A");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(i=m-1;i>=0;i--){
        for(j=n-1;j>=0;j--){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    
}


