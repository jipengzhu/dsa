#include "stack.c"

int main()
{
    Stack *stack = initStack();
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        char *p = (char *)malloc(sizeof(char));
        *p = ch;

        Status *s = push(stack, p);
        checkStatus(s);
    }

    while (!isStackEmpty(stack))
    {
        ElemType elem;
        Status *s = pop(stack, &elem);
        checkStatus(s);

        printf("%c\n", *((char *)elem));
    }
}
