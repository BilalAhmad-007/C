#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
typedef struct stack stack;
int isEmpty(stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
int isFull(stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    return 0;
}
int main(){
    stack *s;
    s=(stack*)malloc(sizeof(stack));
    s->size=10;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("Cheking that stack empty or not before inserting any element:\n");
    if(isEmpty(s)){
        printf("...Stack is empty...");
    }
    else{
        printf("...Stack is not empty...");
    }
    printf("\n");
    s->arr[0]=45;
    s->top++;
    printf("\nInserted element in stack is %d\n",s->arr[0]);
    printf("\nCheking that stack empty or not after inserting an element:\n");
    if(isEmpty(s)){
        printf("...Stack is empty...\n");
    }
    else{
        printf("...Stack is not empty...\n");
    }
    // now filling the stack and use the isFull fn for checking that the stack is full or not
    printf("\nEnter the elements of stack:\n");
    for(int i=1; i<s->size; i++){
        scanf("%d",&s->arr[i]);
        s->top++;
    }
    printf("Checking that the stack is full or not:\n");
    if(isFull(s)){
        printf("...Stack is full...");
    }
    else{
        printf("...Stack is not full...");
    }
    free(s->arr);
    free(s);
    return 0;
}