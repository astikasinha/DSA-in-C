#include<stdio.h>
#define true 1
#define false 0
void primefactor(int n)
{
    int k[100];
    int a[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (a[j] == j)
                {
                    a[j] = i;
                }
            }
        }
    }
    i=0;
    while (n != 1)
    {
        k[i]=a[n];
        n = n / a[n];
        i++;
    }
    return k;
}
int isprime(int num){
    int c=0;
    for(int i=2;i*i<num;i++){
        if(num%i==0){
            c++;
        }
    }
    if(c>0){
        return true;
    }
    else{
        return false;
    }
}
void main(){
    int num;
    int h[100];
    printf("enter the number");
    scanf("%d",&num);
    if(isprime(num)){
        return num-1;
    }
    else{
        h=primefactor(num);
    }
    int l=sizeof(h);
    if(l==2){
        if(isprime(h[0]) && isprime(h[1])){
            m=h[0]-1;
            n=h[1]-1;
            return m*n;
        }
        else{
            return 1;
        }
    }
    if(l>2){
        for(i=0;i<l;i++){
            v=()
        }
    }
}
