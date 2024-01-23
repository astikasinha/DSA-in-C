#include <stdio.h>

void enqueue(int a[], int *n, int x) {
    a[(*n)+1] = x;
    (*n)=(*n)+1;
    int p = ((*n) - 1) / 2;
    int c = (*n) - 1;
    while (c > 0 && a[c] > a[p]) {
        int t = a[c];
        a[c] = a[p];
        a[p] = t;

        c = p;
        p = (p - 1) / 2;
    }
}

void maxheapify(int a[], int i, int n) {
    while ((2 * i + 1) <= n - 1) {
        int l = 2 * i + 1;
        int r = l + 1;
        int t;
        int max = l;
        if (r <= n - 1) {
            if (a[r] > a[l]) {
                max = r;
            }
        }
        if (a[max] > a[i]) {
            t = a[max];
            a[max] = a[i];
            a[i] = t;
        } else {
            break;
        }
        i = max;
    }
}

int dequeue(int a[], int *n) {
    int x = a[0];
    (*n)--;
    a[0] = a[(*n)];
    maxheapify(a, 0, (*n) - 1);
    return x;
}

int main() {
    int n, x, a[100];
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter the element to be inserted: ");
    scanf("%d", &x);
    enqueue(a, &n, x);

    printf("Array after enqueue operation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int removed = dequeue(a, &n);
    printf("Removed element from the max heap: %d\n", removed);

    printf("Array after dequeue operation:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
