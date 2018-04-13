#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define TAM 10

int hash(int x){
	return(abs(x%TAM));

}
int colisao(int table[TAM], int elem, int h){
	int i = h;
	while(i<TAM && table[i]!=-1){
		i++;
	}if(i<TAM){
		table[i]=elem;
	}else{
		i=0;
		while(i<h && table[i]!=-1){
			i++;
		}if(i<h){
			table[i]=elem;
		}else{
			printf("\nnao é possivel inserir elemento na tabela.. tabela cheia");
		}
	}

}
int colisao1(int tableaux[TAM], int elem, int h){
	int i = h;
	while(i<TAM && tableaux[i]!=0){
		i++;
	}if(i<TAM){
		tableaux[i]=elem;
	}else{
		i=0;
		while(i<h && tableaux[i]!=0){
			i++;
		}if(i<h){
			tableaux[i]=elem;
		}else{
			printf("\nnao é possivel inserir elemento na tabela.. tabela cheia");
		}
	}

}
/*
int controle_de_colisao(int tableaux[TAM]){
	int i;
	for (i=0; i<TAM; i++){	
		tableaux[i]=0;
	}

}
*/
int inserir(int table[TAM],int tableaux[TAM], int elem){
	int i, j, h,cont=0;
	h = hash(elem);

	if(table[h]!=-1 && tableaux[h]!=0 ){
		colisao(table, elem, h);
		colisao1(tableaux, elem, h);

	
	}else{
		table[h]=elem;
		tableaux[h]=elem;
	}
	

}/*
int remover(int table[TAM], int elem){
	int h, i, j;
	int tableaux[TAM];
	h= hash(elem);
	for (i=0; i<TAM; i++){
		if (table[i]==elem){
		
		}
	}
	for(j=0; j<TAM; j++){
		tableaux[j]=0;

	}
	printf("\nESTE ELEMENTO NAO ESTA CONTIDO NA TABELA... ");

}
*/
int impresao(int table[TAM], int tableaux[TAM]){
	int i, j;
	for(i=0; i<TAM; i++){
		if(table[i] != -1){
			printf("\n elemento %d | hash %d", table[i], i);
		}

	}
	for(j=0; j<TAM; j++){
		if(tableaux[j] != -1){
			printf("\n elemento %d | hash %d", tableaux[j], j);
		}

	}

}
int main(){
	
	int table[TAM],tableaux[TAM], opcao, i, n;
	for(i=0;i<TAM;i++)
		table[i]=-1;
	INICIO:
	system("cls");
	printf("\n*************PROGRAMA DE TABELA HASH*************");
	printf("\n*************************************************");
	printf("\n**********1-INSERIR ELEMENTO NA TABELA***********");
	printf("\n**********2-BUSCAR ELEMENTO NA TABELA************");
	printf("\n**********3-EXCLUIR ELEMENTO NA TABELA***********");
	printf("\n**********4-IMPRIMIR ELEMENTO NA TABELA**********");
	printf("\n*******************0-SAIR************************");
	printf("\n*************************************************");
	printf("\n*************ESCOLHA UMA OPCAO ACIMA************\n");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			system("cls");
			printf("\n**********1-INSERIR ELEMENTO NA TABELA***********");
			printf("\nENTRE COM OS VALORES DESEJADOS\n");	
			scanf("%d", &n);	
			inserir(table,tableaux,n);	
			system("pause");

		break;

		case 2:
			system("cls");
			printf("\n**********2-BUSCAR ELEMENTO NA TABELA************");
			system("pause");
 		break;

		case 3:
			system("cls");
			printf("\n**********3-EXCLUIR ELEMENTO NA TABELA***********");
			printf("\nENTRE COM OS VALORES DESEJADOS\n");	
			scanf("%d", &n);
			//remover(table, n);
			system("pause");
		break;

		case 4:
			system("cls");
			printf("**********4-IMPRIMIR ELEMENTO NA TABELA**********");
			impresao(table, tableaux);
			system("pause");
		break;

		case 0:
			printf("\n*******************0-SAIR************************");
			printf("\nOBRIGADO POR USAR NOSSO SISTEMA");
		break;
		
		default:
			printf("OPERACAO INVALIDA\n");
			getchar();

	}
	if(opcao){
		goto INICIO;
	}else{
		getchar();
	}

	return 0;
}


