#include<stdio.h>
#include"astikalinkedlist.h"
void delall(struct node **start, int x) {
    struct node *p, *q;
    p = *start;
    q = NULL;
    while (p != NULL) {
        if (p->info == x) {
            struct node *temp = p;
            p = p->next;
            if (q == NULL) {
                deletebegin(start);
            } else {
                deleteNode(start, temp);
            }
        } else {
            q = p;
            p = p->next;
        }
    }
}


int main() {
    struct node *start;
    start = NULL;
    insertbegin(&start, 3);
    insertbegin(&start, 8);
    insertbegin(&start, 4);
    insertbegin(&start, 7);
    insertbegin(&start, 4);
    insertbegin(&start, 9);

    printf("Original list: ");
    traverse(start);

    delall(&start, 4);

    printf("List after deleting all occurrences of 4: ");
    traverse(start);

    return 0;
}