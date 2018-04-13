#include<stdio.h>

int funcao_particao(int vetor[], int inicio, int fim){
	int pivo, down, up, aux;
	pivo=vetor[inicio];
	down=inicio;
	up=fim;
	while(down < up){/*quer dizer que enquanto for verdade essa condiçao(down for menor up) 
		vai entrar aqui dentro desse laço de repetiçao e sair so quando dowm for maior q up*/
		while(vetor[down]<=pivo && down<fim){/* ao entrar ele vai verificar essa condiçao vetor na posiçao down ê menor ou igual ao pivo
		 e down e menor que fim, se for verdade down receber down  mais a proxima posiçao */
			down=down+1;
		}
		while(vetor[up]>pivo){/* depois ele vai verificar essa condiçao vetor na posiçao up  é maior que pivo,
		 se for verdade up receber up menos a proxima posiçao, ou seja volta uma posiçao para traz */
			up=up-1;
		}
		if (down<up){/*se down for maior que fim*/
			aux=vetor[down];
			vetor[down]=vetor[up];
			vetor[up]=aux;
		}
	}
	vetor[inicio]=vetor[up];/*se caso nao entrar no primeiro while ou seja se down for maior que up o vetor na posicao inicio
	recebe vetor na posicao up e vetor na posiçao up recebe pivo e retorna up */
	vetor[up]=pivo;
	return up;//esse retorno é essencial
}
int funcao_quicksort(int vetor[], int inicio, int fim){
	int pivo;
	if(inicio>fim){// se inicio maior que fim, tem que ordenador, certo! entao tem que chamar a funçao partiçao para ordenar
		return 0;//esse retorno é essencial
	}
	pivo=funcao_particao(vetor, inicio, fim);//aqui esta chamando a funçao partiçao para ordenar o vetor , 
	//passa o vetor, o inicio do vetor e o fim do vetor
	funcao_quicksort(vetor, inicio, pivo-1);//aqui é uma chamada da propria funçao quinksort
	//que recebe o vetor o inicio e o pivo -1, quer dizer que vai começar do fim voltando 
	funcao_quicksort(vetor, pivo+1, fim);//aqui vai começar do inicio mais 1
}
int main(){
	int vetor[5];
	int i;
	printf("entre com os valores\n");
	for (i=0; i<5; i++){//vai preencher o vetor na posiçao i
		scanf("%d", &vetor[i]);
	}
	funcao_quicksort(vetor, 0, 4);/*chama a funçao quicksort e passa um vetor a posicao inicial[0] e a posiçao final [4], 
	por o vetor tem 5 posicao {0, 1, 2, 3, 4}*/
	printf("vetor ordenado\n");
	for (i=0; i<5; i++){//aqui percorre o vetor para imprimir o vetor
		printf("%d\n",vetor[i] );
	}
	return 0;// lembrando retornos essenciais
}