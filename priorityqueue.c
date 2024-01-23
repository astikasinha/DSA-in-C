#include <stdio.h>
#include <stdlib.h>
void insertarray(int a[], int *n, int pos, int num) {
    if (*n < 10) {
        int i;
        for (i = (*n) - 1; i >= pos - 1; i--) {
            a[i + 1] = a[i];
        }
        a[pos - 1] = num;
        (*n)++;
    } else {
        printf("Array is full. Cannot insert.\n");
    }
}

int deletearray(int a[], int *n, int pos) {
    if (*n > 0 && pos >= 1 && pos <= *n) {
        int x = a[pos - 1];
        for (int i = pos; i < (*n); i++) {
            a[i - 1] = a[i];
        }
        (*n)--;
        return x;
    } else {
        printf("Invalid position for deletion.\n");
        return -1;  // Return a sentinel value to indicate failure
    }
}

// ascending array
void pqascInsert(int a[], int *n, int num) {
    int i = 0;
    while (i < (*n) && num >= a[i]) {
        i++;
    }
    insertarray(a, n, i + 1, num);
}

// ascending queue
int pqascDelete(int a[], int *n) {
    if (*n > 0) {
        int x = a[0];
        deletearray(a, n, 1);
        return x;
    } else {
        printf("Queue is empty. Cannot delete.\n");
        return -1;  // Return a sentinel value to indicate failure
    }
}

// descending queue
void pqdesInsert(int b[], int *n, int num) {
    int i = 0;
    while (i < (*n) && num < b[i]) {
        i++;
    }
    insertarray(b, n, i + 1, num);
}

// descending queue
int pqdesDelete(int b[], int *n) {
    if (*n > 0) {
        int x = b[(*n) - 1];
        deletearray(b, n, *n);
        return x;
    } else {
        printf("Queue is empty. Cannot delete.\n");
        return -1;  // Return a sentinel value to indicate failure
    }
}

int main() {
    int a[10], b[10];
    int n = 0;
    int num = 15;

    for (int i = 9; i>=0; i--) {
        pqdesInsert(b, &n, num);
        num--;
    }

    while (n > 0) {
        int highpriority = pqdesDelete(b, &n);
        printf("%d ", highpriority);
    }

    return 0;
}


/*gcd function
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}*/
