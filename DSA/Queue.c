#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int f, r;
    int *arr;
};
typedef struct Queue Que;
int isFull(Que *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}
int isEmpty(Que *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}
void enQueue(Que *q, int val)
{
    if (isFull(q))
    {
        printf("\nQueue overflow\n");
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}
int deQueue(Que *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("\nQueue Underflow\n");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
} 
void traverseQ(Que *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}
int main()
{
    Que *q = (Que *)malloc(sizeof(Que));
    q->size = 5;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    printf("\nQueue after inserting 3 elements :\n");
    traverseQ(q);
    enQueue(q, 4);
    enQueue(q, 5);
    printf("\nQueue after inserting 5 elements :\n");
    traverseQ(q);
    printf("Element dequeued: %d\n",deQueue(q));
    printf("Element dequeued: %d\n",deQueue(q));
    printf("Element dequeued: %d\n",deQueue(q));

    printf("\nQueue after removing 3 elements :\n");
    traverseQ(q);
    printf("Element dequeued: %d\n",deQueue(q));
    printf("Element dequeued: %d\n",deQueue(q));
    // deQueue(q);      deleted all elements:Underflow
    // enQueue(q,1);    rear reaches last index:Overflow
    free(q->arr);
    free(q);
    return 0;
}