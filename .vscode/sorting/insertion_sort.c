#include <stdio.h>

void insertionsort(int a[], int n) {
    int i, j, k;
    for (i = 1; i < n; i++) {
        k = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > k) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = k;
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

    insertionsort(a, n);
    printf("insertion sort\n");
    printf("Sorted array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", a[j]);
    }

    return 0;
}
