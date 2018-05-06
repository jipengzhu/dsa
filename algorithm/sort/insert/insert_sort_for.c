#include "sort.h"

void sort(int a[], int n)
{
    for (int i = 0; i + 1 < n; ++i)
    {
        if (a[i + 1] < a[i])
        {
            int x = a[i + 1];
            int j = i;

            for (; j >= 0 && x < a[j]; --j)
            {
                a[j + 1] = a[j];
            }

            a[j + 1] = x;
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
