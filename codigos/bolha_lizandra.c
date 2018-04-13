#include<stdio.h>
int main(){
	int aux, i, j;
	int vetor[10];

	printf("digite os valores\n");
	for ( i = 0; i < 10; i++){
		scanf("%d", &vetor[i]);
	}
	for (i = 0; i < 10; i++){
		for(j=0; j<9; j++){
			if(vetor[j] > vetor[j+1]){
				aux= vetor[j+1];
				vetor[j + 1]= vetor[j];
				vetor[j]=aux;
			}
		}
	}
	printf("vetor ordenado\n");
	for (i = 0; i < 10; i++){
		printf("%d\n", vetor[i] );
	}
	return 0;
}














