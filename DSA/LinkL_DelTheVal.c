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
Node* delTheVal(Node* head, int val){
    Node* p=head;
    Node* q=head->next;
    if(p->data==val){
        head=head->next;
        free(p);
        return head;
    }
    if(q->data==val){
        p->next=q->next;
        free(q);
        return head;
    }
    while(q->data!=val && q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    if(q->data==val){
    p->next=q->next;
    free(q);
    }
    else{
        printf("\n...Value not found...\n");
    }
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

    printf("\nBefore deletion:\n");
    traverseList(head);
    head=delTheVal(head, 1);
    printf("\nAfter deletion:\n");
    traverseList(head);
}

