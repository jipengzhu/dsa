#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int getLength(List l)
{
    return l.length;
}

Status *get(List l, int i, ElemType *e)
{
    if (isEmpty(l))
        return getEmptyError();
    if (isOverIndex(l, i))
        return getOverIndexError();

    *e = l.data[i];

    return getOkStatus();
}

Status *insert(List *l, int i, ElemType e)
{
    if (isFull(*l))
        return getFullError();
    if (canInsert(*l, i))
        return getOverIndexError();

    for (int j = l->length - 1; j >= i; j--)
    {
        l->data[j + 1] = l->data[j];
    }

    l->data[i] = e;
    l->length++;

    return getOkStatus();
}

Status *delete (List *l, int i, ElemType *e)
{
    if (isEmpty(*l))
        return getEmptyError();
    if (isOverIndex(*l, i))
        return getOverIndexError();

    *e = l->data[i];
    l->length--;

    for (int j = i; j < l->length - 1; j++)
    {
        l->data[j] = l->data[j + 1];
    }

    return getOkStatus();
}

void show(List l)
{
    for (int i = 0; i < l.length; i++)
    {
        ElemType d = l.data[i];
        printf("%d\t", d);
    }

    printf("\n");
}

List init(int len)
{
    List l;
    l.length = len;

    for (int i = 0; i < len; i++)
    {
        l.data[i] = i;
    }

    return l;
}
