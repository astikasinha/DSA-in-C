#include<stdio.h>
#include<stdlib.h>
struct node{
    int coeff,exp;
    struct node *next;
};
struct node *getnode() {
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    return p;
}
void insertbegin(struct node **start,int x,int y){
    struct node *p;
    p=getnode();
    p->coeff=x;
    p->exp=y;
    p->next=*start;
    *start=p;

}
void traverse(struct node *start){
    struct node *p;
    p=start;
    while(p!=NULL){
        printf("%dx^%d",p->coeff,p->exp);
        p=p->next;
        if(p!=NULL){
            printf("+ ");
        }
    }
    printf("\n");


}
void addpoly(struct node **poly1,struct node **poly2){
    struct node *poly3,*p,*q;
    poly3=NULL;
    p = *poly1;
    q = *poly2;

    while (p != NULL && q != NULL) {
        if (p->exp == q->exp) {
            insertbegin(&poly3, p->coeff + q->coeff, p->exp);
            p = p->next;
            q = q->next;
        } else {
            if (p->exp > q->exp) {
                insertbegin(&poly3, p->coeff, p->exp);
                p = p->next;
            } else {
                insertbegin(&poly3, q->coeff, q->exp);
                q = q->next;
            }
        }
    }
     while (p != NULL) {
        insertbegin(&poly3, p->coeff, p->exp);
        p = p->next;
    }

    while (q != NULL) {
        insertbegin(&poly3, q->coeff, q->exp);
        q = q->next;
    }
    traverse(poly3);


}
void polymultiply(struct node **list1,struct node **list2){
    struct node *p,*q,*poly3;
    p=*list1;
    q=*list2;
    poly3=NULL;

    int n=(*list1)->exp+(*list2)->exp;
    int *DAT,x,i;
    DAT=(int *)calloc(n+1,sizeof(int));
    while(p!=NULL){
        q=*list2;
        while(q!=NULL){
            x=p->exp+q->exp;
            DAT[x]=DAT[x]+((p->coeff)*(q->coeff));
            q=q->next;
        }
        p=p->next;
    }
    for(i=0;i<=n;i++){
        if(DAT[i]!=0){
            insertbegin(&poly3,DAT[i],i);
        }
    }
    traverse(poly3);
}
void main(){
    struct node *poly1,*poly2;
    poly1=NULL;
    poly2=NULL;
    insertbegin(&poly1,3,2);
    insertbegin(&poly1,8,4);
    insertbegin(&poly1,9,5);
    traverse(poly1);
    insertbegin(&poly2,6,6);
    insertbegin(&poly2,1,7);
    insertbegin(&poly2,2,8);
    traverse(poly2);

    polymultiply(&poly1,&poly2);
}