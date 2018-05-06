#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *p, int *q)
{
    int t = *p;
    *p = *q;
    *q = t;
}

int max(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > max)
            max = a[i];
    }

    return max;
}

int min(int a[], int n)
{
    int min = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (a[i] < min)
            min = a[i];
    }

    return min;
}

void show(int a[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void array(int a[], int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; ++i)
    {
        a[i] = rand() % 100 - 50;
    }
}

void offset(int a[], int n, int k)
{
    for (int i = 0; i < n; ++i)
    {
        a[i] = a[i] + k;
    }
}

void sort(int a[], int n);
