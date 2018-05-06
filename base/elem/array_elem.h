#include "type.h"

#define MAX_SIZE 30

typedef struct
{
    ElemType data[MAX_SIZE];
    int length;
} ArrayList;

typedef ArrayList List;
