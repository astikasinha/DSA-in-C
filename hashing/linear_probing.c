#include<stdio.h>
int linearprobing(int table[],int ts,int x){
    int m=x%ts;//asssigning index to value to be stored
    int flag=1;
    if(table[m]==0){//if item is found in the table at first
        table[m]=x;
    }
    else{//if there is collision
        flag=0;
        for(int i=1;i<ts;i++){
            int newpos=(m+i)%ts;
            if(table[newpos]==0){
                table[newpos]=x;
                flag=1;
                break;
            }
        }
    }
    return flag;//if flag is 1 item is stored successfully

}
void main (){
    int key,ts=15;
    int n,x;
    int tablelp[15]={0};
    printf("enter number of elements to storr");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        linearprobing(tablelp,ts,x);
    }
    for(int i=0;i<=ts-1;i++){
        printf("%d",i);
        printf("--------");
    }
    printf("\n");
    for(int i=0;i<=ts-1;i++){
        printf("----");
    }
    printf("\n");
    for(int i=0;i<=ts-1;i++){
        printf("%d",tablelp[i]);
        printf(" ");
    }

}