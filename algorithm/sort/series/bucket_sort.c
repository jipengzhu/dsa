#include <stdlib.h>
#include "sort.h"

void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
                swap(&a[j], &a[j - 1]);
        }
    }
}

void bucketSort(int a[], int n, int k)
{
    int t = min(a, n);
    offset(a, n, -t);

    int s = max(a, n) / k + 1;

    int b[s][n];
    int c[s];

    for (int i = 0; i < s; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            b[i][j] = 0;
        }
    }

    for (int i = 0; i < s; ++i)
    {
        c[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        int v = a[i];
        int j = v / k;
        b[j][c[j]++] = v;
    }

    for (int i = 0; i < s; ++i)
    {
        bubbleSort(b[i], c[i]);
    }

    int i = 0;
    for (int j = 0; j < s; ++j)
    {
        for (int k = 0; k < c[j]; ++k)
        {
            a[i++] = b[j][k];
        }
    }

    offset(a, n, t);
}

void sort(int a[], int n)
{
    bucketSort(a, n, 3);
}

int main()
{
    int n = 9;
    int a[n];

    array(a, n);
    show(a, n);
    sort(a, n);
    show(a, n);
}
