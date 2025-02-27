#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int size;
    int top;
    char *exp;
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
void push(stack *s, char op)
{
    if (isFull(s))
    {
        printf("Stack Overflow\n");
        return;
    }
    s->top++;
    s->exp[s->top] = op;
}
char pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack Underflow\n");
        return '\0';
    }
    else
    {
        char op = s->exp[s->top];
        s->top--;
        return op;
    }
}
int isOperator(char op)
{
    if (op == '%' || op == '+' || op == '-' || op == '*' || op == '/')
    {
        return 1;
    }
    return 0;
}
int prec(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    return 2;
}
char *InToPo(char *Infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    if (sp == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }
    sp->size = 6;
    sp->top = -1;
    sp->exp = (char *)malloc(sp->size * sizeof(char));
    if (sp->exp == NULL)
    {
        printf("Memory allocation for stack expression failed\n");
        free(sp); // Free allocated stack before returning
        return NULL;
    }
    char *Postfix = (char *)malloc((strlen(Infix) + 1) * sizeof(char));
    if (Postfix == NULL)
    {
        printf("Memory allocation for Postfix failed\n");
        free(sp->exp);
        free(sp);
        return NULL;
    }
    int i = 0;
    int j = 0;
    while (Infix[i] != '\0')
    {
        if (!isOperator(Infix[i]))
        {
            Postfix[j] = Infix[i];
            i++;
            j++;
        }
        else if (isEmpty(sp))
        {
            push(sp, Infix[i]);
            i++;
        }
        else
        {
            if (prec(Infix[i]) > prec(sp->exp[sp->top]))
            {
                push(sp, Infix[i]);
                i++;
            }
            else
            {
                Postfix[j] = pop(sp);
                j++;
            }
        }
    }
    while (!isEmpty(sp))
    {
        Postfix[j] = pop(sp);
        j++;
    }
    Postfix[j] = '\0';
    free(sp->exp);
    free(sp);
    return Postfix;
}

int main()
{
    char *Infix = "a+b-c*z*f/2+3";
    char *Postfix = InToPo(Infix);
    if (Postfix != NULL)
    {
        printf("Postfix expression is : %s", Postfix);
        free(Postfix);
    }
    return 0;
}