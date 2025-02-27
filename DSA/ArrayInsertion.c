#include<stdio.h>
void arrTraversal(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
int arrInsertion(int *arr, int size, int capacity, int index, int element){
    if(size>=capacity){
        return 0;
    }
    for(int i=size-1; i>=index; i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    return 1;
}
int main(){
    int arr[10]={1,2,3,4,5};
    int size=5, capacity=10, index, element;
    printf("Array before insertion: \n");
    arrTraversal(arr,size);
    printf("Enter the element you want to insert: ");
    scanf("%d",&element);
    printf("Enter the index where you want to insert the element: ");
    scanf("%d",&index);
    if(arrInsertion(arr, size, capacity, index, element)){
    size++;
    printf("Array after insertion:\n");
    arrTraversal(arr, size);
    }
    else{
        printf("Overflow Condition"); //if the array is full
    }
}