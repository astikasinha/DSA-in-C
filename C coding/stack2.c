// postfix expression using stack
#include <stdio.h>
#include "astikastack.h"
int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int p = power(a, n / 2);
        if (n % 2 == 0)
        {
            return p * p;
        }
        else
        {
            return p * p * a;
        }
    }
}
int evaluation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    case '^':
        return power(a, b);
    }
}
int postfixevaluation(char postfix[])
{
    struct stack s;
    int i = 0, a, b, answer, value;
    int symbol;
    initialize(&s);
    while (postfix[i] != '\0')
    {
        symbol = postfix[i];
        i++;
        if (symbol >= '0' && symbol <= '9')
        {
            push(&s, symbol - '0');
        }
        else
        {
            b = pop(&s);
            a = pop(&s);
            value = evaluation(a, b, symbol);
            push(&s, value);
        }
    }
    answer = stacktop(&s);
    return answer;
}
int main()
{
    char postfix[50];
    int y;
    printf("enter the postfix expression");
    scanf("%s", postfix);
    y = postfixevaluation(postfix);
    printf("%d", y);
}

// string reverse using stack
#include <stdio.h>
#include "astikastack.h"
char stringreverse(char str[])
{
    struct stack s;
    initialize(&s);
    int i = 0, j = 0, x;
    char answer[50];
    while (str[i] != '\0')
    {
        push(&s, str[i]);
        i++;
    }
    while (s.top != -1)
    {
        x = pop(&s);
        answer[j] = x;
        j++;
    }
    answer[j] = '\0';
    printf("%s", answer);
}
void main()
{
    char str[50];
    printf("enter the string");
    scanf("%s", str);
    stringreverse(str);
}

// palindrome check using stack
#include <stdio.h>
#include "astikastack.h"
char palindromecheck(char str[])
{
    struct stack s;
    initialize(&s);
    int i = 0, x, y;
    while (str[i] != '\0')
    {
        x = str[i];
        push(&s, x);
        i++;
    }
    i = 0;
    while (s.top != -1)
    {
        x = stacktop(&s);
        if (x == str[i])
        {
            pop(&s);
            i++;
        }
        else
        {
            break;
        }
    }
    if (isempty(&s))
    {
        printf("palindrome");
    }
    else
    {
        printf("not palindrome");
    }
}
void main()
{
    char str[50];
    printf("enter the string");
    scanf("%s", str);
    palindromecheck(str);
}

// valid parenthesization
#include <stdio.h>
#include "astikastack.h"
char valid(char exp[])
{
    struct stack s;
    initialize(&s);
    char str[50];
    int flag = 1, i = 0, x;
    while (str[i] != '\0')
    {
        x = str[i];
        i++;
        if (x == '(')
        {
            push(&s, x);
        }
        else
        {
            if (!isempty(&s))
            {
                pop(&s);
            }
            else
            {
                flag == 0;
                break;
            }
        }
    }
    if (isempty(&s))
    {
        if (flag == 1)
        {
            printf("valid");
        }
        else
        {
            printf("invalid exp");
        }
    }
    else
    {
        printf("invalid exp");
    }
}
void main()
{
    char exp[50];
    printf("enter the expressipon");
    scanf("%s", exp);
    valid(exp);
}

// prefix expression using stack
#include <stdio.h>
#include "astikastack.h"
#include <string.h>
int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        int p = power(a, n / 2);
        if (n % 2 == 0)
        {
            return p * p;
        }
        else
        {
            return p * p * a;
        }
    }
}
int evaluation(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '%':
        return a % b;
    case '^':
        return power(a, b);
    }
}
int prefixevaluation(char postfix[])
{
    struct stack s;
    int i = 0, a, b, answer, value;
    int symbol;
    initialize(&s);
    while (postfix[i] != '\0')
    {
        symbol = postfix[i];
        i++;
        if (symbol >= '0' && symbol <= '9')
        {
            push(&s, symbol - '0');
        }
        else
        {
            a = pop(&s);
            b = pop(&s);
            value = evaluation(a, b, symbol);
            push(&s, value);
        }
    }
    answer = stacktop(&s);
    return answer;
}
int main()
{
    char postfix[50];
    int y;
    printf("enter the postfix expression");
    scanf("%s", postfix);
    strrev(postfix);
    y = prefixevaluation(postfix);
    printf("%d", y);
}

