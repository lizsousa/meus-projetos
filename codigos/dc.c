#include<stdio.h>
int main(){
	float num1,num2;

	printf("digite o primeiro numero\n");
	scanf("%f",&num1);

	printf("digite o segundo numero\n");
	scanf("%f",&num2);

	if(num1>num2){
	
		printf("o numero 1 eh maior\n", num1);
	}
	else(num2>num1){
	
		printf("o numero 2 eh maior\n", num2);
		
	}
	return 0;
}
