#include<stdio.h>
#include<conio.h>
int main(){
    int arr[5]={5,3,4,2,6};
    int temp;
    for(int i=1; i<5; i++){
        for(int j=0; j<4; j++){
            if(arr[j]>arr[j+1]){
            temp=arr[j];
            arr[j]=arr[j+1];
            arr[j+1]=temp;
            
            }
        }

    }
    for(int k=0; k<5; k++){
        printf("%d",arr[k]);
    }
}