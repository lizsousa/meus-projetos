#include <stdio.h>

int main(){
	int vet[5];
	int i, j, aux;
	printf("entre com os valores\n");
	for(i=0; i<5; i++){
		scanf("%d", &vet[i]);
	}
	for(i = 0; i<5; i++){
		for(j=0; j<4; j++){
			if(vet[j] > vet[j+1]){
				aux = vet[j+1];
				vet[j+1] = vet[j];
				vet[j]=aux;
			}
		}
	}
	printf("vetor ordenado: \n");
	for (i=0; i<5; i++){
		printf ("%d \n", vet[i]);
	}
	return 0;
}

