#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node *next;
};
struct node *getnode(){
    struct node *p;
    p=(struct node *)malloc(sizeof(struct node));
    p->next=NULL;
    return p;
}
int insertbegin(struct node **start,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next=(*start);
    (*start)=p;
}
void traverse(struct node *start){
    struct node *p;
    p=start;
    while(p!=NULL){
        printf("%d   ",p->info);
        p=p->next;
    }
}
int main(){
    struct node *chain[10]={NULL};//array of linked list
    for(int i=1;i<=100;i++){
        int k=i%10;
        insertbegin(&chain[k],i);
    }

    for(int i=0;i<10;i++){
        printf("\nchain %d:=> ",i);
        traverse(chain[i]);
        printf("\n");
    }
}