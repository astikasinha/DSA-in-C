#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *random;
};

struct node *getnode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void insertbegin(struct node **list, int x) {
    struct node *p;
    p = getnode();
    p->info = x;
    p->next = *list;
    *list = p;
}

void insertend(struct node **list, int x) {
    struct node *p;
    struct node *q;
    p = *list;
    while (p->next != NULL) {
        p = p->next;
    }
    q = getnode();
    q->info = x;
    q->next = NULL;
    p->next = q;
}

void traverse(struct node *list) {
    struct node *p;
    p = list;
    while (p != NULL) {
        printf("%d ", p->info);
        p = p->next;
    }
    printf("\n");
}

struct node *duplicate(struct node *head) {
    // inserting new nodes in between
    struct node *p, *temp;
    struct node *cur = head;
    while (cur != NULL) {
        temp = cur->next;
        p = getnode();
        p->info = cur->info;
        cur->next = p;
        cur->next->next = temp;
        cur = temp;
    }

    cur = head;
    // setting random pointers of new nodes
    while (cur != NULL) {
        if (cur->next != NULL) {
            cur->next->random = (cur->random != NULL) ? (cur->random->next) : NULL;
        }
        cur = cur->next->next;
    }

    struct node *orig = head;
    struct node *copy = head->next;
    temp = copy;
    while (orig != NULL) {
        orig->next = orig->next->next;
        copy->next = (copy->next != NULL) ? (copy->next->next) : NULL;
        orig = orig->next;
        copy = copy->next;
    }

    return temp;
}

int main() {
    struct node *start = NULL;
    insertbegin(&start, 100);
    insertend(&start, 200);
    insertend(&start, 300);
    insertend(&start, 400);
    insertend(&start, 500);
    insertend(&start, 600);
    insertend(&start, 800);

    struct node *duplicateList = duplicate(start);
    traverse(duplicateList);

    return 0;
}
