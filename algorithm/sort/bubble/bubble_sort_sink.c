#include "sort.h"

void sort(int a[], int n)
{
    for (int i = n - 1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
            }
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
