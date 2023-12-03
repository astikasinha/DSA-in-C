// sieve eratosthenes
#include <stdio.h>
int primesieve(int n)
{
    int prime[101] = {0};
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (prime[i] == 0)
        {
            printf("%d ", i);
        }
    }
}
int main()
{
    int n;
    printf("enter the number upto which you want to find prime numbers");
    scanf("%d", &n);
    primesieve(n);
}

// prime factorisation using sieve
#include <stdio.h>
void primefactor(int n)
{
    int a[100] = {0};
    for (int i = 2; i <= n; i++)
    {
        a[i] = i;
    }
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == i)
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (a[j] == j)
                {
                    a[j] = i;
                }
            }
        }
    }
    while (n != 1)
    {
        printf("%d\t", a[n]);
        n = n / a[n];
    }
}
void main()
{
    int n;
    printf("enter the number");
    scanf("%d", &n);
    primefactor(n);
}

// magic square
#include <stdio.h>
int main()
{
    int a[100][100] = {0};
    int n, r, c, tr, tc,k;
    printf("enter the order of magic square");
    scanf("%d", &n);
    c = n / 2;
    a[0][c] = 1;
    k = a[0][c];
    tr = r;
    tr = c;
    while (k < n * n)
    {
        tr--;
        if (tr < 0)
        {
            tr = n - 1;
        }
        tc++;
        if (tc > n - 1)
        {
            tc = 0;
        }
        if (a[tr][tc] == 0)
        {
            a[tr][tc] = ++k;
            r = tr;
            c = tc;
        }
        else
        {
            a[r + 1][c] = ++k;
            r = r + 1;
        }
        printf("%d\t",a[tr][tc]);
    }
}
