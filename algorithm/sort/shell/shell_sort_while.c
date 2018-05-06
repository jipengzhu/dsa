#include "sort.h"

void shell_sort(int a[], int n, int d)
{
    int i = 0;
    while (i + d < n)
    {
        if (a[i + d] < a[i])
        {
            int x = a[i + d];
            int j = i;

            while (j >= 0 && x < a[j])
            {
                a[j + d] = a[j];
                j -= d;
            }

            a[j + d] = x;
        }
        i += d;
    }
}

void sort(int a[], int n)
{
    for (int d = n / 2; d > 0; d /= 2)
    {
        shell_sort(a, n, d);
    }
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
