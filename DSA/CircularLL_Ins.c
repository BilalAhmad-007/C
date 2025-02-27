#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;
void linkListTrav(Node *head)
{

    Node *ptr = head;
    while (ptr->next != head)
    {
        printf(" %d ->", ptr->data);
        ptr = ptr->next;
    }
    printf(" %d ->", ptr->data);
}
Node *Insertatbeg(Node *head, int data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    Node *ptr = head->next; 
    new->data = data;
    new->next = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    return new;
}
int main()
{   int n;
    Node *head, *second, *third;
    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = head;

    printf("Linked list before insertion:\n");
    linkListTrav(head);
    printf("\nEnter the element you want to insert: ");
    scanf("%d",&n);
    head = Insertatbeg(head, n); 
    printf("\nLinked list after insertion:\n");
    linkListTrav(head);
}