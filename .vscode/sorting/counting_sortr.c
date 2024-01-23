#include <stdio.h>
#include<stdlib.h>

void countingsort(int a[], int n, int k, int ans[]) {
    int c[k + 1];

    // Initialize the counting array with zeros
    for (int i = 0; i <= k; i++) {
        c[i] = 0;
    }

    // Count the occurrences of each element in the array
    for (int i = 0; i < n; i++) {
        c[a[i]] = c[a[i]] + 1;
    }

    // Modify the counting array to store the actual position of the elements in the sorted array
    for (int i = 1; i <= k; i++) {
        c[i] = c[i] + c[i - 1];
    }

    // Build the sorted array
    for (int i = n - 1; i >= 0; i--) {
        ans[c[a[i]] - 1] = a[i];
        c[a[i]] = c[a[i]] - 1;
    }
}
void countingsortforradix(int a[], int n, int exp) {
    int* ans = (int *)malloc(n * sizeof(int));
    int* c = (int *)calloc(10, sizeof(int));

    for (int i = 0; i < n; i++) {
        c[(a[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        c[i] = c[i] + c[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        ans[c[(a[i] / exp) % 10] - 1] = a[i];
        c[(a[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        a[i] = ans[i];
    }

    free(c);
    free(ans);
}

int* radixsort(int a[], int n, int d) {
    int exp = 1;
    for (int i = 0; i < d; i++) {
        countingsortforradix(a, n, exp);
        exp = exp * 10;
    }
    return a;
}

int main() {
    int n, k;

    printf("Number of elements in the array: ");
    scanf("%d", &n);

    int* a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the number of digits in the largest number: ");
    scanf("%d", &k);

    int* sortedArray = radixsort(a, n, k);

    printf("Sorted array: ");
    for (int j = 0; j < n; j++) {
        printf("%d ", sortedArray[j]);
    }

    free(a);
    
    return 0;
}
