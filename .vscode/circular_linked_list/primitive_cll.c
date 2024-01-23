#include<stdio.h>
struct node{
int info;
struct node *next;
};
struct node * getnode()
{
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}
void traverse(struct node *cstart)
{
    if(cstart==NULL)
    {
        return;
    }
    else
    {
        struct node *p=cstart->next;
        while(p!=cstart)
        {
            printf("%d ->",p->info);
            p=p->next;
        }
        printf("%d \n",p->info);
    }
}
void insbeg(struct node **cstart,int data)
{
    if(*cstart==NULL)
    {
        struct node *p=getnode();
        p->info=data;
        p->next=p;
        *cstart=p;
    }
    else
    {
        struct node *p=getnode();
        p->info=data;
        struct node *q=(*cstart)->next;
        p->next=q;
        (*cstart)->next=p;
    }
}
void insend(struct node **cstart,int data)
{
    if(*cstart==NULL)
    {
        struct node *p=getnode();
        p->info=data;
        p->next=p;
        *cstart=p;
    }
    else
    {
        struct node *p=getnode();
        p->info=data;
        struct node *q=(*cstart)->next;
        (*cstart)->next=p;
        p->next=q;
        (*cstart)=p;
    }
}
void insaft(struct node **cstart,int data,struct node *x)
{
    if(*cstart==(*cstart)->next)
    {
        struct node *p=getnode();
        p->info=data;
        (*cstart)->next=p;
        p->next=(*cstart);
        (*cstart)=p;
    }
    else
    {


    struct node *p=(*cstart)->next;
        while(p->info!=x->info)
        {
            p=p->next;
        }
        struct node *q=p->next;
        struct node *r=getnode();
        r->info=data;
        p->next=r;
        r->next=q;
    }
}
void freenode(struct node * p)
{
    free(p);
}
int delbeg(struct node **cstart)
{
    if(*cstart==(*cstart)->next)
    {
    struct node *p=(*cstart);
    int x=p->info;
        (*cstart)=NULL;
            freenode(p);
            return x;
    }
    else
    {
        struct node *p=(*cstart)->next;
        struct node *q=p->next;
        int x=p->info;
        (*cstart)->next=q;
        freenode(p);
        return x;
    }
}
int delend(struct node **cstart)
{
    if(*cstart==(*cstart)->next)
    {
    struct node *p=(*cstart);
    int x=p->info;
        (*cstart)=NULL;
            freenode(p);
            return x;
    }
    else
    {
        struct node *p=(*cstart)->next;
        while(p->next!=(*cstart))
        {
            p=p->next;
        }
        int x=(*cstart)->info;
        struct node *q=(*cstart)->next;
        struct node *r=(*cstart);
        freenode(r);
        p->next=q;
        (*cstart)=p;
        return x;
    }
}
int delaft(struct node **cstart,struct node *x)
{
    if(*cstart==(*cstart)->next)
    {
         struct node *p=(*cstart);
    int x=p->info;
        (*cstart)=NULL;
            freenode(p);
            return x;
    }
    else
    {
        struct node *p=(*cstart)->next;
        while(p->info!=x->info)
        {
            p=p->next;
        }
        struct node *q=p->next;
        struct node *r=q->next;
        p->next=r;
        int x=q->info;
        freenode(q);
        return x;
    }
}
int sumofnodes(struct node *cstart)
{
    if(cstart==NULL)
    {
        return 0;
    }
    struct node *p=cstart->next;
    int sum=0;
    while(p!=cstart)
    {
        sum=sum+p->info;
        p=p->next;
    }
    sum=sum+p->info;
    return sum;
}
void changell(struct node **cstart)
{
    if(*cstart==NULL)
    {
        return;
    }
    else
    {
        struct node *p=(*cstart)->next;
        int sum=sumofnodes(*cstart);
        while(p!=(*cstart))
        {
            p->info=sum-p->info;
            p=p->next;
        }
        p->info=sum-p->info;
        return;
    }
}
void main()
{
    struct node *cstart=NULL;
    insbeg(&cstart,1);
    insbeg(&cstart,2);

    insbeg(&cstart,3);
    insbeg(&cstart,4);
    insbeg(&cstart,5);

    traverse(cstart);
    insbeg(&cstart,6);
    traverse(cstart);
    insend(&cstart,10);
    traverse(cstart);
    struct node *x=getnode();
    x->info=4;
    insaft(&cstart,12,x);
    traverse(cstart);
    delbeg(&cstart);
    traverse(cstart);
    delend(&cstart);
    traverse(cstart);
    struct node *z=getnode();
    z->info=12;
    delaft(&cstart,z);
    traverse(cstart);
    printf("sum of nodes=%d \n",sumofnodes(cstart));
    changell(&cstart);
    traverse(cstart);
}