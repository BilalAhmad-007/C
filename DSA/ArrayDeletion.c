#include<stdio.h>
void arrTraversal(int *a, int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void arrDeletion(int *arr, int size, int index){
    for(int i=index; i<size-1; i++){
        arr[i]=arr[i+1];
    }
}
int main(){
    int arr[10]={1,2,3,4,5};
    int size=5, index;
    printf("Array before Deletion: \n");
    arrTraversal(arr,size);
   
    printf("Enter the index where you want to Delete the element: ");
    scanf("%d",&index);
    arrDeletion(arr, size, index);
    size--;
    printf("Array after Deletion:\n");
    arrTraversal(arr, size);
    }
    