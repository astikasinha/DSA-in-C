#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define size 8
struct cqueue{
    char item[size];
    int front;
    int rear;
};
struct cqueue cq;
void initialize(){
    cq.rear=0;
    cq.front=0;
}
int isempty(){
    if(cq.front==cq.rear){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void encqueue(char x){
    if((cq.rear+1)%size==cq.front){
        printf("OVERFLOW");
        exit(1);
    }
    else{
        cq.rear=(cq.rear+1)%size;
        cq.item[cq.rear]=x;
    }
}
char decqueue(){
    char x;
    if(isempty()){
        printf("underflows");
        exit(1);
    }
    else{
        cq.front=(cq.front+1)%size;
        x=cq.item[cq.front];
        return x;
    }
}
void main(){
    initialize();
    encqueue('A');
    encqueue('B');
    encqueue('C');
    char x=decqueue();
    encqueue('X');
    encqueue('Y');
    x=decqueue();
    encqueue('P');
    encqueue('Q');
    printf("deleted item is %c",x);
}

