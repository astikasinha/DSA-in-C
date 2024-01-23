#include <stdio.h>
struct time
{
    int hour;
    int minute;
    int second;
};
int main()
{
    int x, y, z;
    struct time T1 = {5, 24, 36};
    struct time T2 = {11, 54, 58};
    struct time T3;
    int carry = 0;
    printf("%d::%d::%d", T1.hour, T1.minute, T1.second);
    printf("%d::%d::%d", T2.hour, T2.minute, T2.second);
    x = T1.second + T2.second;
    carry = x / 60;
    x = x % 60;

    y = T1.minute + T2.minute + carry;
    carry = y / 60;
    y = y % 60;

    z = T1.hour + T2.hour + carry;

    T3.hour = z;
    T3.minute = y;
    T3.second = x;
    printf("\n%d %d %d", T3.hour, T3.minute, T3.second);
}

// complex multiplication
#include <stdio.h>
struct multiplication
{
    int real;
    int imaginary;
};
int main()
{
    struct multiplication num1 = {2, 3};
    struct multiplication num2 = {3, 4};
    struct multiplication num3;
    int x, y;
    x = (num1.real * num2.real) - (num1.imaginary * num2.imaginary);
    y = (num1.real * num2.imaginary) + (num2.real * num1.imaginary);
    num3.real = x;
    num3.imaginary = y;
    printf("%d+i%d", num3.real, num3.imaginary);
}

// complex subtarction
#include <stdio.h>
struct subtraction
{
    int real;
    int imaginary;
};
int main()
{
    struct subtraction num1 = {2, 3};
    struct subtraction num2 = {3, 4};
    struct subtraction num3;
    int x, y;
    x = num1.real - num2.real;
    y = num1.imaginary - num2.imaginary;
    num3.real = x;
    num3.imaginary = y;
    printf("%d-i%d", num3.real, num3.imaginary);
}

// complex addition
#include <stdio.h>
struct addition
{
    int real;
    int imaginary;
};
int main()
{
    struct addition num1 = {2, 3};
    struct addition num2 = {3, 4};
    struct addition num3;
    int x, y;
    x = num1.real + num2.real;
    y = num1.imaginary + num2.imaginary;
    num3.real = x;
    num3.imaginary = y;
    printf("%d+i%d", num3.real, num3.imaginary);
}

// height
#include <stdio.h>
struct height
{
    int feet;
    int inches;
};
int main()
{
    struct height num1 = {2, 3};
    struct height num2 = {3, 4};
    struct height num3 = {6, 7};
    struct height num4;
    int x, y;
    x = num1.feet + num2.feet + num3.feet;
    y = num1.inches + num2.inches + num3.inches;
    num4.feet = x;
    num4.inches = y;
    printf("%d %d", num4.feet, num4.inches);
}

// function method for structure
#include <stdio.h>
struct time
{
    int hour;
    int minute;
    int second;
};
typedef struct time time;

void Addtime(time T1, time T2)
{
    int x, y, z, carry = 0;
    time T3;
    x = T1.second + T2.second;
    carry = x / 60;
    x = x % 60;

    y = T1.minute + T2.minute + carry;
    carry = y / 60;
    y = y % 60;

    z = T1.hour + T2.hour + carry;

    T3.hour = z;
    T3.minute = y;
    T3.second = x;
    printf("\n%d %d %d", T3.hour, T3.minute, T3.second);
}
int main()
{
    int x, y, z;
    time T1 = {5, 24, 36};
    time T2 = {11, 54, 58};
    time T3;
    int carry = 0;
    printf("%d::%d::%d", T1.hour, T1.minute, T1.second);
    printf("%d::%d::%d", T2.hour, T2.minute, T2.second);
    Addtime(T1, T2);
}

