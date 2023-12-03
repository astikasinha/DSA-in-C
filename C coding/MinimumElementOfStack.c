#include<stdio.h>
#include"astikastack.h"
int main(){
    initialize(&s);
    struct stack s1;
    initialize(&s1);
    push(&s,400);
    push(&s,200);
    push(&s,278);
    push(&s,900);
    push(&s,789);
    int x=pop(&s);
    int min=x;
    while(!isempty(&s)){
        x=pop(&s);
        if(x<min){
            min=x;
        }
    push(&s1,x);
    }
    while(!isempty(&s1)){
        x=pop(&s1);
        push(&s,x);
    }
    printf("%d",min);

}

