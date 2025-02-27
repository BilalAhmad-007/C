#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;
Node* createNode(Node* head, int val){
    Node* newNode= (Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    if(head==NULL){
        return newNode;
    }
    Node* ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=newNode;
    return head;
}
void traverseList(Node* head){
    Node* ptr=head;
    while(ptr!=NULL){
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("Null");
}
int main(){
    int n,val;
    Node* head=NULL;
    printf("Enter the number of nodes you want in linked list: ");
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        printf("Enter the %d element: ",i);
        scanf("%d",&val);
        head=createNode(head, val);
    }
    printf("\nYour Linked List is:\n");
    traverseList(head);
    return 0;
}
