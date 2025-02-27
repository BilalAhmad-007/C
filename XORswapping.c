#include<stdio.h>
void SwapNum(int *a, int *b){
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}
void main(){
    int x,y;
    printf("Enter first Number: ");
    scanf("%d",&x);
    printf("Enter the second Number: ");
    scanf("%d",&y);
    printf("Before swapping:\n");
    printf("First Num: %d, Second Num: %d\n",x,y);
    printf("After swapping:\n");
    SwapNum(&x,&y);
    printf("First Num: %d, Second Num: %d\n",x,y);
}