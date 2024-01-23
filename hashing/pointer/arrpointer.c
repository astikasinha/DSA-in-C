/*#include<stdio.h>
void main(){
    int a[]={1,2,3,4,5,6,7,89,90,75};
    int *t=a;
    for(int i=0;i<10;i++){
        printf("%d ",*(t+i));
    }
    
}*/

/*#include<stdio.h>
#include<stdlib.h>
void main(){
    int *t;
    int n;
    scanf("%d",&n);
    t=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(t+i));
    }
    for(int i=0;i<n;i++){
        printf("%d",*(t+i));
    } 
}*/
/*#include<stdio.h>
#include<stdlib.h>
void main(){
    int *t;
    int n;
    scanf("%d",&n);
    kite(n);
}
void kite(int n){
    t=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",(t+i));
    }
    for(int i=0;i<n;i++){
        printf("%d",*(t+i));
    } 
}*/
#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *start;
struct node *getnode(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    return p;
}
void insertbegin(int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=start;
    start=p;
}
void insertionatanyposition(int x){
    
}
/*void insertafter(struct node *p,int x){
    struct node *q;
    struct node *r;
    q=p->next;
    r=getnode();
    r->info=x;
    p->next=r;
    r->next=q;
}*/
void insertend(int x){
    struct node *p;
    struct node *q;
    p=start;
    while(p->next!='\0'){
        p=p->next;
    }
    q=getnode();
    q->info=x;
    q->next='\0';
    p->next=q;
}
int count(){
    int c=0;
    struct node *p;
    p=start;
    while(p!='\0'){
        c++;
        p=p->next;
    }
    return c;
}
int countevenodd(){
    int ce=0,co=0;
    struct node *p;
    p=start;
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
void pairwiseswap(){
    struct node *p;
    struct node *q;
    p=start;
    q=start->next;
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
    traverse();
}
void traverse(){
    struct node *p;
    p=start;
    while(p!='\0'){
        printf("%d ",p->info);
        p=p->next;
    }
}
void main(){
    start ='\0';
    insertbegin(100);
    insertbegin(200);
    insertbegin(300);
    insertbegin(400);
    insertend(600);
    insertend(3000);
    insertend(8900);
    int m=count();
    printf("%d\n",m);
    countevenodd();
    traverse();
    printf("\n");
    pairwiseswap();
}