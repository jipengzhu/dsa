#include "queue.c"

int main()
{
    Queue *queue = initQueue();
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        Status *s = enqueue(queue, ch);
        checkStatus(s);
    }

    while (!isQueueEmpty(queue))
    {
        ElemType elem;
        Status *s = dequeue(queue, &elem);
        checkStatus(s);

        printf("%c\n", elem);
    }
}
