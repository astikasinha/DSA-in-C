#include<stdio.h>
#include<stdlib.h>

struct node {
    int info;
    struct node *next;
    struct node *prev;
};

struct node *getnode() {
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->prev = NULL;
    p->next = NULL;
    return p;
}

void insertbegin(struct node **cdstart, int x) {
    struct node *p;
    if ((*cdstart) == NULL) {
        p = getnode();
        p->info = x;
        p->next = p;
        p->prev = p;
        (*cdstart) = p;
    } else {
        struct node *q = (*cdstart)->next;
        p = getnode();
        p->info = x;
        p->prev = (*cdstart);
        p->next = q;
        q->prev = p;
        (*cdstart)->next = p;
    }
}
void insertend(struct node **cdstart, int x) {
    struct node *p;
    if ((*cdstart) == NULL) {
        p = getnode();
        p->info = x;
        p->next = p;
        p->prev = p;
        (*cdstart) = p;
    } else {
        struct node *q = (*cdstart)->next;
        p = getnode();
        p->info = x;
        p->next=q;
        p->prev=(*cdstart);
        (*cdstart)->next=p;
        q->prev=p;
        (*cdstart)=p;
    }
}
void insertafter(struct node **cdstart,int y,int x){
    struct node *p;
    if ((*cdstart) == NULL) {
        p = getnode();
        p->info = x;
        p->next = p;
        p->prev = p;
        (*cdstart) = p;
    } else {
        struct node *temp;
        temp=(*cdstart)->next;
        while(temp->info!=y){
            temp=temp->next;
        }
        p=getnode();
        p->info=x;
        p->prev=temp;
        p->next=temp->next;
        temp->next->prev=p;
        temp->next=p;
        if(temp==(*cdstart)){
            (*cdstart)=(*cdstart)->next;
        }
    }
    
}
void insertbefore(struct node **cdstart,int y,int x){
    struct node *p;
    if ((*cdstart) == NULL) {
        p = getnode();
        p->info = x;
        p->next = p;
        p->prev = p;
        (*cdstart) = p;
    } else {
        struct node *temp;
        temp=(*cdstart)->prev;
        while(temp->info!=y){
            temp=temp->next;
        }
        p=getnode();
        p->info=x;
        p->next=temp;
        p->prev=temp->prev;
        temp->prev->next=p;
        temp->prev=p;
        if(temp==(*cdstart)){
            (*cdstart)=(*cdstart)->prev;
        }
    }
    
}
int deletebegin(struct node **cdstart){
    if((*cdstart)==NULL){
        printf("void deletion");
    }
    else{
        struct node *temp;
        temp=(*cdstart)->next;
        (*cdstart)->next=temp->next;
        temp->next->prev=(*cdstart);
        int x=temp->info;
        free(temp);
        return x;
    }
}
int deleteend(struct node **cdstart){
    if((*cdstart)==NULL){
        printf("void deletion");
    }
    else{
        struct node *temp,*temp2;
        temp=(*cdstart)->prev;
        temp->next=(*cdstart)->next;
        (*cdstart)->next->prev=temp;
        temp2=(*cdstart);
        int x=temp2->info;
        (*cdstart)=temp;
        free(temp2);
        return x;
    }
    
}
int deleteafter(struct node **cdstart,int y){
    if((*cdstart)==NULL){
        printf("void deletion");
    }
    else{
        struct node *temp,*temp2;
        temp=(*cdstart)->next;
        while(temp->info!=y){
            temp=temp->next;
        }
        temp2=temp->next;
        temp->next=temp2->next;
        temp2->next->prev=temp;
        int x=temp2->info;
        free(temp2);
        return x;
    }
    
}
int deletebefore(struct node **cdstart,int y){
    if((*cdstart)==NULL){
        printf("void deletion");
    }
    else{
        struct node *temp,*temp2;
        temp=(*cdstart)->prev;
        while(temp->info!=y){
            temp=temp->next;
        }
        temp2=temp->prev;
        temp->prev=temp2->prev;
        temp2->prev->next=temp;
        int x=temp2->info;
        free(temp2);
        return x;
    }
    
}

void traverse(struct node *cdstart) {
    if (cdstart == NULL) {
        printf("void list\n");
    } else {
        struct node *q = cdstart;
        do {
            printf("%d ", (q->next)->info);
            q = q->next;
        } while (q != cdstart);
        printf("\n");
    }
}

int main() {
    struct node *cdstart;
    cdstart = NULL;
    insertbegin(&cdstart, 100);
    insertbegin(&cdstart, 200);
    insertbegin(&cdstart, 300);
    insertbegin(&cdstart, 400);
    traverse(cdstart);
    printf("\n");
    insertend(&cdstart, 500);
    traverse(cdstart);
    printf("\n");
    insertafter(&cdstart, 300,700);
    traverse(cdstart);
    printf("\n");
    insertbefore(&cdstart, 300,1000);
    traverse(cdstart);
    printf("\n");
    int m=deletebegin(&cdstart);
    traverse(cdstart);
    printf("\n");
    printf("%d",m);
    printf("\n");
    int l=deleteafter(&cdstart,300);
    traverse(cdstart);
    printf("\n");
    printf("%d",l);
    printf("\n");
    l=deletebefore(&cdstart,300);
    traverse(cdstart);
    printf("\n");
    printf("%d",l);
    printf("\n");
    l=deleteend(&cdstart);
    traverse(cdstart);
    printf("\n");
    printf("%d",l);
    printf("\n");
    

    return 0;
}
