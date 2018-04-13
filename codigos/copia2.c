#include<stdio.h>

int funcao_particao(int vetor[],int inicio, int fim ){
	int pivo, down, up, aux;
	pivo=vetor[inicio];
	down=inicio;
	up=fim;
	while(down<up){
		while(vetor[down]<=pivo && down<fim){
		    down=down+1;
		}
		while(vetor[up]>pivo) {
		    up=up-1;
		}
		if (down<up){
			aux=vetor[down];
			vetor[down]=vetor[up];
			vetor[up]=aux;
		}	

	}
	vetor[inicio]=vetor[up];
	vetor[up]= pivo;
	return up;
}
int  funcao_quicksort(int vetor[], int inicio, int fim){
	int pivo;
	if(inicio > fim){
		return 0;
	}
	pivo=funcao_particao(vetor, inicio, fim);
	funcao_quicksort(vetor, inicio, pivo-1);
	funcao_quicksort(vetor, pivo+1, fim);
}
int main(){
	int i, vetor[5];
	printf("entre com os valores\n");
	for (i=0; i<5; i++){
		scanf("%d", &vetor[i]);
	}
	funcao_quicksort(vetor, 0, 4);
	printf("vetor ordenado\n");
	for (i=0; i<5; i++){
		printf("%d\n", vetor[i]);
	}
	return 0;

}