// infix to postfix expression
#include <stdio.h>
#include "infixstack.h"
int precedence(char a, char b)
{
    if (a == '^' || a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (b == '-' || b == '+')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
char infixtopostfix(char infix[])
{
    char x, symbol, postfix[100];
    int i = 0, j = 0;
    struct stack s;
    initialize(&s);
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        i++;
        if (symbol >= 'a' && symbol <= 'z' || symbol>='0' && symbol<='9')
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            while (s.top != -1 && precedence(stacktop(&s), symbol))
            {
                x = pop(&s);
                postfix[j] = x;
                j++;
            }
            push(&s, symbol);
        }
    }
    while (s.top != -1)
    {
        x = pop(&s);
        postfix[j] = x;
        j++;
    }
    postfix[j] = '\0';
    printf("%s", postfix);
}
void main()
{
    char infix[100];
    scanf("%s", infix);
    infixtopostfix(infix);
}



// infix to postfix using brackets
#include <stdio.h>
#include "infixstack.h"
int precedence(char a, char b)
{
    if (a == '(')
    {
        return 0;
    }
    else
    {
        if (b == '(')
        {
            return 0;
        }
        else
        {
            if (b == ')')
            {
                return 1;
            }
        
            else
            {
                if (a == '^' || a == '*' || a == '/' || a == '%'){
                    if (b == '^'){
                        return 0;
                        }
                        else{
                            return 1;
                            }
                }
                else{
                    if (b == '-' || b == '+'){
                        return 1;
                    }
                        else{
                            return 0;
                    }
                }
            }
        }
    }
}
char infixtopostfix(char infix[])
{
    char x, symbol, postfix[100];
    int i = 0, j = 0;
    struct stack s;
    initialize(&s);
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        i++;
        if (symbol >= 'a' && symbol <= 'z'|| symbol>='0' && symbol<='9')
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            while (s.top != -1 && precedence(stacktop(&s), symbol))
            {
                x = pop(&s);
                postfix[j] = x;
                j++;
            }
            if(symbol!=')'){
                push(&s,symbol);
            }
            else{
                pop(&s);
            }
        }
    }
    while (s.top != -1)
    {
        x = pop(&s);
        postfix[j] = x;
        j++;
    }
    postfix[j] = '\0';
    printf("%s", postfix);
}
void main()
{
    char infix[100];
    scanf("%s", infix);
    infixtopostfix(infix);
}



// infix to prefix expression
#include <stdio.h>
#include "infixstack.h"
#include<string.h>
int precedence(char a, char b)
{
    if (a == '^' || a == '*' || a == '/' || a == '%')
    {
        if (b == '^')
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        if (b == '-' || b == '+')
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}
char infixtoprefix(char infix[])
{
    char x, symbol, prefix[100];
    int i = 0, j = 0;
    struct stack s;
    initialize(&s);
    strrev(infix);
    while (infix[i] != '\0')
    {
        symbol = infix[i];
        i++;
        if (symbol >= 'a' && symbol <= 'z'||symbol>='0'&& symbol<='9')
        {
            prefix[j] = symbol;
            j++;
        }
        else
        {
            while (s.top != -1 && !precedence(symbol,stacktop(&s)))
            {
                x = pop(&s);
                prefix[j] = x;
                j++;
            }
            push(&s, symbol);
        }
    }
    while (s.top != -1)
    {
        x = pop(&s);
        prefix[j] = x;
        j++;
    }
    prefix[j] = '\0';
    strrev(prefix);
    printf("%s", prefix);
}
void main()
{
    char infix[100];
    scanf("%s", infix);
    infixtoprefix(infix);
}



#include<stdio.h>
#include"astikastack.h"
int power(int a,int n){
    if(n==0){
        return 1;
    }
    else{
        int p=power(a,n/2);
        if(n==0){
            return p*p;
        }
        else{
            return p*p*a;
        }
    }
}
int operation(int a,int b,char op){
    switch(op){
        case '+':return(a+b);
        case '-':return(a-b);
        case '*':return(a*b);
        case '/':return(a/b);
        case '%':return(a%b);
        case '^':return(power(a,b));

    }
}
int postfixevaluation(char Exp[]){
    struct stack s;
    initialize(&s);
    int i=0,x,a,b,value;
    while(Exp[i]!='\0'){
        x=Exp[i];
        i++;
        if(x>='0'&&x<='9'){
            push(&s,x-'0');
        }
        else{
            b=pop(&s);
            a=pop(&s);
            value=operation(a,b,x);
            push(&s,value);
        }
    }
    int answer=stacktop(&s);
    return answer;
}
void main(){
    char Exp[50];
    scanf("%s",Exp);
    int z;
    z=postfixevaluation(Exp);
    printf("%d",z);
}