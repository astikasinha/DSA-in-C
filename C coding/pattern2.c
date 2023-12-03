#include<stdio.h>
void main(){
    int i,j,k=1,n;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d\t",k);
            k++;
        }
        printf("\n");
    }

}

//day 3 ps 2
#include<stdio.h>
void main(){
    int i,j,n;
    printf("enter the number of lines");
    scanf("%d",&n);
    int k=0;
    for(i=1;i<=n;i++){
        for(int k=1;k<=n-i;k++){
            printf(" ");
        }
        k=i;
        for(j=1;j<=i;j++,k++)
        {
            printf("%d ",k);
        }
                printf("\n");
    }
    }


//day ps 3
#include<stdio.h>
void main(){
    int i,j,k,n,m=1;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%c",'A'+i-1);
        }
        printf("\n");
    }
}

//day 3 ps 4
#include<stdio.h>
void main(){
    int i,j,k,n;
    char m='A';
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%c",m);
            m=m+1;
        }
        printf("\n");
    }
}

//day 3 ps 5
#include<stdio.h>
void main(){
    int i,j,n;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=n;i>=1;i--){
        for(j=i;j<=n;j++){
            printf("%c",j+'A'-1);
        }
        printf("\n");
    }
}

//day 3 ps 7
#include<stdio.h>
void main()
{
        int i,n,j;
        
        printf("Enter the no of lines\n");
        scanf("%d",&n);
        
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++)
            {
                printf("  ");
            }
            for(j=i;j>0;j--)
            {
                printf(" %d",j);
            }
            for(j=2;j<=i;j++)
            {
                printf(" %d",j);
            }
            printf("\n");
        }
}


//day 3 ps 8
#include<stdio.h>
void main()
{
        int i,n,j;
        printf("Enter the no of lines\n");
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++)
            {
                printf("  ");
            }
            for(j=i;j>0;j--)
            {
                printf(" *");
            }
            for(j=2;j<=i;j++)
            {
                printf(" *");
            }
            printf("\n");
        }
}

//day3 ps 10
#include<stdio.h>
void main(){
    int i,j,k,n,m;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
			for(int j=0;j<i;j++){
			    printf(" ");
			}
			for(int k=0;k<n-i;k++){
				printf("* ");
			}
			printf("\n");
    }
	for(int i=n-1;i>=1;i--){
	    for(int j=1;j<i;j++){
	        printf(" ");
	        
	    }
	    for(int k=i;k<=n;k++){
	        printf("* ");
	        
	    }
	    printf("\n");
	}
}


//new pattern
#include<stdio.h>
void main(){
    int i,j,k,n,m;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(int i=1;i<n-i;i++){
			for(int j=0;j<i;j++){
			    printf(" ");
			}
			for(int k=1;k<=n;k++){
			    printf("* ");
			}
			printf("\n");
    }
	
}

//new pattern
#include<stdio.h>
void main(){
    int i,j,k,n,m=1;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i;j++){
            printf(" ");
            }
        for(j=1;j>0;j--){
            printf(" %d",j);
            }
        for(j=2;j<=i;j++){
            printf(" %d",j);
            }
        printf("\n");
        }
        
}

//half butterfly
#include<stdio.h>
void main(){
    int i,j,k,n,m=1;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("*");
            }
        for(k=1;k<=2*(n-i);k++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
    
}


//day 3 ps 11
#include<stdio.h>
void main(){
    int i,j,k,n,m=1;
    printf("enter the number of lines");
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            printf("%d",j);
            }
        for(k=1;k<=2*(n-i);k++){
            printf(" ");
        }
        for(j=1;j<=i;j++){
            m=i;
            printf("%d",m-1);
            m--;    
        }
        printf("\n");
    }
}
// Tower of Hanoi program in C using Recursion
#include<stdio.h>
void toH(int n, char rodA, char rodC, char rodB)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c",rodA ,rodC );
		return;
	}
	toH(n-1, rodA, rodB, rodC);
	printf("\n Move disk %d from rod %c to rod %c", n, rodA, rodC);
	toH(n-1, rodB, rodC,rodA);
}

int main()
{
	int no_of_disks ;
	printf("Enter number of disks: ");
	scanf("%d", &no_of_disks);
	toH(no_of_disks, 'A','C','B'); 
	return 0;
}


