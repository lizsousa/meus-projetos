#include<stdio.h>
	int main(){
	int NUMBER,horasextra;
	double SALARY; 
	float valorrecebeporhora;
 	scanf("%d",&NUMBER);
	scanf("%d",&horasextra);
	scanf("%f",&valorrecebeporhora);

	SALARY=(valorrecebeporhora*horasextra);
	printf("NUMBER = %d\n", NUMBER);
	printf("SALARY = U$ %.2lf\n",SALARY);
	return 0;
}

