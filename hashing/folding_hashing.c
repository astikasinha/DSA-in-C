#include<stdio.h>
#include<math.h>
int foldinghash(int keys[],int ksize,int tsize){
    int M = tsize;
    int c=0,r;
    int location[ksize];
    while(M!=0){
        c++;
        M=M/10;
    }
    int d=c-1;
    for(int i = 0; i < ksize; i ++)  {
        int sum=0;  
        int x=keys[i];
        while(x!=0){
            r=(x%(int)(pow(10,d)));
            sum=sum+r;
            x=(x/(int)(pow(10,d)));
        }
        location[i] = (sum % tsize);  
    }  
    printf("\nThe indexes of the values in the Hash Table: ");  
    for(int i = 0; i < ksize; i++)  
    {  
        printf("%d ", location[i]);  
    }  
}
int main(){
    int i,tsize,ksize,keys[ksize];
    printf("enter the number of size of the table");
    scanf("%d",&tsize);
     printf("enter the number of size of the keys");
    scanf("%d",&ksize);
    printf("enter the keys");
    for(i=0;i<ksize;i++){
        scanf("%d",&keys[i]);
    }
    foldinghash(keys,ksize,tsize);
}
