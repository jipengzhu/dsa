#include <stdio.h>
#include <stdlib.h>

#include "list.c"

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("require list length and item index\n");
        return ERROR;
    }

    int len = atoi(argv[1]);
    int i = atoi(argv[2]);

    List l = init(len);
    show(l);

    ElemType e;
    Status *s = delete (&l, i, &e);
    checkStatus(s);

    printf("index: %d, item: %d, len: %d\n", i, e, getLength(l));
    show(l);

    return 0;
}
