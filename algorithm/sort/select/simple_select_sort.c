#include "sort.h"

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }

        if (k != i)
        {
            swap(&a[i], &a[k]);
        }
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
