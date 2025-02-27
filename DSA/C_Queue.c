#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int f,r;
    int* arr;
};
typedef struct Queue Que;
int isEmpty(Que *q){
    if(q->f==q->r){
        return 1;
    }
    return 0;
}
int isFull(Que* q){
    if((q->r+1)%q->size==q->f){
        return 1;
    }return 0;
}
void nQ(Que *q, int val){
    if(isFull(q)){
        printf("Que is Full\n");
    }
    else{
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
    }
}
int dQ(Que *q){
    int val=-1;
    if(isEmpty(q)){
        printf("Que is Empty\n");
    }
    else{
        q->f=(q->f+1)%q->size;
        val= q->arr[q->f];
    }
}
void traverseQ(Que *q){
    for(int i = (q->f+1)%q->size; i<=q->r; i++){
        printf("%d ",q->arr[i]);
    }
    printf("\n");
}
int main(){
    Que *q=(Que*)malloc(sizeof(Que));
    q->size=5;
    q->f=q->r=0;
    q->arr=(int*)malloc(q->size*sizeof(int));

    printf("Enqueuing 4 elements\n");
    nQ(q, 1);
    nQ(q, 2);
    nQ(q, 3);
    nQ(q, 4);
    printf("Enqueue one more element:\n");
    nQ(q, 5);
    printf("Queue after inserting the elements:\n");
    traverseQ(q);
    
    printf("Now dequeuing each element:\n");
    printf("Element dequeued: %d\n",dQ(q));
    printf("Element dequeued: %d\n",dQ(q));
    printf("Element dequeued: %d\n",dQ(q));
    printf("Element dequeued: %d\n",dQ(q));
    printf("Now dequeuing one more element:\n");
    dQ(q);
    printf("Again Inserting 3 elements:\n");
    nQ(q, 5);
    nQ(q, 6);
    nQ(q, 7);
    printf("The Queue After inserting some elements again:\n");
    traverseQ(q);
    printf("Dequeue two elements:\n");
    printf("Element dequeued: %d\n",dQ(q));
    printf("Element dequeued: %d\n",dQ(q));
    printf("Queue after dequeuing:\n");
    traverseQ(q);
    free(q->arr);
    free(q);
    return 0;
}