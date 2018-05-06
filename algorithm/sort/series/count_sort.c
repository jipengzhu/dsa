#include <stdlib.h>
#include "sort.h"

void sort(int a[], int n)
{
    int t = min(a, n);
    offset(a, n, -t);

    int m = max(a, n) + 1;
    int c[m];

    for (int i = 0; i < m; ++i)
    {
        c[i] = 0;
    }

    for (int i = 0; i < n; ++i)
    {
        int v = a[i];
        c[v] = c[v] + 1;
    }

    int i = 0;
    for (int v = 0; v < m; ++v)
    {
        int k = c[v];
        if (k > 0)
        {
            for (int j = 0; j < k; ++j)
            {
                a[i++] = v;
            }
        }
    }

    offset(a, n, t);
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
