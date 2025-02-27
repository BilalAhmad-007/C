#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data; 
    struct Node* next;
};
typedef struct Node Node;
Node *f,*r;
int isEmpty(){
    if(f==NULL){
        return 1;
    }
    return 0;
}
int isFull(){
    Node* n=(Node*)malloc(sizeof(Node));
    if(n==NULL){
        return 1;
    }
    free(n);
    return 0;
}
void enQueue(int val){
    if(isFull()){
        printf("Queue Overflow\n");
       
    }
    else{
        Node* new=(Node*)malloc(sizeof(Node));
        new->data=val;
        new->next=NULL;
        if(f==NULL){
            f=r=new;
        }
        else{
            r->next=new;
            r=new;
        }
    }
}
int deQueue(){
    int val;
    if(isEmpty(f)){
        printf("\nEmpty Queue\n");
    }
    else{
        Node* ptr=f;
        if(f==r){
            f=r=f->next;
            val=ptr->data;
            free(ptr);
            return val;
        }
        else{
            f=f->next;
            val=ptr->data;
            free(ptr);
            return val;
        }
    }
}
void traverseQ(){
    Node* ptr=f;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

int main(){
    
    f=r=NULL;
    printf("enqueue 3 elements:\n");
    enQueue(1);
    enQueue(2);
    enQueue(3);
    printf("queue after enqueue 3 elements:\n");
    traverseQ();
    printf("dequeue 3 elements:\n");
    printf("Element dequeued: %d\n", deQueue());
    printf("Element dequeued: %d\n", deQueue());
    printf("Element dequeued: %d\n", deQueue());
    enQueue(4);
    printf("queue after inserting one more element:\n");
    traverseQ();


    return 0;
}