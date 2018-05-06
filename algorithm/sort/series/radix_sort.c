#include "sort.h"

int radix(int d)
{
    int r = 0;
    while (d > 0)
    {
        ++r;
        d = d / 10;
    }

    return r;
}

int digit(int d, int c)
{
    while (c-- > 0)
    {
        d = d / 10;
    }

    return d % 10;
}

void sort(int a[], int n)
{
    int t = min(a, n);
    offset(a, n, -t);

    int c[n];
    for (int i = 0; i < n; ++i)
    {
        c[i] = radix(a[i]);
    }

    int m = max(c, n);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            c[j] = digit(a[j], i);
        }

        for (int j = 0; j < n - 1; ++j)
        {
            for (int k = n - 1; k > j; --k)
            {
                if (c[k] < c[k - 1])
                {
                    swap(&c[k], &c[k - 1]);
                    swap(&a[k], &a[k - 1]);
                }
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
