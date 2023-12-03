#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define size 8
struct queue{
    char item[size];
    int front;
    int rear;
};
struct queue q;
void initialize(){
    q.rear=-1;
    q.front=0;
}
int isempty(){
    if((q.rear-q.front+1)==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void enqueue(char x){
    if(q.rear==size-1){
        printf("OVERFLOW");
        exit(1);
    }
    else{
        q.rear=q.rear+1;
        q.item[q.rear]=x;
    }
}
char dequeue(){
    char x;
    if(isempty()){
        printf("underflows");
        exit(1);
    }
    else{
        x=q.item[q.front];
        q.front++;
        return x;
    }
}
void main(){
    initialize();
    enqueue('A');
    enqueue('B');
    enqueue('C');
    enqueue('D');
    enqueue('E');
    char x=dequeue();
    printf("deleted item is %c",x);
}

