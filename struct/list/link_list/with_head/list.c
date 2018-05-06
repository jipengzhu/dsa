#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int getLength(List l)
{
    return l->data;
}

Status *get(List l, int i, ElemType *e)
{
    if (isEmpty(l))
        return getEmptyError();
    if (isOverIndex(l, i))
        return getOverIndexError();

    List p = l;
    while (p && i >= 0)
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

    List p = *l;
    while (p && i > 0)
    {
        p = p->next;
        i--;
    }

    List q = (List)malloc(sizeof(List));
    q->data = e;

    q->next = p->next;
    p->next = q;

    (*l)->data += 1;

    return getOkStatus();
}

Status *delete (List *l, int i, ElemType *e)
{
    if (isEmpty(*l))
        return getEmptyError();
    if (isOverIndex(*l, i))
        return getOverIndexError();

    List p = *l;
    while (p && i > 0)
    {
        p = p->next;
        i--;
    }

    List q = p->next;
    p->next = q->next;

    *e = q->data;
    free(q);

    (*l)->data -= 1;

    return getOkStatus();
}

void show(List l)
{
    List p = l->next;
    while (p)
    {
        printf("%d\t", p->data);
        p = p->next;
    }

    printf("\n");
}

List initOnHead(int len)
{
    List head = (List)malloc(sizeof(List));
    head->data = len;
    head->next = NULL;

    for (int i = len - 1; i >= 0; i--)
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
    List head = (List)malloc(sizeof(List));
    head->data = len;
    head->next = NULL;

    List rear = head;
    for (int i = 0; i < len; i++)
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
