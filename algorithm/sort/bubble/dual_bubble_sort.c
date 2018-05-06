#include "sort.h"

void sort(int a[], int n)
{
    int l = 0;
    int r = n - 1;
    while (l < r)
    {
        for (int j = l; j < r; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
        }

        --r;

        for (int j = r; j > l; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(&a[j], &a[j - 1]);
            }
        }

        ++l;
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
