#include<stdio.h>
#include<stdlib.h>
 
 typedef struct stack{
    int size;
    int top;
    int *arr;
 }stack;

int isfull(stack* s){
    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isempty(stack* s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}

void push(stack* s, int n){
    if(isfull(s)){
        printf("Stack Oveflow");
    }
    else{
        s->top++;
        s->arr[s->top]=n;
    }
}
int pop(stack* s){
    int ret;
    if(isempty(s)){
        printf("Stack Underflow\n");
    }
    else{
        ret=s->arr[s->top];
        s->top--;
        return ret;
    }
}
int peek(stack* s){
    int ret;
    if(isempty(s)){
        printf("Stack Underflow\n");
    }
    else{
        ret=s->arr[s->top];
        // s->top--;
        return ret;
    }
}

int main(){
    // int result;
     stack* s;
s=(stack*)malloc(sizeof(stack));
s->size=5;
s->top=-1;
s->arr=(int*)malloc(s->size*sizeof(int));

push(s,10);
printf("Top element in Stack is:%d",peek(s));
pop(s);
printf("Top element in Stack is:%d",peek(s));
free(s->arr);
free(s);
return 0;
}