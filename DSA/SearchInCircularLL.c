#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
typedef struct Node Node;
int searchElement(Node* head, int val){
    Node* ptr= head;
    int i=1;
    while(ptr->next!=head){
        if(ptr->data==val){
            return i;
        }
        ptr=ptr->next;
        i++;
    }
    if(ptr->data==val){
    return i;
    }
    return 0;
}
int main(){
    int n, loc;
    Node *head,*second,*third;
    head=(Node*)malloc(sizeof(Node));
    second=(Node*)malloc(sizeof(Node));
    third=(Node*)malloc(sizeof(Node));

    head->data=1;
    head->next=second;
    
    second->data=2;
    second->next=third;

    third->data=3;
    third->next=head;

    printf("Enter the element you want to search in the linked list: ");
    scanf("%d",&n);
    loc=searchElement(head, n);
    if(loc){
        printf("Value found at location: %d",loc);
    }
    else{
        printf("Value not found");
    }

}
