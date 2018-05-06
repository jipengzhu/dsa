#ifndef _H_LIST
#define _H_LIST
#endif

#include "base.h"
#include "elem.h"

int getLength(List l);
Boolean isEmpty(List l)
{
    return getLength(l) == 0 ? TRUE : FALSE;
}

Boolean isFull(List l)
{
    return getLength(l) == MAX_SIZE ? TRUE : FALSE;
}

Boolean isOverIndex(List l, int i)
{
    return i < 0 || i >= getLength(l) ? TRUE : FALSE;
}

Boolean canInsert(List l, int i)
{
    return i < 0 || i > getLength(l) ? TRUE : FALSE;
}
Status *get(List l, int i, ElemType *e);
Status *insert(List *l, int i, ElemType e);
Status *delete (List *l, int i, ElemType *e);
List init(int len);
