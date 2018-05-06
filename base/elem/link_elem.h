#include "type.h"

#define MAX_SIZE 30

typedef struct Node
{
    ElemType data;
    struct Node *next;
} * LinkList;

typedef LinkList List;
