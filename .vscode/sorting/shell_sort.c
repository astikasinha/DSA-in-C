#include<stdio.h>
void shellsort(int a[],int n){
    int i,j,gap;
    for(gap=n/2;gap>=1;gap=gap/2){
        for(j=gap;j<n;j++){
            for(i=j-gap;i>=0;i=i-gap){
                if(a[i+gap]>a[i]){
                    break;
                }
                else{
                    int t=a[i+gap];
                    a[i+gap]=a[i];
                    a[i]=t;
                }
            }

        }
    }
}
int main() {
    int i, n;
    printf("Number of elements in the array: ");
    scanf("%d", &n);

    int a[n]; 

    printf("Enter the elements of the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    shellsort(a,n);
    printf("shell sort\n");
    printf("Sorted array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}