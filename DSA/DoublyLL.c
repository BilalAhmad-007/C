#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;
void traverseFromFirst(Node* head){
    Node* ptr= head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}
void traverseFromLast(Node* last){
    Node* ptr= last;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->prev;
    }
    printf("NULL");
}
int main(){
    Node *head, *second, *third;
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head->prev=NULL;
    head->data=1;
    head->next=second;

    second->prev=head;
    second->data=2;
    second->next=third;

    third->prev=second;
    third->data=3;
    third->next=NULL;
    printf("Linked List traversal from beginning: \n");
    traverseFromFirst(head);
    printf("\nLinked List traversal from end:\n");
    traverseFromLast(third);
}