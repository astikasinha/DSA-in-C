//first pattern
#include<stdio.h>
void printpattern(int n){
    int i,j,s;
    for(i=0;i<1;i++){
        for(j=1;j<=n;j++){
            for(s=0;s<j;s++){
                printf("*");
            }
            printf(" ");
        }
    }
}
void main(){
    int n;
    printf("enter the number of terms");
    scanf("%d",&n);
    printpattern(n);
}


#include<stdio.h>
void main(){
    int A[10]={1,2,3,4,5,6,7,8,9,0},i=7,x;
    printf("%u",&A[7]);
    x=i-0;
    printf("%u",A+x);

}

#include<stdio.h>
void main(){
    int A[10];
    int B[5][4],x,i=4,j=3;
    x=i-0;
    //for 1d array
    printf("%u",&A[i]);
    printf("\n%u",A+x);

    //for 2d array
    x=(i-0)*(3-0+1)+(j-0);
    printf("\n\n%u",&B[i][j]);
    printf("\n\n%u",B[0]+x);
}
//for 3d array
#include<stdio.h>
void main(){
    int C[2][3][4],i=2,j=3,k=4,x;
    x=(i-0)*(2-0+1)*(3-0+1)+(j-0)*(3-0+1)+(k-0);
    printf("\n\n\n%u",&C[i][j][k]);
    printf("\n\n\n%u",C[0][0]+x);
    }

//Matrix addition
#include<stdio.h>
void printarray(int *c[10][10],int m,int n){
    int i,j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            printf("%d\t",c[i][j]);
        }
        printf("\n");
    }
    
}
void addition(int *A[10][10],int *B[10][10],int m,int n){
    int i,j,c[10][10];
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            c[i][j]=A[i][j]+B[i][j];
        }
}
void main(){
    int A[10][10],B[10][10],c[10][10],i,j,m,n;
    printf("enter the number of rows and columns");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    printf("enter the number of rows and columns");
    scanf("%d%d",&m,&n);
    printf("enter the elements of matrix");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            scanf("%d",&B[i][j]);
        }
    }
    addition(A[0],B[0],m,n);
    printarray(c[0],m,n);
}

//tower of hanoi
#include<stdio.h>
void toh(int n, char A,char B,char C){
    if(n==1){
        printf("move disk 1 from %c to %c",A,C);
        return;
    }
    toh(n-1,A,C,B);
    printf("\nmove disc %d from rod %c to rod %c\n",n,A,C);
    toh(n-1,C,B,A);
}
int main(){
    int n;
    char A,B,C;
    printf("enter the number of discks");
    scanf("%d",&n);
    toh(n,'A','B','C');
    return 0;
}