#include<stdio.h>
#include<stdlib.h>
typedef struct celula{
	int item;
	struct celula *prox;
  	

}node;
 node *topo;
 int pilha_contador;
	
void pilha_construtor();
void pilha_destructor();
int pilha_vazia(node *pilha);
void pilha_tamanho();
void pilha_push(int valor, node *pilha);
void pilha_pop(node *pilha);
void pilha_get(int valor);

void pilha_construtor(){

	topo = NULL;
	pilha_contador = 0;
}
/*
int pilha_destructor(){
	int aux;
	node *temp;
	temp = malloc(sizeof(node));
	if(pilha_vazia()){
		return 0;
	}else{
		while(topo!= NULL) {
			temp=(node*)topo;
			temp->prox=NULL;
			topo=topo->prox;
			free(temp);
		}
		pilha_contador = 0;
		return 1;
	}
}
*/
int pilha_vazia(node *pilha){
	if(topo==NULL){
		return 1;
	}else{
		return 0;
	}

}
/*
void pilha_tamanho(){
	return pilha_contador;
}
*/
void pilha_push(int valor, node *pilha){
	node *nova_celula = malloc(sizeof(node));
	if(nova_celula==NULL){
		
	}else{
		nova_celula->item = valor;
		nova_celula->prox = topo;
		topo = nova_celula;
		pilha = topo;
		pilha_contador++;
	
	}
}
void pilha_pop(node *pilha){//funçao desempilha
	node *temp;
	temp = (node*)malloc(sizeof(node));
	if(pilha_vazia(pilha)){
	
	}else{
	
		temp=topo;
		topo=topo->prox;
		pilha=topo;
		temp->prox=NULL;//medida de seguranḉa para desligar a celular removida da pilha
		free(temp);
		pilha_contador--;
	
	}


}
/*
int pilha_get(int valor){//elemento do topo da pilha
	if(pilha_vazia()){
		return 0;

	}else{
		valor=topo->item;
		return 1;
	}

}
*/
int main(){
	node *p1, *p2, *p3;
	char pilha[20];
	int i;
	int elem = 1;

	
	printf("digite a expressao");
	scanf("%s",pilha);
	for (i=0; i<20; i++ ){
		if(pilha[i] =='('){
			pilha_push(pilha[i], p1);
			
		}
		else{
			pilha_pop(p1);
			
		}
		
		if(pilha[i] =='['){
			pilha_push(pilha[i], p2);
			printf("1 \n");
		}
		else{
			pilha_pop(p2);

		}
		
		if(pilha[i] =='{'){
			pilha_push(pilha[i], p3);
		}
		else{
			pilha_pop(p3);
		}
			
		elem = 0;
	}
	if(elem = 1){
			printf("expressao valida \n");
	}else{
			printf("expressao invalida\n");
	}	
	return 0;	


}