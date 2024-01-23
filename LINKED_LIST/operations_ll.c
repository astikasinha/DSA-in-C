#include<stdio.h>
#include"astikalinkedlist.h"
#include"astikastack1.h"
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
void merge(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL && q!=NULL){
        if(p->info<q->info){
            insertbegin(&poly3,p->info);
            p=p->next;
        }
        else{
            insertbegin(&poly3,q->info);
            q=q->next;
        }
    }
    while(p!=NULL){
        insertbegin(&poly3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insertbegin(&poly3,q->info);
        q=q->next;
    }
    reverselinkedlist(&poly3);
}
void unionof(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->info<q->info){
            insertbegin(&poly3,p->info);
            p=p->next;
        }
        else{
            if(q->info<p->info){
                insertbegin(&poly3,q->info);
                q=q->next;
            }
            else{
                insertbegin(&poly3,p->info);
                p=p->next;
                q=q->next;
            }
        }
    }
    while(p!=NULL){
        insertbegin(&poly3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insertbegin(&poly3,q->info);
        q=q->next;
    }
    reverselinkedlist(&poly3);
}
void intersectionof(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->info<q->info){
            p=p->next;
        }
        else{
            if(q->info<p->info){
                q=q->next;
            }
            else{
                insertbegin(&poly3,p->info);
                p=p->next;
                q=q->next;
            }
        }
    }
    reverselinkedlist(&poly3);

}
void difference1(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->info<q->info){
            insertbegin(&poly3,p->info);
            p=p->next;
        }
        else{
            if(q->info<p->info){
                q=q->next;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
    }
    while(p!=NULL){
        insertbegin(&poly3,p->info);
        p=p->next;
    }
    reverselinkedlist(&poly3);
}
void difference2(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->info<q->info){
            p=p->next;
        }
        else{
            if(q->info<p->info){
                insertbegin(&poly3,q->info);
                q=q->next;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
    }
    while(q!=NULL){
        insertbegin(&poly3,q->info);
        q=q->next;
    }
    reverselinkedlist(&poly3);
}
void symmetric(struct node **poly1,struct node **poly2){
    struct node *p,*q,*poly3;
    p=*poly1;
    q=*poly2;
    poly3=NULL;
    while(p!=NULL&&q!=NULL){
        if(p->info<q->info){
            insertbegin(&poly3,p->info);
            p=p->next;
        }
        else{
            if(q->info<p->info){
                insertbegin(&poly3,q->info);
                q=q->next;
            }
            else{
                p=p->next;
                q=q->next;
            }
        }
    }
    while(p!=NULL){
        insertbegin(&poly3,p->info);
        p=p->next;
    }
    while(q!=NULL){
        insertbegin(&poly3,q->info);
        q=q->next;
    }
    reverselinkedlist(&poly3);

}
void main(){
    struct node *poly1,*poly2;
    poly1=NULL;
    poly2=NULL;
    insertbegin(&poly1,4);
    insertbegin(&poly1,3);
    insertbegin(&poly1,2);
    traverse(poly1);
    insertbegin(&poly2,3);
    insertbegin(&poly2,2);
    insertbegin(&poly2,1);
    traverse(poly2);

    symmetric(&poly1,&poly2);
}