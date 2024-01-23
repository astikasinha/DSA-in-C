#include<stdio.h>
#include"astikacircularlinkedlist.h"
void concatenate(struct node **cstart1,struct node **cstart2){
    struct node *p,*q;
    p=(*cstart1)->next;
    q=(*cstart2)->next;
    (*cstart1)->next=q;
    (*cstart2)->next=p;
    traverse(*cstart2);
}
void main(){
    struct node *cstart1=NULL;
    struct node *cstart2=NULL;
    insbeg(&cstart1,1);
    insend(&cstart1,2);

    insend(&cstart1,3);
    insend(&cstart1,4);
    insend(&cstart1,5);

    traverse(cstart1);

    insbeg(&cstart2,6);
    insend(&cstart2,7);

    insend(&cstart2,8);
    insend(&cstart2,9);
    insend(&cstart2,10);

    traverse(cstart2);
    concatenate(&cstart1,&cstart2);

}