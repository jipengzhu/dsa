#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int getLength(List l)
{
    int c = 0;
    while (l)
    {
        c++;
        l = l->next;
    }

    return c;
}

Status *get(List l, int i, ElemType *e)
{
    if (isEmpty(l))
        return getEmptyError();
    if (isOverIndex(l, i))
        return getOverIndexError();

    List p = l;
    while (p && i > 0)
    {
        p = p->next;
        i--;
    }

    *e = p->data;

    return getOkStatus();
}

Status *insert(List *l, int i, ElemType e)
{
    if (isFull(*l))
        return getFullError();
    if (canInsert(*l, i))
        return getOverIndexError();

    List q = (List)malloc(sizeof(List));
    q->data = e;

    if (i == 0)
    {
        q->next = *l;
        *l = q;
    }
    else
    {
        List p = *l;
        while (p && i > 1)
        {
            p = p->next;
            i--;
        }

        q->next = p->next;
        p->next = q;
    }

    return getOkStatus();
}

Status *delete (List *l, int i, ElemType *e)
{
    if (isEmpty(*l))
        return getEmptyError();
    if (isOverIndex(*l, i))
        return getOverIndexError();

    List q = *l;
    if (i == 0)
    {
        *l = q->next;
    }
    else
    {
        List p = *l;
        while (p && i > 1)
        {
            p = p->next;
            i--;
        }

        q = p->next;
        p->next = q->next;

        *e = q->data;
    }

    free(q);

    return getOkStatus();
}

void show(List l)
{
    List p = l;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }

    printf("\n");
}

List initOnHead(int len)
{
    if (len == 0)
        return NULL;

    List head = (List)malloc(sizeof(List));
    head->data = 0;
    head->next = NULL;

    for (int i = len - 1; i > 0; i--)
    {
        List p = (List)malloc(sizeof(List));
        p->data = i;
        p->next = NULL;

        p->next = head->next;
        head->next = p;
    }

    return head;
}

List initOnTail(int len)
{
    if (len == 0)
        return NULL;

    List head = (List)malloc(sizeof(List));
    head->data = 0;
    head->next = NULL;

    List rear = head;
    for (int i = 1; i < len; i++)
    {
        List p = (List)malloc(sizeof(List));
        p->data = i;
        p->next = NULL;

        rear->next = p;
        rear = p;
    }

    return head;
}

List init(int len)
{
    return initOnHead(len);
    //return initOnTail(len);
}
