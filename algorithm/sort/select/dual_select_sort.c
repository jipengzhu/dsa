#include "sort.h"

void sort(int a[], int n)
{
    for (int i = 0; i <= n / 2; ++i)
    {
        int min = i;
        int max = n - 1 - i;
        int l = min;
        int r = max;
        for (int j = l + 1; j < r; ++j)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
            else if (a[j] > a[max])
            {
                max = j;
            }
        }

        if (min != l)
        {
            swap(&a[i], &a[min]);
        }

        if (max != r)
        {
            swap(&a[r], &a[max]);
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
