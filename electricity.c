//ELECTRICITY PROGRAM 9
#include<stdio.h>
void main(){
    int bill=0,i,unit;
    float total;
    printf("enter the units of consumption");
    scanf("%d",&unit);
    if(unit>200&&unit<=400){
        bill=unit*6;
    }
    if(unit>400&&unit<=600){
        bill=unit*7;
    }
    if(unit>600){
        bill=unit*8;
    }
    bill=bill+220;
    total=0.05*bill;
    printf("the total electricity bill is %f",total);
}

//mediclaim insurance PROGRAM 10
#include<stdio.h>
void main(){
    int yob,count;
    char mar,gen;
    float sum;
    printf("enter the date of birth,marital status,gender");
    scanf("%d%c%c",&yob,&mar,&gen);
    count=2023-yob;
    if(count<30){
        sum=1000;
    }
    if(count>=30&&count<40){
        sum=1500;
    }
    if(count>=40&&count<50){
        sum=2000;
    }
    if(count>=50&&count<60){
        sum=2500;
    }
    if(count>=60&&count<70){
        sum=3000;
    }
    if(count>70){
        printf("insurance cannot be taken");
    }
    if(gen='F'){
        sum=sum-(0.2*sum);
    }
    if(mar='U'){
        sum=sum-(0.1*sum);
    }
    sum=sum+(0.18*sum);
    printf("the total premium sum is %f",sum);
}

//day for a given date
#include<stdio.h>
void main(){
    int days,year,i,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},realyear,l,date,month,x;
    printf("enter the date");
    scanf("%d",&date);
    printf("enter the month");
    scanf("%d",&month);
    printf("enter the year");
    scanf("%d",&year);
    realyear=year-1;
    days=realyear*365;
    l=realyear/4-realyear/100+realyear/400;
    days=days+l;

    for(i=1;i<=m-1;i++){
        days=days+m[i];
    }
    if(year%4==0&&year%100!=0||year%400==0){
        days=days+1;
    }
    days=days+date;

    x=days%7;
    switch(x){
        case 1:printf("monday");
               break;
        case 2:printf("tuesdasy");
               break;
        case 3:printf("wednesday");
               break;
        case 4:printf("thursday");
               break;
        case 5:printf("friday");
               break;
        case 6:printf("saturday");
               break;
        case 0:printf("sunday");
               break;

    }
}

#include<stdio.h>
Traverse(int A[],int N){
    int i;
    for(i=0;i<N;i++){
        printf("%d",A[i]);
    }
    /************************************/

    void MergeArray(int A[],int N,int B[],int M){
        int i=0,j=0,k=0;
        int C[13];
        while(i<N&&j<M)
    }
}
