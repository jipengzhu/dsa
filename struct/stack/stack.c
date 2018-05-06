#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *initStack()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s)
    {
        printf("malloc memory error");
        exit(1);
    }

    s->top = -1;

    return s;
}

Boolean isStackFull(Stack *s)
{
    return s->top == STACK_SIZE;
}

Boolean isStackEmpty(Stack *s)
{
    return s->top == -1;
}

Status *push(Stack *s, ElemType e)
{
    if (isStackFull(s))
        return getFullError();

    s->top += 1;
    s->data[s->top] = e;

    return getOkStatus();
}

Status *pop(Stack *s, ElemType *e)
{
    if (isStackEmpty(s))
        return getEmptyError();

    *e = s->data[s->top];
    s->top -= 1;

    return getOkStatus();
}

Status *top(Stack *s, ElemType *e)
{
    if (isStackEmpty(s))
        return getEmptyError();

    int top = s->top;
    *e = s->data[top];

    return getOkStatus();
}
