#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *getnode(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
void insertbegin(struct node **list,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=*list;
    *list=p;
}
void insertafter(struct node **list,int y,int x){
    struct node *temp;
    struct node *p;
    temp=*list;
    while(temp!='\0'){
        if(temp->info==y){
            break;
        }
        else{
            temp=temp->next;
        }
    }
    p=getnode();
    p->info=x;
    p->next=temp->next;
    temp->next=p;
}
void insertend(struct node **list,int x){
    struct node *p;
    struct node *q;
    p=*list;
    while(p->next!='\0'){
        p=p->next;
    }
    q=getnode();
    q->info=x;
    q->next='\0';
    p->next=q;
}
int deletebegin(struct node **list){
    struct node *temp;
    int x;
    temp=*list;
    (*list)=(*list)->next;
    x=temp->info;
    free(temp);
    return x;
}
void deleteNode(struct node **list, struct node *nodeToDelete) {
    struct node *temp = *list;
    while (temp != NULL && temp->next != nodeToDelete) {
        temp = temp->next;
    }

    if (temp == NULL) {
        // Node not found
        return;
    }

    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
 
int deleteend(struct node **list){
    struct node *p,*q;
    p=*list;
    q='\0';
    int x;
    while(p->next!='\0'){
        q=p;
        p=p->next;
    }
    q->next='\0';
    x=p->info;
    free(p);
    return x;
}

void traverse(struct node *list){
    struct node *p;
    p=list;
    while(p!='\0'){
        printf("%d ",p->info);
        p=p->next;
    }
}