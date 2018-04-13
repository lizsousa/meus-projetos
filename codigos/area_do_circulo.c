#include<stdio.h>
#include<stdlib.h>
int main(){
	int raio, area;
	float pi=3.14;
	printf("digite o valor do raio:\n");
	scanf("%d",&raio);
	area=pi*(raio*raio);
	printf("valor da area do circulo eh: %d\n ",area);
	return 0;
}