#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;

void traverseList(Node* ptr){
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("Null");
}

Node* insertInBet(Node* head, int val, int index){
    Node* new= (Node*)malloc(sizeof(Node*));
    Node* ptr=head;
    int i=0;
    while(i!=index-1){
        ptr= ptr->next;
        i++;
    }
    new->data=val;
    new->next=ptr->next;
    ptr->next=new;
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
    traverseList(head);
    head= insertInBet(head, 0, 2);
    printf("\nLinkedList after insertion in between\n");
    traverseList(head);
}
