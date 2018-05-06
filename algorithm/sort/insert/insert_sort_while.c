#include "sort.h"

void sort(int a[], int n)
{
    int i = 0;
    while (i + 1 < n)
    {
        if (a[i + 1] < a[i])
        {
            int x = a[i + 1];
            int j = i;

            while (j >= 0 && x < a[j])
            {
                a[j + 1] = a[j];
                --j;
            }

            a[j + 1] = x;
        }
        ++i;
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
