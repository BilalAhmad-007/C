#include<stdio.h>
/* void SwapNum(int *a, int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}
*/
void SwapNum(int x, int y){
    x=x+y;
    y=x-y;
    x=x-y;
    printf("First Num: %d, Second Num: %d\n",x,y);
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
   // SwapNum(&x,&y); --> for call by reference...
   // printf("First Num: %d, Second Num: %d\n",x,y);
    SwapNum(x,y); // for call by value...
    printf("First Num: %d, Second Num: %d\n",x,y);
    // ^ it doesn't show swapped value beacuse value swapped for local variables...
}