// program 1 lab 9
#include <stdio.h>
struct s
{
    int marks;
    char name[50];
}s[6];
void main()
{
    int i,j,k,y,total=0,comp[6],t,x;
    float percent;
    printf("enter the name");
    for(i=0;i<1;i++){
        gets(s[i].name);
    }
    printf("enter the marks of student");
    for(i=0;i<6;i++){
         scanf("%d",&s[i].marks);
         total=total+s[i].marks;
         comp[i]=s[i].marks;
    }
    x=s[0].marks;
    for(i=1;i<6;i++){
        if(x>s[i].marks){
            t=s[i].marks;
            s[i].marks=x;
            x=t;
        }
    }
    y=s[1].marks;
    for(i=2;i<6;i++){
        if(y>s[i].marks){
            k=s[i].marks;
            s[i].marks=y;
            y=k;
        }
    }
    total=total-comp[0]-comp[1];
    percent=total/4.0;
    printf("%f",percent);
    if(percent>95.0){
        printf("eligible");
    }
    else{
        printf("not eligible");
    }
}


//program 2 day 9
#include <stdio.h>
struct s
{
    int marks;
    int age,roll;
    char name[50];
}s[6];
void main()
{
    int i,j;
    printf("enter the name");
    for(i=0;i<6;i++){
        gets(s[i].name);
    }
    printf("enter the marks of student");
    for(i=0;i<6;i++){
         scanf("%d%d%d",&s[i].roll,&s[i].age,&s[i].marks);
    }
    for(i=0;i<6;i++){
        puts(s[i].name);
        printf(s[i].roll,s[i].age,s[i].marks);
    }
}


#include<stdio.h>
struct student{
    char name[50];
    int roll;
    float p,c,m;
}s[5];
void main(){
    int i;
    float total[5],percent;
    printf("enter the details");
    for(i=0;i<5;i++){
        gets(s[i].name);
        scanf("%d%f%f%f",&s[i].roll,&s[i].p,&s[i].c,&s[i].m);
    }
    for(i=0;i<5;i++){
        total[i]=s[i].p+s[i].c+s[i].m;
        percent=total[i]/3.0;
        printf("%f",percent);
    }
}


