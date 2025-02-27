#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
void traverseList(Node *top)
{
    Node *ptr = top;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
int isFull()
{
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL)
    {
        return 1;
    }
    return 0;
}
Node *push(Node *top, int data)
{
    if (isFull())
    {
        printf("Stack Overflow\n");
    }
    else
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->next = top;
        new->data = data;
        top = new;
        return top;
    }
}
Node *pop(Node *top)
{
    if (isEmpty(top))
    {
        printf("Stack UnderFlow\n");
    }
    else
    {
        Node *ptr = top;
        printf("%d ", ptr->data);
        top = top->next;
        free(ptr);
        return top;
    }
}
int main()
{
    Node *top;
    top = NULL;
    if (isEmpty(top))
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Stack is not empty\n");
    }

    /*
    top=(Node*)malloc(sizeof(Node));
    top->data=1;
    top->next=NULL;
    if(isEmpty(top)){
        printf("Stack Underflow\n");
    }
    else{
        printf("Stack is not empty :%d\n",top->data);
    }
    */

    top = push(top, 1);
    top = push(top, 2);
    top = push(top, 3);
    top = push(top, 4);
    top = push(top, 5);
    printf("...Elements are pushed into the stack...\n");
    printf("Entered elements are popped:\n");
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    top = pop(top);
    // traverseList(top);
    return 0;
}
