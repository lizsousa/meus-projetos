#include<stdio.h>
void Quicksort(vetor[10], int i, int j);

void ordem_do_vetor(vetor[10]){
	int a;
	int b = true;
			printf("vetor ordenado\n", vetor[a] );
}
void Quicksort(int vetor[10], int inicio, int fim){
	int pivo, aux, i, j, meio;
	i=inicio;
	j=fim;

	meio=(int)(i+j)/2;
	pivo=vetor[meio];

	do{
		while(vetor[i]<pivo) i=i+1;
		while(vetor[j]>pivo) j=j-1;
		if(i<=j){
			aux=vetor[i];
			vetor[i]=vetor[j];
			vetor[j]=aux;
			i=i+1;
			j=j-1;
		}
	}while(j<i);
	if(inicio<j)Quicksort(vetor, inicio, j);
	if(i<fim)Quicksort(vetor, i, fim);

}
int main(){
	int vetor[10];
	int a;

	printf("digite 10 valores:\n");
	for(a=0; a<10; a++){
		scanf("%d", &vetor[a]);
	}
	printf("vetor \n", );
	if(ordem_do_vetor){
		printf("vetor esta ordenado nao necessita de ordenaçao");

	}
	else{
		Quicksort(vetor, vetor[inicio], vetor[fim]);
	}
	return 0;
}