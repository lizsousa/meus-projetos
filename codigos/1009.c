#include<stdio.h>
int main(){
	char nome[20];
	double salariofixo, totaldevendas, TOTAL;

	scanf("%s",nome);
	scanf("%lf",&salariofixo);
	scanf("%lf",&totaldevendas);
	
	TOTAL=((totaldevendas*0.15)+salariofixo);


	printf("TOTAL = R$ %.2lf\n", TOTAL);
	return 0;
}
