#include<stdio.h>
void printA(int a[], int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
void getA(int a[], int n){
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    printf("\n");
}
void merge(int a[], int mid, int low, int high){
    int i,j,k,b[50];
    i=k=low;
    j=mid+1;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            i++; k++;
        }
        else{
            b[k]=a[j];
            j++;k++;
        }
    }
    while(i<=mid){  // this loop is for inserting the remaining elements of a[i] to b[k]
        b[k]=a[i];
        i++;k++;
    }
    while(j<=high){ // this loop is for inserting the remaining elements of a[j] to b[k]
        b[k]=a[j];
        j++;k++;
    }
    for(i=low; i<=high; i++){
        a[i]=b[i];
    }
}
void mergeSort(int a[], int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        mergeSort(a,low,mid);
        mergeSort(a,mid+1,high);
        merge(a,mid,low,high);
    }
}
int main(){
    int arr[5];
    int s=5;
    printf("Enter the elements of array:\n");
    getA(arr,s);
    printf("Array before sorted:\n");
    printA(arr,s);
    mergeSort(arr,0,4);
    printf("\nArray after sorted:\n");
    printA(arr,s);
    return 0;
}