#include "sort.h"

void heapAdjust(int a[], int n, int i)
{
    int lc = 2 * i;
    int rc = lc + 1;

    int max = i;
    if (lc < n && a[lc] > a[max])
    {
        max = lc;
    }

    if (rc < n && a[rc] > a[max])
    {
        max = rc;
    }

    if (max != i)
    {
        swap(&a[i], &a[max]);

        // sub tree is broken and need to be sort again
        heapAdjust(a, n, max);
    }
}

void heapBuild(int a[], int n)
{
    // from bottom to top to adjust non-leaf node
    // require (2 * i < n - 1)
    for (int i = (n - 1) / 2; i >= 0; --i)
    {
        heapAdjust(a, n, i);
    }
}

void sort(int a[], int n)
{
    heapBuild(a, n);

    for (int i = n - 1; i > 0; --i)
    {
        swap(&a[i], &a[0]);

        // readjust the unsorted part of array
        heapAdjust(a, i, 0);
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
