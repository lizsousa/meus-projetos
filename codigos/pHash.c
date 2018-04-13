#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define TAM 10

int hash(int x){
	return(abs(x%TAM));
}
int colisao(int tabela[TAM], int elem, int h){
	int i=h;
	while(i<TAM && tabela[i]!=-1){
		i++;
	}if(i<TAM){
		tabela[i]=elem;
	}else{
		i=0;
		while(i<h && tabela[i]!=-1){
			i++;
		}if(i<h){
			tabela[i] = elem;
		}else{
			printf("não foi possivel inserir o elemento. Tabela cheia\n\n");
		}
	}
	
}

int inserir(int tabela[TAM], int elem){
	int h;
	h = hash(elem);
	if(tabela[h]!=-1){
		colisao(tabela,elem,h);
	}else{
		tabela[h]=elem;
	}
}
int impressao(int tabela[TAM])
{
	int i;
	for(i=0;i<TAM;i++){
		if(tabela[i]!=-1){
			printf("elemento%d |hash%d\n",tabela[i],i);
		}
	}
}
int main(){
	int tab[TAM];
	int op,n,i;
	for(i=0;i<TAM;i++)
		tab[i]=-1;
	INICIO:
	system("cls");
	printf("*******************PROGRAMA DE TABELA HASH*******************");
	printf("*************************************************************");
	
	printf("\n\n(1) PARA INSERCAO");
	printf("\n(2) PARA BUSCA");
	printf("\n(3) PARA EXCLUSAO");
	printf("\n(4) PARA IMPRESSAO");
	printf("\n(0) PARA SAIR DO SISTEMA");
	printf("\n\nEntre com uma opcao acima: ");
	scanf("%d",&op);
	switch(op)
	{
		case 1:
			system("cls");
			printf("*******************INSERCAO*******************\n\n");
			printf("Entre com o valor a ser inserido: ");
			scanf("%d",&n);
			inserir(tab,n);
			system("pause");
			break;
		case 2:
			system("cls");
			printf("*******************BUSCA*******************\n\n");
			system("pause");
			break;
		case 3:
			system("cls");
			printf("*******************EXCLUSAO*******************\n\n");
			system("pause");
			break;
		case 4:
			system("cls");
			printf("*******************IMPRESSAO*******************\n\n");
			impressao(tab);
			system("pause");
			break;
		case 0:
			printf("\nObrigado por usar nosso sistema");
			break;
		default:
			printf("POR FAVOR ENTRE COM UMA OPCAO VALIDA!!!");
			getchar();
			break;
	}
	if(op)
		goto INICIO;
	else
		getchar();
}

