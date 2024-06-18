#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
};

void initialize(struct node **top) {
    *top = NULL;
}

int isempty(struct node *top) {
    return (top == NULL);
}

void push(struct node **top, int x) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    if (newnode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newnode->info = x;
    newnode->next = *top;
    *top = newnode;
}

int pop(struct node **top) {
    if (isempty(*top)) {
        printf("Stack is empty\n");
        exit(1);
    } else {
        int x = (*top)->info;
        struct node *temp = *top;
        *top = (*top)->next;
        free(temp);
        return x;
    }
}

int stacktop(struct node *top) {
    if (isempty(top)) {
        printf("Stack is empty\n");
        exit(1);
    } else {
        return top->info;
    }
}

int main() {
    struct node *start;
    initialize(&start);

    push(&start, 100);
    push(&start, 200);
    push(&start, 300);
    push(&start, 400);
    push(&start, 500);
    push(&start, 600);
    push(&start, 800);

    printf("Popped element is %d\n", pop(&start));

    return 0;
}
