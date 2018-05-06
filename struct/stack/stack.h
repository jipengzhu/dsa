#ifndef _H_STACK
#define _H_STACK

#include "base.h"
#include "stack_elem.h"

Stack* initStack();
Boolean isStackFull(Stack *s);
Boolean isStackEmpty(Stack *s);
Status* push(Stack *s, ElemType e);
Status* pop(Stack *s, ElemType *e);

#endif
