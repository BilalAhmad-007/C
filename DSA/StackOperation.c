#include <stdio.h>
#include <stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;
};
typedef struct stack stack;
int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(stack *s, int element)
{
    if (isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top] = element;
    }
}
void pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("%d ", s->arr[s->top]);
        s->top--;
    }
}
int main()
{
    stack *s;
    s = (stack *)malloc(sizeof(stack));
    s->size = 5;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    printf("Putting elements in the stack:\n");
    push(s, 0);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    for (int i = 0; i < s->size; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\nInserting one more element in the stack:\n");
    push(s, 5);
    printf("\n\nDeleting the elements from the stack one by one:\n");
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    printf("\nDeleting one more element from the stack:");
    pop(s);
    return 0;
}
