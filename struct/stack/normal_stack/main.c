#include "stack.c"

int main()
{
    Stack *stack = initStack();
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        Status *s = push(stack, ch);
        checkStatus(s);
    }

    while (!isStackEmpty(stack))
    {
        ElemType elem;
        Status *s = pop(stack, &elem);
        checkStatus(s);

        printf("%c\n", elem);
    }
}
