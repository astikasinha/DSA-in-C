#include<stdio.h>
#include<stdlib.h>
struct node{
int info;
struct node *next;
struct node *prev;
};
struct node *getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->prev=NULL;
    p->next=NULL;
    return p;
}
struct node *search(struct node *dstart,int x){
    struct node *p;
    p=dstart;
    while(p->info!=x){
        p=p->next;
        
    }
    return p;
}
void insertbegin(struct node **dstart,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=(*dstart);
    if((*dstart)!=NULL){
        (*dstart)->prev=p;
    }
    (*dstart)=p;
}
void insertend(struct node **dstart,int x){
    struct node *p,*q;
    p=getnode();
    p->info=x;
    p->next=NULL;
    if((*dstart)!=NULL){
        q=(*dstart);
        while(q->next!=NULL){
            q=q->next;
        }
            q->next=p;
            p->prev=q;
    

    }
    else{
        p->prev=NULL;
        (*dstart)=p;
    }
}
void insertafter(struct node **p,int x){
    struct node *q,*r;
    q=(*p)->next;
    r=getnode();
    r->info=x;
    (*p)->next=r;
    r->prev=(*p);
    r->next=q;
    if(q!=NULL){
        q->prev=r;
    }
}
void insertbefore(struct node **dstart,struct node **p,int x){
    struct node *q,*r;
    q=(*p)->prev;
    r=getnode();
    r->info=x;
    r->next=(*p);
    (*p)->prev=r;
    r->prev=q;
    if(q!=NULL){
        q->next=r;
    }
    else{
        (*dstart)=r;
    }
}
void freenode(struct node *p)
{
    free(p);
}
int deletebegin(struct node **dstart){
    struct node *p;
    p=(*dstart);
    (*dstart)=(*dstart)->next;
    if(*dstart!=NULL){
        (*dstart)->prev=NULL;
    }
    int x=p->info;
    freenode(p);
    return x;

}
int deleteend(struct node **dstart){
    struct node *p,*q;
    p=(*dstart);
    while(p->next!=NULL){
        p=p->next;
    }
    q=p->prev;
    if(q!=NULL){
        q->next=NULL;
    }
    else{
        (*dstart)=NULL;
    }
    int x=p->info;
    freenode(p);
    return x;
}
void deleteafter(struct node **p){
    struct node *q;
    if((*p)!=NULL && (*p)->next!=NULL){
        q=(*p)->next;
        (*p)->next=q->next;
        if(q->next!=NULL){
            q->next->prev=(*p);
        }
        free(q);
    }
    else{
        printf("void deletion");
    }
}
void deletebefore(struct node **p){
    struct node *q;
    if((*p)!=NULL && (*p)->prev!=NULL){
        q=(*p)->prev;
        (*p)->prev=q->prev;
        if(q->prev!=NULL){
            q->prev->next=(*p);
        }
        free(q);
    }
    else{
        printf("void deletion");
    }
}

void traverse(struct node *dstart){
    struct node *p=dstart;
    while(p!=NULL){
        printf("%d ",p->info);
        p=p->next;
    }
}
void main(){
    struct node *dstart,*p;
    dstart=NULL;
    insertbegin(&dstart,100);
    insertbegin(&dstart,200);
    insertbegin(&dstart,300);
    insertbegin(&dstart,400);
    insertbegin(&dstart,500);
    insertbegin(&dstart,600);
    traverse(dstart);
    printf("\n");
    p=search(dstart,400);
    insertafter(&p,8888);
    traverse(dstart);
    printf("\n");
    p=search(dstart,400);
    insertbefore(&dstart,&p,99998);
    traverse(dstart);
    printf("\n");
    int k=deletebegin(&dstart);
    traverse(dstart);
    printf("\n");
    printf("%d",k);
    printf("\n");
    insertend(&dstart,9000);
    traverse(dstart);
    printf("\n");
    int m=deleteend(&dstart);
    traverse(dstart);
    printf("\n");
    printf("%d",m);
    printf("\n");
    p=search(dstart,400);
    deletebefore(&p);
    traverse(dstart);
    printf("\n");
    p=search(dstart,300);
    deleteafter(&p);
    traverse(dstart);

}
