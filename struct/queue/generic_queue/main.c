#include "queue.c"

int main()
{
    Queue *queue = initQueue();
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        char *p = (char *)malloc(sizeof(char));
        *p = ch;

        Status *s = enqueue(queue, p);
        checkStatus(s);
    }

    while (!isQueueEmpty(queue))
    {
        ElemType elem;
        Status *s = dequeue(queue, &elem);
        checkStatus(s);

        printf("%c\n", *((char *)elem));
    }
}
