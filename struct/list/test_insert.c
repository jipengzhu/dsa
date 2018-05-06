#include <stdio.h>
#include <stdlib.h>

#include "list.c"

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("require list length, item index and item value\n");
        return ERROR;
    }

    int len = atoi(argv[1]);
    int i = atoi(argv[2]);
    int v = atoi(argv[3]);

    List l = init(len);
    show(l);

    Status *s = insert(&l, i, v);
    checkStatus(s);

    printf("index: %d, item: %d, len: %d\n", i, v, getLength(l));
    show(l);

    return 0;
}
