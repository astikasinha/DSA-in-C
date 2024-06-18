#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node* next;
};

void insertbegin(struct node** list, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = *list;
    *list = newNode;
}

void insertend(struct node** list, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    if (*list == NULL) {
        *list = newNode;
        return;
    }

    struct node* temp = *list;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertafter(struct node** list, int afterData, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->info = data;
    newNode->next = NULL;

    struct node* temp = *list;
    while (temp != NULL && temp->info != afterData) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Element %d not found in the list.\n", afterData);
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void traverse(struct node* list) {
    while (list != NULL) {
        printf("%d ", list->info);
        list = list->next;
    }
}

int count(struct node* list) {
    int c = 0;
    while (list != NULL) {
        c++;
        list = list->next;
    }
    return c;
}

struct node* reverselinkedlist(struct node* list) {
    struct node *prev, *current, *next;
    prev = NULL;
    current = list;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;  // Return the new head of the reversed list
}

void palindrome(struct node* list) {
    struct node *p, *q;
    p = list;
    int flag = 1;
    int c = count(list);
    int mid = (c % 2 == 0) ? (c / 2) : ((c + 1) / 2);

    for (int i = 1; i < mid; i++) {
        p = p->next;
    }

    struct node* revhead = reverselinkedlist(p->next);

    while (list != NULL && revhead != NULL) {
        if (list->info != revhead->info) {
            flag = 0;
            break;
        }
        list = list->next;
        revhead = revhead->next;
    }

    if (flag == 1)
        printf("Given singly linked list is a palindrome\n");
    else
        printf("Given singly linked list is not a palindrome\n");
}

int main() {
    struct node* start = NULL;

    insertbegin(&start, 100);
    insertbegin(&start, 200);
    insertbegin(&start, 300);
    insertbegin(&start, 400);
    insertend(&start, 500);
    insertend(&start, 600);
    insertend(&start, 800);
    insertafter(&start, 600, 700);

    traverse(start);
    printf("\n");

    palindrome(start);

    return 0;
}
