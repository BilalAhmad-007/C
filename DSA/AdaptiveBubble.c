#include<stdio.h>
int getArr(int *A, int n){
	printf("Enter the elements of array:\n");
	for(int i=0;i<n;i++){
		scanf(" %d",&A[i]);
	}
	return 0;
}
int printA(int *A,int size){
	for(int i=0;i<size;i++){
		printf("%d ",A[i]);
	}
	return 0;
}
void aBubble(int *A,int n){
	int i,j,temp;
	int isSorted=0;
	for(i=0;i<n-1;i++){
		printf("\nWorking on the pass %d \n",i+1);
		isSorted=1;
		for(j=0;j<n-1-i;j++){
			if(A[j]>A[j+1]){
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
				isSorted=0;
			}
		}
		if(isSorted){
			return;
		}
	}
}
int main(){
	int size, A[6];
	size=6;
	getArr(A,size);
	printf("\nArray Before Sorted\n");
	printA(A,size);
	printf("\n");
	aBubble(A,size);
	printf("\nArray After Sorted\n");
	printA(A,size);
	return 0;
}