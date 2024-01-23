#include<stdio.h>
void selectionsort(int a[],int n){
    int i,j,min;
    for(i=0;i<n-2;i++){//n-2 isliye qki last wala emlement already bada hokar wo last tak pahunch jaata hai last iterations tak
        min=i;
        for(j=i+1;j<=n-1;j++){//this loop sets minimum value of the arrray
            if(a[j]<a[min]){//this does the comparison of all the elements of the array
                min=j;//this sets the minimum index that is the index of the elemnt that has minimum value
            }
        }
        int t=a[i];//ye min aur first element after each iteration k baad ko swaqp krta hai
        a[i]=a[min];
        a[min]=t;

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

    selectionsort(a,n);

    printf("Sorted array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}
