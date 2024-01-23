#include<stdio.h>
int catalonnumber(int n){
    int i,j;
    int DAT[1000]={0};
    int a[n][n+1];
    for(i=0;i<n;i++){
        for(j=0;j<n+1;j++){
            a[i][j+i+2]=0;
        }
    }
    for(i=0;i<n;i++){
        a[i][0]=1;
    }
    a[0][1]=1;
    DAT[0]=1;
    DAT[1]=1;
    for(i=1;i<n;i++){
        for(j=0;j<=i+1;j++){
            a[i][j]=a[i][j-1]+a[i-1][j];
        }
        DAT[i+1]=a[i][i+1];
    }
    printf("The nth catalon term is %d ",DAT[n]);
    printf("\n\n");
    
    printf("displaying the catalon terms till the nth catalon term:-\n");
    for(i=0;i<=n;i++){
        printf("%d ",DAT[i]);
    }
}
void main(){
    int n;
    printf("enter the nth catalon term:");
    scanf("%d",&n);
    catalonnumber(n);

}