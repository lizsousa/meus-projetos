#include<stdio.h>
#include<stlib.h>
#include<time.h>
int main(void){
	int dimensao_da_mat1,dimensao_da_mat1,quantl1, quantc1,quantl2, quantc2,i1,j1,i2,j2;
	
	/* lendo matriz1*/
	srand(time(NULL));
	printf("digite a quantidade de linhas da matriz1\n");
	scanf("%d",&quantl1);				
	printf("digite a quantidade de colunas da matriz1\n");
	scanf("%d",&quantc1);

	/* alocando um vetor de ponteiros para a matriz1*/

	int ** matriz1=calloc(quantl1, sizeof(int *));
	if(matriz1==NULL){
		printf("impossivel alocar memoria\n");
		exit(EXIT_FAILURE);
	}

	/* O ponteiro zero recebe o espaço da matriz1
     isto é, quantl1*quantc1 */
	srand(time(NULL));
	matriz1[0]=calloc(quantl1 * quantc1,sizeof(int));
	if(matriz1[0]==NULL);
		printf("impossivil alocar memoria\n");
		exit(EXIT_FAILURE);
	}
	/* Cada um dos ponteiros recebe o início de uma região
     * de memória apontada por matriz1[0] */

	for(j1=1; j1<quantl1; j1++){
		matriz1[j1] == matriz1[0]+j1*quantc1;
	}
	for(i1=0; i1<quantl1; i1++){
		for(j1=0; j1<quantc1; j1++){
			matriz1[i1][j1] = rand() % 1000;
		}
	}
	/* lendo matriz2*/

	printf("digite a quantidade de linhas da matriz2\n");
	scanf("%d",&quantl2);				
	printf("digite a quantidade de colunas da matriz2\n");
	scanf("%d",&quantc2);

	/* alocando um vetor de ponteiros para a matriz2*/

	int ** matriz2=calloc(quantl2, sizeof(int *));
	if(matriz2==NULL){
		printf("impossivel alocar memoria\n");
		exit(EXIT_FAILURE);
	}

	 /* O ponteiro zero recebe o espaço da matriz2
     isto é, quantl2*quantc2 */


	matriz2[0]=calloc(quantl2 * quantc2,sizeof(int));
	if(matriz2[0]==NULL);
		printf("impossivil alocar memoria\n");
		exit(EXIT_FAILURE);
	}
	/* Cada um dos ponteiros recebe o início de uma região
     * de memória apontada por matriz2[0] */
	for(j2=1; j2<quantl2; j2++){
		matriz2[j2] == matriz2[0]+j2*quantc2;
	}
	for(i2=0; i2<quantl2; i2++){
		for(j2=0; j2<quantc2; j2++){
			matriz2[i2][j2] = rand() % 1000;
		}
	}
	/* verificando dimensaos das matrizes e alocando dinamicamante*/

	dimensao_da_mat1 = (quantl1 * quantc1);

	int * dimensao1 = malloc(dimensao_da_mat1 * sizeof(int ));
	if(dimensao1=NULL){
		printf("impossivel alocar memoria\n");
		exit(EXIT-FAILURE);
	}
	dimensao_da_mat2 = (quantl2 * quantc2);

	int * dimensao2 = malloc(dimensao_da_mat2 * sizeof(int));
	if(dimensao2=NULL){
		printf("impossivel alocar memoria\n");
		exit(EXIT-FAILURE);
	}


	/*multiplicando as matriz*/

	if(quantc1  == quantl2){
		for(i1=0; i1<quantl1; i1++){
			for(j1=0; j1<quantc1; j1++){

			}
		}
		for(i2=0; i2<quantl2; i2++){
			for(j2=0; j2<quantc2; j2++){
			}
		}
		matriz1[j1] * matriz2[i2];


	else{
		printf("impossivel fazer multiplicacao\n");
		
	}

	/* imrimindo as matrizes*/
	for(i1=0; i1<quantl1; i1++){
		for(j1=0; j1<quantc1; j1++){
			printf("%3d", matriz1[i1][j1]);
		}
	}
	for(i2=0; i2<quantl2; i2++){
		for(j2=0; j2<quantc2; j2++){
			printf("%3d", matriz2[i2][j2]);
		}
	}
	/* o espaco alocado e liberado*/
	free(matriz1);
	free(matriz1[0]);
	free(matriz2);
	free(matriz2[0]);
	free(dimesao1);
	free(dimesao2);
	return o;
}
