#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

void initialize(struct node **dstart) {
    *dstart = NULL;
}

struct node *getnode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->prev = NULL;
    p->next = NULL;
    return p;
}

int isempty(struct node *dstart) {
    if (dstart == NULL) {
        return true;
    } else {
        return false;
    }
}

void enqueuefront(struct node **front, struct node **rear, struct node **dstart, int x) {
    struct node *p;
    p = getnode();
    p->info = x;  // Set the info field to the input value x
    if (isempty(*dstart)) {
        *front = p;
        *rear = p;
    } else {
        p->next = *front;
        (*front)->prev = p;
        *front = p;
    }
    *dstart = *rear;
}

void enqueuerear(struct node **front, struct node **rear, struct node **dstart, int x) {
    struct node *p;
    p = getnode();
    p->info = x;  // Set the info field to the input value x
    if (isempty(*dstart)) {
        *front = p;
        *rear = p;
    } else {
        p->prev = *rear;
        (*rear)->next = p;
        *rear = p;
    }
    *dstart = *rear;
}


int dequeuerear(struct node **front, struct node **rear, struct node **dstart) {
    struct node *p;
    if (isempty(*dstart)) {
        return -1;
    } else {
        struct node *q;
        int x=(*rear)->info;
        p=(*rear)->prev;
        q=(*rear);
        (*rear)=q;
        p->next=NULL;
        free(q);
        return x;
    }
}
int dequeuefront(struct node **front, struct node **rear, struct node **dstart) {
    struct node *p;
    if (isempty(*dstart)) {
        return -1;
    } else {
        struct node *q;
        int x=(*front)->info;
        p=(*front)->next;
        q=(*front);
        (*front)=p;
        p->prev=NULL;
        free(q);
        return x;
    }
}

void traverse(struct node *dstart) {
    struct node *p;
    p = dstart;
    while (p->prev!= NULL) {
        p = p->prev;
    }
    while (p!= NULL) {
        printf("%d ",p->info);
        p = p->next;
    }
    
    printf("\n");
}

int main() {
    struct node *dstart, *front, *rear;
    initialize(&dstart);
    front = NULL;
    rear = NULL;

    enqueuerear(&front, &rear, &dstart, 100);
    enqueuerear(&front, &rear, &dstart, 200);
    enqueuerear(&front, &rear, &dstart, 300);
    enqueuerear(&front, &rear, &dstart, 400);
    traverse(dstart);

    int dequeuedValue = dequeuerear(&front, &rear, &dstart);
    if (dequeuedValue != -1) {
        printf("Dequeued value: %d\n", dequeuedValue);
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    enqueuefront(&front, &rear, &dstart, 100);
    enqueuefront(&front, &rear, &dstart, 200);
    enqueuefront(&front, &rear, &dstart, 300);
    enqueuefront(&front, &rear, &dstart, 400);
    traverse(dstart);

    traverse(dstart);
    dequeuedValue = dequeuefront(&front, &rear, &dstart);
    if (dequeuedValue != -1) {
        printf("Dequeued value: %d\n", dequeuedValue);
    } else {
        printf("Queue is empty. Cannot dequeue.\n");
    }

    traverse(dstart);

    return 0;
}
