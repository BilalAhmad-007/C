#include<stdio.h>
int main(){
	float a,b;
	char c;
	printf("Enter a number: ");
	scanf("%f",&a);
	printf("Enter an Operator: ");
	scanf(" %c",&c);
	printf("Enter second number: ");
	scanf("%f",&b);
	printf("\n");
	switch(c){
		case '+':
		printf("Result= %f ",a+b);
		break;
		case '-':
		printf("Result= %f",a-b);
		break;
		case '*':
		printf("Result= %f",a*b);
		break;
		case '/':
		printf("Result= %f",a/b);
		break;
		default:
		printf("Invalid operator");
		break;
	}
	return 0;
}