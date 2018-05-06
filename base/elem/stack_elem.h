#include "stack_type.h"

#define STACK_SIZE 30

typedef struct
{
    ElemType data[STACK_SIZE];
    int top;
} Stack;
