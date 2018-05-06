#include <stdlib.h>
#include "sort.h"

void mergeArray(int a[], int n, int first, int mid, int last)
{
    int *t = (int *)malloc(n * sizeof(int));
    int i = first;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= last)
    {
        if (a[i] < a[j])
        {
            t[k++] = a[i++];
        }
        else
        {
            t[k++] = a[j++];
        }
    }

    while (i <= mid)
    {
        t[k++] = a[i++];
    }

    while (j <= last)
    {
        t[k++] = a[j++];
    }

    for (i = 0; i < k; i++)
    {
        a[first + i] = t[i];
    }

    free(t);
}

void mergeSort(int a[], int n, int first, int last)
{
    if (first < last)
    {
        int mid = (first + last) / 2;
        mergeSort(a, n, first, mid);
        mergeSort(a, n, mid + 1, last);

        mergeArray(a, n, first, mid, last);
    }
}

void sort(int a[], int n)
{
    mergeSort(a, n, 0, n - 1);
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
