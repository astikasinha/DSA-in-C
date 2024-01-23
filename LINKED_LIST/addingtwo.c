#include<stdio.h>
#include"astikalinkedlist.h"
#include"astikastack1.h"
void reverselinkedlist(struct node **list) {
    struct node *current, *prev, *next;
    current = *list;
    prev = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *list = prev;// Update the list pointer
}
void add(struct node **poly1,struct node **poly2){
    reverselinkedlist(poly1);
    reverselinkedlist(poly2);
    struct node *p,*q,*poly3;
    poly3=NULL;
    p=*poly1;
    q=*poly2;
    int carry=0;
    while(p!=NULL && q!=NULL){
        int total=p->info+q->info+carry;
        int sum=total%10;
        carry=total/10;
        p=p->next;
        q=q->next;
        insertbegin(&poly3,sum);
    }
    while(p!=NULL){
        int total=p->info+carry;
        int sum=total%10;
        carry=total/10;
        insertbegin(&poly3,sum);
        p=p->next;
    }
    while(q!=NULL){
        int total=q->info+carry;
        int sum=total%10;
        carry=total/10;
        insertbegin(&poly3,sum);
        q=q->next;
    }
    if(carry==1){
        insertbegin(&poly3,carry);
    }
    traverse(poly3);
}
void main(){
    struct node *poly1,*poly2;
    poly1=NULL;
    poly2=NULL;
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
    insertbegin(&poly1,9);
   
    traverse(poly1);
    printf("\n");
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);
    insertbegin(&poly2,9);

    traverse(poly2);
    printf("\n");

    add(&poly1,&poly2);
}
