#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct LinkedList
{
    int data;
    struct LinkedList* next;
};
typedef struct LinkedList Node;

void traverseList(Node* ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("Null");
}
Node* delAtLast(Node* head){
    Node* preptr=head;
    Node* ptr=head->next;
    while(ptr->next!=NULL){
        ptr=ptr->next;
        preptr=preptr->next;
    }
    free(ptr);
    preptr->next=NULL;
    return head;
}
void main(){
    // Creating the nodes
    Node *head, *second, *Third;
    head= (Node*)malloc(sizeof(Node));
    second= (Node*)malloc(sizeof(Node));
    Third= (Node*)malloc(sizeof(Node));
    // Linking the Nodes with their data 
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=Third;

    Third->data=3;
    Third->next=NULL;

    printf("List before the deletion:\n");
    traverseList(head);
    head= delAtLast(head);
    printf("\nList after deletion:\n");
    traverseList(head);
}

