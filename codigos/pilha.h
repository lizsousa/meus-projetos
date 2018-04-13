#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

#include <stdlib.h>

#define MAX 100
Struct Validacao_String{
	char eq[20], simb;
	int valida;
};
typedef Struct pilha Pilha;

Pilha* criar_Pilha();
void liberar_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int inserir_Pilha(Pilha* pi, Validacao_String vS);
int remover_Pilha(Pilha* pi);
int pilha_Cheia(Pilha* pi);
int pilha_Vazia(Pilha* pi);
int consulta_Topo_Pilha(Pilha* pi, Validacao_String *vS );
#endif