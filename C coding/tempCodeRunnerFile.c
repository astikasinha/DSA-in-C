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