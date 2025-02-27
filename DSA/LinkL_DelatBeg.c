#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
void traverseList(Node* head)
{
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("Null");
}
Node* delAtBeg(Node* head){
    Node* ptr=head;
    head=head->next;
    free(ptr);
    return head;
}
void main()
{
    Node *head, *second, *third;
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;
    printf("\nLinked List before deletion:\n");
    traverseList(head);
    head=delAtBeg(head);
    printf("\nLinked list after deletion:\n");
    traverseList(head);
}