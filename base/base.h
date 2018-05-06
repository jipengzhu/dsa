#include <stdio.h>
#include <stdlib.h>

#ifndef _H_BASE
#define _H_BASE

#define OK 0
#define ERROR 1

#define TRUE 1
#define FALSE 0
typedef int Boolean;

typedef struct
{
    int code;
    const char *msg;
} Status;

Status *getStatus(int code, const char *msg)
{
    Status *s = (Status *)malloc(sizeof(Status));
    s->code = code;
    s->msg = msg;

    return s;
}

Status *getEmptyError()
{
    return getStatus(ERROR, "get error of that container is empty");
}

Status *getFullError()
{
    return getStatus(ERROR, "get error of that container is full");
}

Status *getOverIndexError()
{
    return getStatus(ERROR, "get error of that out of index");
}

Status *getOkStatus()
{
    return getStatus(OK, "ok");
}

void checkStatus(Status *s)
{
    if (s->code != OK)
    {
        printf("%s\n", s->msg);
        exit(1);
    }
}

#endif
