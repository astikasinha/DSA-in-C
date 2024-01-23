//ARRAY OPERATION IN STACK
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define size 10
#define false 0
int arr[size];
int top1,top2;
void initialize1(){
    top1==-1;
}
void initialize2(){
    top2=size;
}
int isempty1(){
    if (top1==-1){
        return true;
    }
    else{
        return false;
    }
}
void push1(int x){
    if(top1 +1 ==top2){
        printf("stack overflows");
        exit(1);
    }
    else{
        top1++;
        arr[top1]=x;
    }
}
int pop1(){
    int x;
    if(isempty1()){
        printf("stack underflow");
        exit(1);
    }
    else{
        x=arr[top1];
        top1--;
        return x;
    }
}
int isempty2(){
    if(top2==size){
        return true;
    }
    else{
        return false;
    }
}
int pop2(){
    int x;
    if(isempty2()){
        printf("stackunderflow");
        exit(1);
    }
    else{
        x=arr[top2];
        top2++;
        return x;
    }
}
void push2(int x){
    if(top1 +1==top2){
        printf("stack overflow");
        exit(1);
    }
    else{
        top2++;
        arr[top2]=x;
    }
}
void main(){
    push1(10);
    push1(20);
    push1(30);
    push1(40);
    push2(5);
    push2(15);
    push2(25);
    push2(35);
    push2(45);
    push2(55);
    
}
