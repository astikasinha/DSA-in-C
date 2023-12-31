#include<stdio.h>
#include<stdlib.h>
#include"astikastack1.h"
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
int count(struct node *list){
    int c=0;
    struct node *p;
    p=list;
    while(p!='\0'){
        c++;
        p=p->next;
    }
    return c;
}
int countevenodd(struct node *list){
    int ce=0,co=0;
    struct node *p;
    p=list;
    while(p!='\0'){
        if((p->info)%2==0){
            ce++;
        }
        else{
            co++;
        }
        p=p->next;
    }
    printf("even %d         odd %d\n",ce,co);
}
void pairwiseswap(struct node **list){
    struct node *p;
    struct node *q,*m;
    p=*list;
    q=(*list)->next;
    while(p!='\0'&& q!='\0'){
        int t=p->info;
        p->info=q->info;
        q->info=t;
        p=p->next->next;
        q=q->next;
        if(q!='\0'){
            q=q->next;
        }

    }
    m=*list;
    while(m!='\0'){
        printf("%d ",m->info);
        m=m->next;
    }
}
int middleelement(struct node *list){
    struct node *t,*r;
    t=list;
    r=list->next;
    while(r!='\0'&& r->next!='\0'){
        t=t->next;
        r=r->next->next;
    }
    return t->info;
}
void reverselinkedlist(struct node**list){
    struct node *p,*m;
    p=*list;
    struct stack s1;
    initialize(&s1);
    while(p!='\0'){
        push(&s1,p->info);
        p=p->next;
    }
    p=*list;
    while(!isempty(&s1)){
        int x=pop(&s1);
        p->info=x;
        p=p->next;
    }
    m=*list;
    while(m!='\0'){
        printf("%d ",m->info);
        m=m->next;
    }
    
}
void concatenate(struct node **start1, struct node **start2) {
    struct node *p, *m;

    if ((*start1) == NULL && (*start2) == NULL) {
        printf("Both lists are empty.\n");
    } else {
        if ((*start1) == NULL) {
            *start1 = *start2;
        } else {
            p = *start1;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = *start2;
        }

        m = (*start1);
        while (m != NULL) {
            printf("%d ", m->info);
            m = m->next;
        }
    }
}
void last(struct node **list,int x){
    struct node *p,*m;
    p=*list;
    struct stack s1;
    initialize(&s1);
    while(p!='\0'){
        push(&s1,p->info);
        p=p->next;
    }
    p=*list;
    while(!isempty(&s1)){
        int x=pop(&s1);
        p->info=x;
        p=p->next;
    }
    m=*list;
    int i=0;
    while((m->info)!=x){
        i++;
        m=m->next;
    }
    printf("%d at position %d from last in linked list",m->info,i);
    
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
    while(p!='\0'){
        printf("%d ",p->info);
        p=p->next;
    }
}
void main(){
    struct node *start,*start1,*start2;
    start ='\0';
    start1='\0';
    start2='\0';
    insertbegin(&start,100);
    insertbegin(&start,200);
    insertbegin(&start,300);
    insertbegin(&start,400);
    insertend(&start,500);
    insertend(&start,600);
    insertend(&start,800);
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
    last(&start,200);
    printf("\n");
    int b=middleelement(start);
    printf("%d",b);
    printf("\n");
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