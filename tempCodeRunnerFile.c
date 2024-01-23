#include <stdio.h>
int main()
{
    int a[20][20] = {0};
    int n, r, c, tr, tc,k;
    printf("enter the order of magic square");
    scanf("%d", &n);
    c = n / 2;
    r=0;
    k=1;
    a[r][c]=k;
    while (k <= n * n)
    {
        k++;
        tr=r;
        tc=c;
        tr--;
        tc++;
        if (tr==-1)
        {
            tr = n - 1;
        }
        if (tc== n)
        {
            tc = 0;
        }
        if (a[tr][tc]!= 0)
        {
            a[r+1][c] =k;
            r++;
        }
        else
        {
            a[tr][tc] =k;
            r =tr;
            c=tc;
        }
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                printf("%d ",a[i][j]);
            }
        printf("\n");
    }
}
