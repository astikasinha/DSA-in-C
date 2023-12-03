/*#include<stdio.h>
#define m 100
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
            return(((p*a)%m)*p)%m;
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
}*/

#include<stdio.h>
long long MatrixMultiply(long long F[2][2],long long M[2][2]){
    long long a=F[0][0]*M[0][0]+F[0][1]*M[1][0];
    long long b=F[0][0]*M[0][1]+F[0][1]*M[1][1];
    long long c=F[1][0]*M[0][0]+F[1][1]*M[1][0];
    long long d=F[1][0]*M[0][1]+F[1][1]*M[1][1];
    F[0][0]=a;
    F[0][1]=b;
    F[1][0]=c;
    F[1][1]=d;
}
void power(long long F[2][2],long long n){
    if(n==0 || n==1)
    return;
    long long M[2][2]={1,1,1,0};
    power(F,n/2);
    MatrixMultiply(F,F);
    if(n%2!=0){
        MatrixMultiply(F,M);
    }
}
long long Fib(long long n){
    long long F[2][2]={1,1,1,0};
    if(n==0)
    return 0;
    power(F,n-1);
    return F[0][0];
}
long long main(){
    long long n;
    printf("enter the number ");
    scanf("%lld",&n);
    printf("%lld",Fib(n));
}