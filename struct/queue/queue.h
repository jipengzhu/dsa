#ifndef _H_QUEUE
#define _H_QUEUE

#include "base.h"
#include "queue_elem.h"

Queue* initQueue();
Boolean isQueueFull(Queue *q);
Boolean isQueueEmpty(Queue *q);
Status* enqueue(Queue *q, ElemType e);
Status* dequeue(Queue *q, ElemType *e);

#endif
