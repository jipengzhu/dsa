#include "queue_type.h"

#define QUEUE_SIZE 30

typedef struct
{
    ElemType data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;
