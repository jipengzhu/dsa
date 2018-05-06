#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    if (!q)
    {
        printf("malloc memory error");
        exit(1);
    }

    q->front = 0;
    q->rear = 0;

    return q;
}

Boolean isQueueFull(Queue *q)
{
    return (q->rear + 1) % QUEUE_SIZE == q->front;
}

Boolean isQueueEmpty(Queue *q)
{
    return q->rear == q->front;
}

Status *enqueue(Queue *q, ElemType e)
{
    if (isQueueFull(q))
        return getFullError();

    q->data[q->rear] = e;
    q->rear = (q->rear + 1) % QUEUE_SIZE;

    return getOkStatus();
}

Status *dequeue(Queue *q, ElemType *e)
{
    if (isQueueEmpty(q))
        return getEmptyError();

    *e = q->data[q->front];
    q->front = (q->front + 1) % QUEUE_SIZE;

    return getOkStatus();
}
