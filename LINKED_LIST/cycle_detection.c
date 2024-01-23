#include <stdio.h>
#include "astikalinkedlist.h"

int lengthloop(struct node *start) {
    struct node *t, *r;
    int c=0;
    t = start;
    r = start->next;
    while (r!=t) {
        t = t->next;
        r = r->next->next;
    }
    do{
        c++;
        t=t->next;
    }while(t!=r);
    return c;
}
int findloop(struct node *start) {
    struct node *t, *r;
    t = start;
    r = start->next;
    while (r != NULL && r->next != NULL) {
        t = t->next;
        r = r->next->next;
        if (t == r) {
            return 1;
        }
    }
    return 0;
}

int main() {
    struct node *start = NULL;
    struct node *p, *q;
    insertbegin(&start, 1);
    insertend(&start, 2);
    insertend(&start, 3);
    insertend(&start, 4);
    insertend(&start, 5);
    insertend(&start, 6);
    insertend(&start, 7);
    insertend(&start, 8);
    p = start;
    while (p->info != 4) {
        p = p->next;
    }
    q = start;
    while (q->info != 8) {
        q = q->next;
    }
    q->next = p;

    int k = findloop(start);
    if (k == 1) {
        printf("Loop exists\n");
    } else {
        printf("Loop does not exist\n");
    }
    int x=lengthloop(start);
    printf("%d",x);
    return 0;
}

