#include<stdio.h>
#include"astikacircularlinkedlist.h"
int josephusproblem(struct node **cstart,int k){
    int c=1;
    struct node *p,*q;
    p=*cstart;
    q=NULL;
    while(p->next!=NULL){
        while(c!=k){
            q=p;
            c++;
            p=p->next;
        }
        p=p->next;
        delaft(&cstart,q);
        c=1;
    }
    return p->info;

}
void main(){
    int n,k;
    struct node *cstart;
    cstart=NULL;
    printf("enter the number to be deleted");
    scanf("%d",&k);
    insbeg(&cstart,1);
    for(int i=2;i<=101;i++){
        insend(&cstart,i);
    }
    n=josephusproblem(&cstart,k);
    printf("%d",k);
}