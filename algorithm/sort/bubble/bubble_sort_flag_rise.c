#include "sort.h"

void sort(int a[], int n)
{
    int i = 0;
    while (i < n - 1)
    {
        int pos = n - 1;
        for (int j = n - 1; j > i; --j)
        {
            if (a[j] < a[j - 1])
            {
                swap(&a[j], &a[j - 1]);
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
