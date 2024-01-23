#include <stdio.h>
#include <stdlib.h>
#define stacksize 50
struct stack
{
    int item[stacksize];
    int top;
} s;

void initialize(struct stack *s)
{
    s->top = -1;
}

int isempty(struct stack *s)
{
    return (s->top == -1);
}

int stacktop(struct stack *s)
{
    if (isempty(s))
    {
        printf("stack is empty");
        exit(1);
    }
    return s->item[s->top];
}

void push(struct stack *s, int x)
{
    if (s->top == (stacksize - 1))
    {
        printf("\nSTACK OVERFLOW");
        exit(1);
    }
    else
    {
        s->top++;
        s->item[s->top] = x;
    }
}

int pop(struct stack *s)
{
    if (isempty(s))
    {
        printf("\nSTACK UNDERFLOW");
        exit(1);
    }
    else
    {
        int x = s->item[s->top];
        s->top--;
        return x;
    }
}


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
int prcd(char a,char b){
    if(a=='^'||a=='*'||a=='/'||a=='%'){
        if(b=='^'){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        if(a=='+'||a=='-'){
            if(b=='+'||b=='-'){
                return 1;
            }
            else{
                return 0;
            }
        }
    }
}

struct node *buildexptree(char *exp){
    int i=0;
    char symb,op;
    struct node *x,*y;
    struct node *start=NULL,*p,*q;
    char opstk[20];
    int top=-1;
    initialize(opstk);
    while(exp[i]!='\0'){
        symb=exp[i];
        i++;
        if(symb>='a'&& symb<='b'||symb>='A'&&symb<='B'||symb>='0'&&symb<='9'){
            x=makenode(symb);
            x->next=start;
            start=x;
            //Push(opndstk,x);
        }
        else{
            while(top!=-1&&prcd(opstk[top],symb)){
                //op=pop(opstk);
                op=opstk[top--];
                y=makenode(op);
                p=start;
                start=start->next;
                q=start;
                start=start->next;
                y->right=p;
                y->left=q;
                push(opstk,y);
                y->next=start;
                start=y;
            }
            opstk[++top]=symb;
            //push(opstk,symb);
        }

    }
    while(top!=-1){
        op=opstk[top--];
        y=makenode(op);
        p=start;
        start=start->next;
        q=start;
        start=start->next;
        y->right=p;
        y->left=q;
        push(opstk,y);
        y->next=start;
        start=y;
    }
    return start;
}

void preordertraversal(struct node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preordertraversal(root->left);
        preordertraversal(root->right);
    }
}

void postordertraversal(struct node *root) {
    if (root != NULL) {
        postordertraversal(root->left);
        postordertraversal(root->right);
        printf("%d ", root->data);
    }
}

void inordertraversal(struct node *root) {
    if (root != NULL) {
        inordertraversal(root->left);
        printf("%d ", root->data);
        inordertraversal(root->right);
    }
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
/*int countnodes(struct node* t){
    if(t==NULL){
        return 0;
    }else{
        return 1+countnodes(t->left)+countnodes(t->right);
    }
}
int countleaf(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 1;
        }
        else{
            return countleaf(t->left)+countleaf(t->right);
        }
    }

}
int countn1(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        }
        else{
            if(t->left!=NULL && t->right!=NULL){
                return countn1(t->left)+countn1(t->right);
            }
            else{
                return 1+countn1(t->left)+countn1(t->right);
            }
        }
    }
}
int countn2(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        }
        else{
            if(t->left!=NULL && t->right!=NULL){
                return 1+countn2(t->left)+countn2(t->right);
            }
            else{
                return countn2(t->left)+countn2(t->right);
            }
        }
    }
}
int max(int x,int y){
    if(x>y){
        return x;
    }
    else{
        return y;
    }
}
int heightoftree(struct node *t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        }
        else{
            return 1+max(heightoftree(t->left),heightoftree(t->right));
        }
    }
}*/

int main() {
    /*struct node *root = NULL;
    createTree(&root);
    preordertraversal(root);
    printf("\n");
    int z= countnodes(root);
    printf("%d",z);
    printf("\n\n");
    z=countleaf(root);
    printf("%d",z);
    printf("\n\n");
    z=countn1(root);
    printf("%d",z);
    printf("\n\n");
    z=countn2(root);
    printf("%d",z);
    printf("\n\n");
    z=heightoftree(root);
    printf("%d",z);
    printf("\n\n");

    printf("Inorder Traversal: ");
    inordertraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postordertraversal(root);
    printf("\n");*/
    char expression[20];
    struct node *t;
    scanf("%s",expression);
    t=buildexptree(expression);
    preordertraversal(t);
    printf("\n\n");
    postordertraversal(t);
    printf("\n\n");
    inordertraversal(t);
    return 0;
}