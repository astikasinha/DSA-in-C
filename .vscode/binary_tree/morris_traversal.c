#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};

struct node *makenode(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    p->next=NULL;
    return p;
}
void createTree(struct node **root) {
    struct node *p;
    int x, choice;
    if ((*root) == NULL) {
        printf("Enter the data of the root node: ");
        scanf("%d", &x);
        (*root) = makenode(x);
    }

    printf("Does the left of %d exist? (1 for Yes, 0 for No): ", (*root)->data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the data of the left node: ");
        scanf("%d", &x);
        p = makenode(x);
        (*root)->left = p;
        createTree(&((*root)->left));
    }

    printf("Does the right of %d exist? (1 for Yes, 0 for No): ", (*root)->data);
    scanf("%d", &choice);
    if (choice == 1) {
        printf("Enter the data of the right node: ");
        scanf("%d", &x);
        p = makenode(x);
        (*root)->right = p;
        createTree(&((*root)->right));
    }
}
void inordermorristraversal(struct node *root){
    struct node *c;
    c=root;
    while(c!=NULL){
        if(c->left==NULL){
            printf("%d ",c->data);
            c=c->right;
        }
        else{
            struct node *p;
            p=c->left;
            while(p->right!=c && p->right!=NULL){
                p=p->right;
            }
            if(p->right==NULL){
                p->right=c;
                c=c->left;
            }
            else{
                p->right=NULL;
                printf("%d ",c->data);
                c=c->right;
            }
        }
    }

}
void main(){
    struct node *root = NULL;
    createTree(&root);
    inordermorristraversal(root);
}