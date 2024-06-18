#include <stdio.h>
#include <stdlib.h>

#define stacksize 100

struct stack {
    int item[stacksize];
    int top;
};

void initialize(struct stack *s) {
    s->top = -1;
}

int isempty(struct stack *s) {
    return (s->top == -1);
}

int stacktop(struct stack *s) {
    if (isempty(s)) {
        printf("stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return s->item[s->top];
}

void push(struct stack *s, int x) {
    if (s->top == (stacksize - 1)) {
        printf("\nSTACK OVERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        s->top++;
        s->item[s->top] = x;
    }
}

int pop(struct stack *s) {
    if (isempty(s)) {
        printf("\nSTACK UNDERFLOW\n");
        exit(EXIT_FAILURE);
    } else {
        int x = s->item[s->top];
        s->top--;
        return x;
    }
}

struct node {
    int info;
    struct node *next;
};

struct node *getnode() {
    return (struct node *)malloc(sizeof(struct node));
}

void insertbegin(struct node **list, int x) {
    struct node *p = getnode();
    p->info = x;
    p->next = *list;
    *list = p;
}

void insertafter(struct node **list, int y, int x) {
    struct node *temp = *list;
    while (temp != NULL && temp->info != y) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in the list\n", y);
        return;
    }

    struct node *p = getnode();
    p->info = x;
    p->next = temp->next;
    temp->next = p;
}

void insertend(struct node **list, int x) {
    struct node *p = getnode();
    p->info = x;
    p->next = NULL;

    if (*list == NULL) {
        *list = p;
    } else {
        struct node *temp = *list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

int deletebegin(struct node **list) {
    if (*list == NULL) {
        printf("List is empty\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = *list;
    *list = (*list)->next;
    int x = temp->info;
    free(temp);
    return x;
}

int deleteend(struct node **list) {
    if (*list == NULL) {
        printf("List is empty\n");
        exit(EXIT_FAILURE);
    }

    struct node *p = *list;
    struct node *q = NULL;
    int x;

    while (p->next != NULL) {
        q = p;
        p = p->next;
    }

    if (q == NULL) {
        *list = NULL;
    } else {
        q->next = NULL;
    }

    x = p->info;
    free(p);
    return x;
}

int count(struct node *list) {
    int c = 0;
    struct node *p = list;
    while (p != NULL) {
        c++;
        p = p->next;
    }
    return c;
}

void countevenodd(struct node *list) {
    int ce = 0, co = 0;
    struct node *p = list;
    while (p != NULL) {
        if ((p->info) % 2 == 0) {
            ce++;
        } else {
            co++;
        }
        p = p->next;
    }
    printf("even %d         odd %d\n", ce, co);
}

void pairwiseswap(struct node **list) {
    struct node *p = *list;
    while (p != NULL && p->next != NULL) {
        int t = p->info;
        p->info = p->next->info;
        p->next->info = t;
        p = p->next->next;
    }
}



void reverselinkedlist(struct node **list) {
    struct node *p = *list;
    struct stack s1;
    initialize(&s1);

    while (p != NULL) {
        push(&s1, p->info);
        p = p->next;
    }

    p = *list;
    while (!isempty(&s1)) {
        int x = pop(&s1);
        p->info = x;
        p = p->next;
    }

    struct node *m = *list;
    while (m != NULL) {
        printf("%d ", m->info);
        m = m->next;
    }
}

void concatenate(struct node **start1, struct node **start2) {
    struct node *p = *start1;

    if (p == NULL && *start2 == NULL) {
        printf("Both lists are empty.\n");
        return;
    }

    if (p == NULL) {
        *start1 = *start2;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = *start2;
    }

    struct node *m = *start1;
    while (m != NULL) {
        printf("%d ", m->info);
        m = m->next;
    }
}


void sort(struct node **list) {
    struct node *t, *r;
    t = *list;

    if (t == NULL) {
        printf("Empty list\n");
        return;
    }

    while (t != NULL) {
        r = t->next;
        while (r != NULL) {
            if (t->info > r->info) {
                int temp = t->info;
                t->info = r->info;
                r->info = temp;
            }
            r = r->next;
        }
        t = t->next;
    }

    struct node *m = *list;
    while (m != NULL) {
        printf("%d ", m->info);
        m = m->next;
    }
}

void traverse(struct node *list){
    struct node *p;
    p=list;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
}
void main(){
    struct node *start,*start1,*start2;
    start ='\0';
    start1='\0';
    start2='\0';
    insertend(&start,100);
    insertend(&start,200);
    insertend(&start,300);
    insertend(&start,400);
    insertend(&start,500);
    insertend(&start,600);
    insertend(&start,800);
    printf("\n");
    insertafter(&start,600,700);
    traverse(start);
    printf("\n");
    int k=deletebegin(&start);
    traverse(start);
    printf("\n");
    printf("%d\n",k);
    int g=deleteend(&start);
    traverse(start);
    printf("\n");
    int m=count(start);
    printf("%d\n",m);
    reverselinkedlist(&start);
    printf("\n");
    countevenodd(start);
    printf("\n");
    pairwiseswap(&start);
    printf("\n");
    sort(&start);
    printf("\n");
    insertbegin(&start1,100);
    insertbegin(&start1,200);
    insertbegin(&start1,300);
    insertbegin(&start1,400);
    insertend(&start1,500);
    insertend(&start1,600);
    insertend(&start1,800);
    insertbegin(&start2,100);
    insertbegin(&start2,200);
    insertbegin(&start2,300);
    insertbegin(&start2,400);
    insertend(&start2,500);
    insertend(&start2,600);
    insertend(&start2,800);
    concatenate(&start1,&start2);
}