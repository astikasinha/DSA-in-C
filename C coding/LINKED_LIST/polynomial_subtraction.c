#include <stdio.h>
#include <stdlib.h>

#define stacksize 100
#define true 1
#define false 0

struct stack {
    int item[stacksize];
    int top;
} s;

void initialize(struct stack *s) {
    s->top = -1;
}

int isempty(struct stack *s) {
    return (s->top == -1);
}

void push(struct stack *s, int x, int y) {
    if (s->top == (stacksize - 1)) {
        printf("\nSTACK OVERFLOW");
        exit(1);
    } else {
        s->top++;
        s->item[s->top] = x;
        s->top++;
        s->item[s->top] = y;
    }
}

int pop(struct stack *s, int *x, int *y) {
    if (isempty(s)) {
        printf("\nSTACK UNDERFLOW");
        exit(1);
    } else {
        *y = s->item[s->top];
        s->top--;
        *x = s->item[s->top];
        s->top--;
    }
}

struct node {
    int coeff, exp;
    struct node *next;
};

struct node *getnode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}

void insertbegin(struct node **list, int x, int y) {
    struct node *p;
    p = getnode();
    p->coeff = x;
    p->exp = y;
    p->next = *list;
    *list = p;
}

void insertend(struct node **list, int x, int y) {
    struct node *p, *q;
    p = *list;
    while (p != NULL && p->next != NULL) {
        p = p->next;
    }
    q = getnode();
    q->coeff = x;
    q->exp = y;
    q->next = NULL;
    if (p == NULL) {
        *list = q;  // Update the list pointer for an empty list
    } else {
        p->next = q;
    }
}

void traverse(struct node *list) {
    struct node *p;
    p = list;
    while (p != NULL) {
        printf("%dx^%d ", p->coeff, p->exp);
        p = p->next;
        if (p != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}

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

    *list = prev;  // Update the list pointer
}

void addpolynomial(struct node **list1, struct node **list2) {
    struct node *p, *q, *list3;
    p = *list1;
    q = *list2;
    list3 = NULL;

    while (p != NULL && q != NULL) {
        if (p->exp == q->exp) {
            insertbegin(&list3, p->coeff + q->coeff, p->exp);
            p = p->next;
            q = q->next;
        } else {
            if (p->exp > q->exp) {
                insertbegin(&list3, p->coeff, p->exp);
                p = p->next;
            } else {
                insertbegin(&list3, q->coeff, q->exp);
                q = q->next;
            }
        }
    }

    while (p != NULL) {
        insertbegin(&list3, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        insertbegin(&list3, q->coeff, q->exp);
        q = q->next;
    }

    reverselinkedlist(&list3);
    *list1 = list3; // Update the list1 pointer
}

void subtractpolynomial(struct node **list1, struct node **list2) {
    struct node *p, *q, *list3;
    p = *list1;
    q = *list2;
    list3 = NULL;
    while (q != NULL) {
        q->coeff = (-1) * q->coeff;
        insertbegin(&list3, q->coeff, q->exp);
        q = q->next;
    }
    addpolynomial(list1, &list3);
    traverse(*list1);
}

int main() {
    struct node *start1, *start2;
    start1 = NULL;
    start2 = NULL;

    insertend(&start1, 3, 5);
    insertend(&start1, 4, 4);
    insertend(&start1, -2, 2);
    insertend(&start1, 8, 1);
    insertend(&start1, 9, 0);
    traverse(start1);

    insertend(&start2, -2, 7);
    insertend(&start2, 1, 6);
    insertend(&start2, 3, 5);
    insertend(&start2, 5, 3);
    insertend(&start2, 4, 2);
    traverse(start2);

    subtractpolynomial(&start1, &start2);

    return 0;
}

