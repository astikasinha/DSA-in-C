#include<stdio.h>
#include<math.h>
int midsquarehash(int keys[],int ksize,int tsize){
    int M = tsize;
    int n=0;
    int location[100];
    for(int i = 0; i < ksize; i ++)  {  
        int x=keys[i];
        while(x!=0){
        x=x/10;
        n=n+1;
        }
        int d=((2*n)-2)/2;
        int f=((keys[i]*keys[i])/(pow(10,d)));
        location[i] = (f % M);  
    }  
    printf("\nThe indexes of the values in the Hash Table: ");  
    for(int i = 0; i < ksize; i++)  
    {  
        printf("%d ", location[i]);  
    }  
}
int main(){
    int i,tsize,ksize,keys[100];
    printf("enter the number of size of the table");
    scanf("%d",&tsize);
     printf("enter the number of size of the keys");
    scanf("%d",&ksize);
    printf("enter the keys");
    for(i=0;i<ksize;i++){
        scanf("%d",&keys[i]);
    }
    midsquarehash(keys,ksize,tsize);
}
