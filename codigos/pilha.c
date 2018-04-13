#include <stdlib.h>
#include <stdio.h>
#define MAX 20

Struct Validacao_String{
	char pilha[MAX], elem;
	
};
typedef Struct pilha Pilha;

Pilha* criar_Pilha();

int tamanho_Pilha(Pilha* pi);
int inserir_Pilha(Pilha* pi, Validacao_String vS);
int remover_Pilha(Pilha* pi);
int pilha_Vazia(Pilha* pi);
int consulta_Topo_Pilha(Pilha* pi, Validacao_String *vS );

Struct pilha{
	int qtd, valida, cont;
	Struct validacao_String dados[MAX];
};
Pilha* criar_pilha(){
	Pilha* pi;
	pi = (Pilha*) malloc (sizeof(pilha));
	if(pi!=NULL)
		pi->qtd=0;
	return pi;
}

int tamanho_pilha(Pilha* pi){
	if(pi==NULL)
		return -1;
	else
		return pi->qtd;
}
int inserir_pilha(Pilha* pi, Validacao_String vS){
	if(pi==NULL)
		return 0;
	if (pilha_cheia(pi))
		return 0;
	pi->dados[pi->qtd]=vS;
	pi->qtd++;
	return 1;
}
int remover_Pilha(Pilha* pi){
	if (pi==NULL || pi->qtd==0)
		return 0;
	pi->qtd--;
	return 1;
	
}

int pilha_Vazia(Pilha* pi){
	if(pi==NULL)
		return -1;
	return(pi->qtd==0);
}
int consulta_Topo_Pilha(Pilha* pi, Validacao_String *vS ){
	if(pi==NULL || pi->qtd==0)
		return 0;
	*vS=pi->dados[pi->qtd-1];
	return 1;
}
int main(){
	
 	int i, tamanho;
	printf("\nDigite a expressao matematica desejada: ");
	scanf("%s",&dados);
	tamanho = tamanho_pilha(dados);
	printf("%d",tamanho);
	Pilha.qtd = -1;
	cont = 0;
	valida = 1;
	elem = dados[cont];
	while(cont < MAX || elem == NULL)	
	{
		if(elem == '(')
			 inserir_Pilha(&Pilha,elem);
		if(elem == ')')
		{
			if(pilha_vazia(Pilha* pi))
				valida = 0;
			else
				remover_Pilha(&pi);
		}
		elem = dados[cont];
		cont++;
	}
	if(valida==1 && pilha_vazia(Pilha* pi))
		printf("Expressao Matematica Valida!!!");
	else
		printf("Expressao Matematica Invalida!!!");
}