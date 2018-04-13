#include <stdlib.h>
#include <stdio.h>
#define MAX 20
struct fila{
	char vetor[MAX];
	int inicio, fim, cont;	
	Fila* dados;
};
void criar_Fila(Fila* fi);
int fila_Vazia(Fila* fi);
int fila_Cheia(Fila* fi); 
int inserir_Fila(Fila* fi, char elem);
char retirar_Fila(Fila* fi);
void criar_Fila(struct fila, Fila* fi){
	fi->vetor[MAX];
	f->dados=(Fila*) malloc(f->MAX * sizeof(fila)); 
	fi->inicio=-1;
	fi->fim=0;
	fi->cont=0;
}
int fila_Vazia(Fila* fi){

}
int fila_Cheia(Fila* fi){

} 
int inserir_Fila(Fila* fi, char elem){

}
char retirar_Fila(Fila* fi){
	
}
