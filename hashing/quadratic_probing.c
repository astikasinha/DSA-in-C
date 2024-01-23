#include<stdio.h>
int quadraticprobing(int table[],int ts,int x){
    int m=x%ts;//asssigning index to value to be stored
    int flag=1;
    if(table[m]==0){//if item is found in the table at first
        table[m]=x;
    }
    else{//if there is collision
        flag=0;
        int i=1;
        while(flag==0){
            int newpos=(m+i*i)%ts;
            i++;
            if(table[newpos]==0){
                table[newpos]=x;
                flag=1;
            }
        }
    }
    return flag;//if flag is 1 item is stored successfully

}
int doublehashing(int table[],int ts,int x){
    int h=x%ts;
    int flag=1;
    if(table[h]==0){
        table[h]=x;
    }
    else{
        flag=0;
        int hdash=(2*x-7)%ts;
        int i=1;
        while(flag==0){
            int newpos=(h+i*hdash)%ts;
            i++;
            if(table[newpos]==0){
                table[newpos]=x;
                flag=1;
            }
        }
    }
}
void main (){
    int key,ts=15;
    int n,x;
    int tablelp[15]={0};
    printf("enter number of elements to storr");
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        quadraticprobing(tablelp,ts,x);
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