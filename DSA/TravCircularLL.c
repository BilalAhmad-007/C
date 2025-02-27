#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
typedef struct Node Node;
void linkListTrav(Node* head){
     for(int i=0; i<5; i++){ // for understanding the concept of circular LL
    Node *ptr=head;
    while(ptr->next!=head){
        printf(" %d ->",ptr->data);
        ptr= ptr->next;
    }
    printf(" %d ->",ptr->data);
    }
    printf(" Repeating...");
}
int main(){
    Node *head, *second, *third;
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=head;

    linkListTrav(head);
    
}