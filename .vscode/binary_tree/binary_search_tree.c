#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *makenode(int x) {
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
struct node *BSTinsert(struct node *t,int key){
    if(t==NULL){
        t=makenode(key);
    }
    else{
        if(key<t->data){
            t->left=BSTinsert(t->left,key);
        }
        else{
            t->right=BSTinsert(t->right,key);
        }
    }
    return t;
}
struct node *bstinsert(struct node **t,int key){
    struct node *p,*q,*r;
    r=makenode(key);
    p=(*t);
    q=NULL;
    if((*t)!=NULL){
        while(p!=NULL){
            q=p;
            if(key<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(key<q->data){
            q->left=r;
        }
        else{
            q->right=r;
        }

    }
    else{
        (*t)=r;
    }
    return *t;
}
void inordertraversal(struct node *root) {
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
}
struct node *BSTsearch(struct node **t,int key){
    while((*t)!=NULL){
        if(key==(*t)->data){
            return (*t);
        }
        else{
            if(key<(*t)->data){
                (*t)=(*t)->left;
            }
            else{
                (*t)=(*t)->right;
            }
        }
    }
    return NULL;
}
struct node *BSTsearchmin(struct node *t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}
struct node *BSTsearchmax(struct node *t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t;
}
int main(){
    struct node *root=NULL;
    int key;
    root=bstinsert(&root,100);
    root=bstinsert(&root,10);
    root=bstinsert(&root,50);
    root=bstinsert(&root,60);
    root=bstinsert(&root,40);
    root=bstinsert(&root,5);
    root=bstinsert(&root,90);
    inordertraversal(root);
    printf("\n");
    printf("Enter the element to  be searched");
    scanf("%d",&key);
    struct node *ans=BSTsearch(&root,key);
    if(ans!=NULL){
        printf("we found element %d at %d",key,ans);
    }
    else{
        printf("Element is not found");
    }
    printf("\n");
    struct node*max=BSTsearchmax(root);
    printf("Maximum element : %d\n",max->data);
    struct node*min=BSTsearchmin(root);
    printf("Minimum element : %d",min->data);

}