//STACK OPERATION
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define STACKSIZE 10
#define false 0
struct stack{
    int item[STACKSIZE];
    int top;
};
struct stack s;
void Initialize(){
    s.top=-1;
}
int isempty(){
    if(s.top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(int x){
    if(s.top==STACKSIZE-1){
        printf("stack overflows");
    }
    else{
        s.top++;
        s.item[s.top]=x;
    }
}
int pop(){
    if(isempty()){
        printf("underflow");
        exit(1);
    }
    else{
        int x=s.item[s.top];
        s.top--;
        return x;
    }
}
int stacktop(){
    int top;
    int x=s.item[s.top];
    top--;
    return x;
}
void main(){
    int x;
    Initialize();
    push(100);
    push(200);
    push(278);
    push(900);
    push(789);
    x=pop();
    printf("popped element is %d\n",x);
    push(890);
    push(567);
    push(765);
    x=pop();
    printf("popped element is %d\n",x);
    push(879);
    push(678);
    push(897);
    push(56);
    push(864);
}



//STACK OPERATION
#include<stdio.h>
#include<stdlib.h>
#define true 1
#define STACKSIZE 10
#define false 0
struct stack{
    int item[STACKSIZE];
    int top;
};
void Initialize(struct stack *s){
    s->top=-1;
}
int isempty(struct stack *s){
    if(s->top==-1){
        return true;
    }
    else{
        return false;
    }
}
void push(struct stack *s,int x){
    if(s->top==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    else{
        s->top++;
        s->item[s->top]=x;
    }
}
int pop(struct stack *s){
    if(isempty(s)){
        printf("underflow");
        exit(1);
    }
    else{
        int x=s->item[s->top];
        s->top--;
        return(x);
    }
}
int stacktop(struct stack *s){
    int top;
    int x=s->item[s->top];
    top--;
    return x;
}
void main(){
    struct stack s;
    int x,n;
    scanf("%d",&n);
    Initialize(&s);
    while(n!=0){
        x=n%2;
        push(&s,x);
        n=n/10;
    }
    while(!isempty(&s)){
        x=pop(&s);
        printf("%d",x);
        
        
    }
    
   
}




//structure program 11
#include<stdio.h>
struct date{
    int day,month,year;
}s[2];
void main(){
    int i;
    printf("enter the day");
    for(i=0;i<2;i++){
        scanf("%d%d%d",&s[i].day,&s[i].month,&s[i].year);
    }
    if(s[0].day==s[1].day&&s[0].month==s[1].month&&s[0].year==s[1].year){
        printf("equal");
    }
    else{
        printf("not equal");
    }

}

//structure program 10
#include<stdio.h>
struct bank{
    char name[50];
    int account,balance;
}s[20];
void main(){
    int i;
    for(i=0;i<3;i++){
        gets(s[i].name);
        scanf("%d%d",&s[i].account,&s[i].balance);
    }
    for(i=0;i<3;i++){
        if(s[i].balance<200){
            puts(s[i].name);
        }
        if(s[i].balance>1000){
            s[i].balance+=100;
            printf("%d",s[i].balance);
        }
    }
}

//structure program 12
#include<stdio.h>
struct employee{
    int hrs,salary;
    char name[50];
}s[10];
void main(){
    int i;
    printf("enter the name,hours of work per day,salary");
    for(i=0;i<10;i++){
        gets(s[i].name);
        scanf("%d%d",&s[i].hrs,&s[i].salary);
    }
    for(i=0;i<10;i++){
        if(s[i].hrs>8){
            s[i].salary=s[i].salary+50;
        }
        puts(s[i].name);
        printf("salary of %d is %d",i+1,s[i].salary);
    }
}

//structure progream 13
#include<stdio.h>
struct book{
    int number;
    char author[50],title[50],flag[10];
}s[10];
void main(){
    int x[10];
    switch(n){
        case value 1:for(i=0;i<10;i++){
            printf("book's author name is:");
            puts(s[i].author);
            printf("book's title is:");
            puts(s[i].title);
            printf("\naccession number is %d",s[i].number);
            break;
        }
        case value 2:for(i=0;i<10;i++){
            printf("book's author name is:");
            gets(s[i].author);
            printf("book's title is:");
            gets(s[i].title);
            printf("\naccession number is:");
            scanf("%d",&s[i].number);
            break;
            }
        case value 3:printf("enter the first name of the author you want to search for");
                     scanf("%c",&x);
                     for(i=0;i<10;i++){
                        if(s[i].author==x){
                            puts(s[i].title);
                            }
                        else{
                            printf("book not in library");
                            } 
                    }
        case value 4:printf("enter the first name of the title of book you want to search for");
                     scanf("%c",&y);
                     int c=0;
                     for(i=0;i<10;i++){
                        if(s[i].title==x){
                            c=c+1;
                            }
                        else{
                            printf("book not in library");
                            }
                    }
                    if(c>1){
                        printf("%d",c);
                    }
        case value 5:printf("Total number of books in the library");
                     int c=0;
                     for(i=0;i<10;i++){
                        if(s[i].number>1){
                            c=c+1;
                        }
                    }
                    printf("%d",c);
        case value 6:printf("To issue a book");
}

//decimal to hexadecimal
#include<stdio.h>
#include"astikastack.h"
int main(){
    char DAT[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    struct stack s;
    initialize(&s);
    int n,rem;
    scanf("%d",&n);
    while(n!=0){
        rem=n%16;
        push(&s,rem);
        n/=16;
    }
    while(s.top!=-1){
        int y=pop(&s);
        printf("%c",DAT[y]);
    }
}

//decimal to binary
#include<stdio.h>
#include"astikastack.h"
int main(){
    struct stack s;
    initialize(&s);
    int n,rem;
    scanf("%d",&n);
    while(n!=0){
        rem=n%2;
        push(&s,rem);
        n/=2;
    }
    while(s.top!=-1){
        int y=pop(&s);
        printf("%d",y);
    }
}

//decimal to octal
#include<stdio.h>
#include"astikastack.h"
int main(){
    struct stack s;
    initialize(&s);
    int n,rem;
    scanf("%d",&n);
    while(n!=0){
        rem=n%8;
        push(&s,rem);
        n/=8;
    }
    while(s.top!=-1){
        int y=pop(&s);
        printf("%d",y);
    }
}
























