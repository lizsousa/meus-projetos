#include <stdio.h>
#include <stlib.h>

struct node{
	int info;
	struct node* proximo;
};
struct node* inserir_lista(struct node* inicio, struct node* lista, int i){
	lista->elemento=i;
	lista->proximo=inicio;
	return(lista);
}
criar_node(struct node* no, int elem){
	no->proximo=null;
	no->info=elemento;
}	
struct node* retirar_lista(){
	struct node* no1;
	int x;
	if(lista->proximo==null){
		printf("\nimpossivel retirar elemento da lista");
		return(lista);
	}else{
		no1=lista;
		lista=no1->proximo;
		x=no1->elemento;
		printf("\nelemento foi removido com sucesso", x);
		return(lista);
	}
}
imprimir_lista( struct node lista){
	int aux;
	while(lista.proximo!=null){
		aux = lista.elemento;
		printf("\n%d \n", aux);
		lista=lista.prox;
	}

}
int menu(void){
	int opc;

	printf("\nEscolha a opcao\n");
	printf("\n1.inserir na lista\n");
	printf("\n2.retirar da lista\n");
	printf("\n3.imprimir a lista\n");
	printf("\nopcao\n");
	scanf("%d",&opc);
	return opc;
}
void opcao(node *lista, int op){
	node *tmp;
		switch(op){
			case 1:
			inserir_lista(lista);
			break;
		
			case 2:
			retirar_lista(lista);
			break;
		
			case 3:
			imprimir_lista(lista);
			break;
		
			defaulf;
			printf("\ncomando invalido\n");
		}
}

int main(){


	
	struct node* inicio;
	int elemento, aux;
	ini_lista=(struct node*)malloc(sizeof(struct node));
	ini_lista->info=-1;
	ini_lista->prox=null;
	printf("\ndigite o valor a ser incluido na pilha");
	scanf("%d, elemento");
	int op;
	do{
		op=menu();
		opcao(lista, op);

	}while(op);
	free(lista);
	return 0;
}