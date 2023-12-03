#include<stdio.h>
int primesieve(int size)
{
    int prime[101] = {0};
    for (int i = 2; i <= size; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= size; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    int z;
    for (int i = 2; i <= size; i++)
    {
        if (prime[i] == 0)
        {
            z=i;
        }
    }
    return z;
}
int divisionhash(int keys[],int s,int n){
    int M = s;
    int location[100];
    for(int i = 0; i < n; i ++)  
    {  
        location[i] = (keys[i] % M);  
    }  
    printf("\nThe indexes of the values in the Hash Table: ");  
    for(int i = 0; i < n; i++)  
    {  
        printf("%d ", location[i]);  
    }  
}
int main(){
    int i,size,keys[100],s,n;
    printf("enter the number of size of the table");
    scanf("%d",&size);
    s=primesieve(size);
    printf("enter the number of keys");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&keys[i]);
    }
    divisionhash(keys,s,n);
}