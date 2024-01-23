#include <stdio.h>
#include"astikalinkedlist.h"
int middleelement(struct node *start){
    struct node *t,*r;
    t=start;
    r=start;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next->next;
    }
    return t;
}
struct node* binarysearch(struct node *start, int key) {
    if (start != NULL) {
        struct node *mid = middleelement(start);  // Corrected the type of mid
        if (key == mid->info) {
            return mid;
        } else {
            if (key < mid->info) {
                return binarysearch(start, key);
            } else {
                return binarysearch(mid->next, key);
            }
        }
    } else {
        return NULL;
    }
}


int main() {
    struct node *list = NULL;

    insertbegin(&list, 10);
    insertend(&list, 20);
    insertend(&list, 30);
    insertend(&list, 40);
    insertend(&list, 50);
    insertend(&list, 60);
    insertend(&list, 70);
    insertend(&list, 80);

    struct node *k = middleelement(list);  // Corrected the type of k
    printf("Middle element: %d\n", k->info);

    int target = 60;
    struct node *result = binarysearch(list, target);
    if (result != NULL) {
        printf("Element %d found at position %d\n", target, result->info);
    } else {
        printf("Element %d not found\n", target);
    }

    return 0;
}
