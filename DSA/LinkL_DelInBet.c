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
Node* delInBet(Node* head, int index){
    Node* p=head;
    Node* q=head->next;
    for(int i=0;i<index-1; i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
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

    printf("\nList before deletion:\n");
    traverseList(head);
    head=delInBet(head, 1);
    printf("\nList after deletion:\n");
    traverseList(head);
}