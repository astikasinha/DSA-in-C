#include<stdio.h>
#include"astikalinkedlist.h"
int reverse(struct node **llist) {
    struct node *p,*c,*n;
    p=NULL;
    c=(*llist);
    n=(*llist)->next;
    while(c!=NULL){
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL){
            n=n->next;
        }
    }
    (*llist)=p;
    return llist;
}
int main(){
    struct node *start;
    start=NULL;
    insertbegin(&start,100);
    insertend(&start,200);
    insertend(&start,300);
    insertend(&start,400);
    insertend(&start,500);

    traverse(start);
    printf("after reversing\n");

    reverse(&start);
    traverse(start);
}
