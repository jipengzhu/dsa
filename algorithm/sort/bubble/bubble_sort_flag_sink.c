#include "sort.h"

void sort(int a[], int n)
{
    int i = n - 1;
    while (i > 0)
    {
        int pos = 0;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                pos = j;
            }
        }

        i = pos;
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
