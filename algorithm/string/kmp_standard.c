#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void next(char *s, int next[], int n)
{
    next[0] = -1;

    int k = -1;
    int j = 1;
    while (j < n)
    {
        if (k == -1 || s[k] == s[j])
        {
            ++k;
            next[j++] = k;
        }
        else
        {
            k = next[k];
        }
    }
}

int search(char *s, char *p)
{
    int s_len = strlen(s);
    int p_len = strlen(p);

    int n[p_len];
    next(p, n, p_len);

    int i = 0;
    int j = 0;
    while (i < s_len && j < p_len)
    {
        if (j == -1 || p[j] == s[i])
        {
            ++i;
            ++j;
        }
        else
        {
            j = n[j];
        }
    }

    if (j == p_len)
    {
        return i - j;
    }
    else
    {
        return -1;
    }
}

int main()
{
    char *s = "abcdbddabcabd";
    char *p = "abcab";

    printf("find \"%s\" in \"%s\"\n", p, s);
    printf("%d\n", search(s, p));
}
