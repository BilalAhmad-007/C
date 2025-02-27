#include<stdio.h>
void main(){
int i,n,m;
printf("Enter the number from you want to print Even no.:\n");
scanf("%d",&n);
printf("Enter the range you want to print Even no.:\n\n");
scanf("%d",&m);
printf("------------------------------------\n");

for(i=n;i<=m;i++){
	if(i%2==1){
		continue;
	}
	printf("%d\n",i);
	
}

}