#include<stdio.h>
#include"astikalinkedlist.h"
void lastnode(struct node *start,int k){
    struct node *p,*q;
    p=start;
    int c=1;
    while(c<=k){
        c++;
        p=p->next;
    }
    q=start;
    while(p->next!=NULL){
        q=q->next;
        p=p->next;
    }
    if(q==start){
        deletebegin(&start);
    }
    else{
        deleteNode(&start,q);
    }
    traverse(start);
}
void split(struct node **start1) {
    struct node *t, *r, *start2;
    start2 = NULL;
    t = *start1;
    r = (*start1)->next;

    // Ensure there are at least two nodes before attempting to split
    if (r == NULL || r->next == NULL) {
        printf("Not enough nodes to split.\n");
        return;
    }

    while (r->next != NULL && r->next->next != NULL) {
        t = t->next;
        r = r->next->next;
    }
    start2 = t->next;
    t->next = NULL;

    printf("First part: ");
    traverse(*start1);

    printf("Second part: ");
    traverse(start2);
}


int main(void) {
    struct node *start = NULL;
    insertbegin(&start, 100);
    insertend(&start, 200);
    insertend(&start, 300);
    insertend(&start, 400);
    insertend(&start, 500);
    insertend(&start, 600);
    insertend(&start, 800);

    printf("Original list: ");
    traverse(start);

    printf("\n");
    lastnode(&start, 3);
    printf("\nAfter removing the last node: ");
    traverse(start);

    printf("\nSplitting the list:\n");
    split(&start);

    return 0;
}
