#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*QuickSort is a sorting algorithm based on the Divide and Conquer algorithm that picks an element as a pivot 
and partitions the given array around the picked pivot by placing the pivot in its correct position in the sorted array.*/
int partition(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int pivot = a[low];
    do {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i < j) {
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    } while (i < j);

    int s = a[j];
    a[j] = a[low];
    a[low] = s;
    return j;
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}
void medianquicksort(int a[],int low,int high,int n){
    int mid=(low+high)/2;
    int t=a[0];
    a[0]=a[mid];
    a[mid]=t;
    quicksort(a,0,n-1);

}
void randomizedquicksort(int a[],int low,int high,int n){
    int rn=rand()%(high+low-1)+low;
    int i=low;
    int t=a[0];
    a[0]=a[rn];
    a[rn]=t;
    quicksort(a,0,n-1);
    


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

    quicksort(a,0,n-1);
    printf("quick sort\n");

    printf("Sorted array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}


