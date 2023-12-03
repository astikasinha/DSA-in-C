#include<stdio.h>
#include"astikalinkedlist.h"
#include"astikastack1.h"
int count(struct node **list){
    int c=0;
    struct node *p;
    p=list;
    while(p!='\0'){
        c++;
        p=p->next;
    }
    return c;
}
int reverselinkedlist(struct node **list){
    struct node *p,*m;
    p=list;
    struct stack s1;
    initialize(&s1);
    while(p!='\0'){
        push(&s1,p->info);
        p=p->next;
    }
    p=list;
    while(!isempty(&s1)){
        int x=pop(&s1);
        p->info=x;
        p=p->next;
    }
    m=list;
    while(m!='\0'){
        return m->info;
        m=m->next;
    }
    
}
void palindrome(struct node **list){
    struct node *p,*q;
    p=*list;
    int flag=1;
    int c=count(*list);
    int mid=(c%2==0)?(c/2):((c+1)/2);
    for(int i=1; i<mid; i++){  
        p = p->next;  
    }  
    struct node *revhead = reverselinkedlist(p->next);
     while((*list) != NULL && revhead != NULL){  
        if((*list)->info != revhead->info){  
            flag = 0;  
            break;  
        }  
        (*list) = (*list)->next;  
        revhead = revhead->next;  
    }  
   
    if(flag==1)  
        printf("Given singly linked list is a palindrome\n");  
    else  
        printf("Given singly linked list is not a palindrome\n");  
}  
void main(){
    struct node *start;
    start ='\0';
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
    palindrome(&start);
}
