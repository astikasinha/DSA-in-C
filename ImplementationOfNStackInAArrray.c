#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
#define size 9

int arr[size];
int item[size];
int top[3];

void initialize(int n, int m) {
    for (int i = 0; i < 3; i++) {
        top[i] = (n / m) * i - 1;
    }
}

int isempty(int i, int n, int m) {
    if (top[i] == (n / m) * i - 1) {
        return true;
    } else {
        return false;
    }
}

void push(int i, int x, int n, int m) {
    if (top[i] == (n / m) * (i + 1) - 1) {
        printf("Stack %d overflow\n", i);
        exit(1);
    } else {
        top[i]++;
        item[top[i]] = x;
        printf("Pushed into Stack %d: %d\n", i, item[top[i]]);
    }
}

int pop(int i, int n, int m) {
    int x;
    if (top[i] == (n / m) * i - 1) {
        printf("Stack %d underflow\n", i);
        exit(1);
    } else {
        x = item[top[i]];
        top[i]--;
        printf("Popped from Stack %d: %d\n", i, x);
        return x;
    }
}

int main() {
    int n = 9, m = 3;
    initialize(n, m);

    push(0, 1, n, m);
    push(1, 2, n, m);
    push(2, 3, n, m);
    push(0, 1, n, m);
    push(1, 2, n, m);
    push(2, 3, n, m);
    push(0, 1, n, m);
    push(1, 2, n, m);
    push(2, 3, n, m);
    pop(0, n, m);
    pop(0, n, m);
    pop(0, n, m);
    pop(0, n, m);

    return 0;
}
