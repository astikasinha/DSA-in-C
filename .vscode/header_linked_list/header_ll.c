#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct headnode{
    int info;
    int c,min,max;
    struct node *next;
};
struct headnode *getnode(){
    struct headnode *p;
    p=(struct headnode*)malloc(sizeof(struct headnode));
    return p;

}
struct headnode *createlinkedlist(struct headnode *head){
    head=getnode();
    head->c=0;
    head->max=-1;
    int min=32000;
    head->next=NULL;
    return head;
}
void insertbegin(struct headnode **head,int x){
    struct headnode *p,*q;
    p=getnode();
    q=(*head)->next;
    p->info=x;
    (*head)->next=p;
    p->next=q;
    (*head)->c++;
    if(x>(*head)->max){
        (*head)->max=x;
    }
    if(x<(*head)->min){
        (*head)->min=x;
    }


}
void traverse(struct headnode *head){
    struct headnode *p;
    p=head->next;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }

}
void freenode(struct node * p)
{
    free(p);
}
int deletebegin(struct node **head){
    struct node *p,*q;
    p=(*head)->next;
    q=p->next;
    (*head)->next=q;
    int x=p->info;
    free(p);
    (*head)->info=((*head)->info)-1;
    return x;
}
int main(){
    struct headnode *head;
    head=createlinkedlist(head);
    insertbegin(&head,1);
    insertbegin(&head,2);
    insertbegin(&head,3);
    insertbegin(&head,41);
    traverse(head);
    printf("\n%d",head->c);
    printf("\n%d",head->max);
    printf("\n%d",head->min);
    return 0;
    

}

