#include "sort.h"

int partition(int a[], int l, int r)
{
    // if x is a[l], direction r -> l is first
    // if x is a[r], direction l -> r is first
    // or x be repeated in many positions
    int x = a[l];
    while (l < r)
    {
        // find the value less than x to exchange
        while (r > l && a[r] >= x)
            --r;

        // don't forget to check index
        if (r > l)
        {
            swap(&a[r], &a[l]);
            l++;
        }

        // find the value greater than x to exchange
        while (l < r && a[l] <= x)
            ++l;

        // don't forget to check index
        if (l < r)
        {
            swap(&a[l], &a[r]);
            r--;
        }
    }

    // r is also ok because r is equal l now
    a[l] = x;

    return l;
}

void quickSort(int a[], int l, int r)
{
    if (l < r)
    {
        int i = partition(a, l, r);
        quickSort(a, l, i - 1);
        quickSort(a, i + 1, r);
    }
}

void sort(int a[], int n)
{
    quickSort(a, 0, n - 1);
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
