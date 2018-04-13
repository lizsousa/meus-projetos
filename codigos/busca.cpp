#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int chave;
	struct node *left;
	struct node *right;
	int fb;
}NODE;

int busca(NODE *r, int n){
	int a;
	while((r != NULL) && (r->chave != n)){
		if(r->chave > n){
			r = r->left;
		} else {
			r = r->right;
		}
	}
	
	if(r == NULL){
		return 0;
	} else {
		return 1;
	}
}

insere(NODE *r, NODE *pNovo){
	
	if(r->chave > pNovo->chave){
		if(r->left == NULL){
			printf("<--\n");
			printf("Inseriu\n");
			r->left= pNovo;
		}else{
			printf("<--\n");
			insere(r->left, pNovo);
		}	
	}else{
		if(r->right == NULL){
			printf("-->\n");
			printf("Inseriu\n");
			r->right= pNovo;
		}else{
			printf("-->\n");
			insere(r->right, pNovo);
		}
	}
	
}
int rotacao_dir(NODE *r){
	NODE *b=*r;
	NODE *a=*b-> left;
	b->left=a->right;
	a->right=b;
	a->fb=0;
	b->fb=0;
	*r=a;
}
int rotacao_esq(NODE *r){
	NODE *b=*r;
	NODE *a=*b-> right;
	b->right=a->left;
	a->left=b;
	a->fb=0;
	b->fb=0;
	*r=a;
}
int rotacao_dupla_esq_dir(NODE *r){
	NODE *c=*r;
	NODE *a=c->left;
	NODE *b=a->right;
	c->left=b->right;
	a->right=b->left;
	b->left=a;
	b->right=c;
}
int altura(NODE *r){
	int altura_left=0;
	int altura_right=0;
	if (r->left){
		altura_left=altura(r->left);
	}if (r->right){
		altura_right=altura(r->right);
	}return(MAX(altura->right, altura->left)+1);
}
void fator_balanceamento(NODE *r){
	r->fb = altura(fb->right)-altura(fb->left);
}

}
main(){
	int num;
	int teste;
	int i, n;
	struct node *raiz;
	struct node *novo;
	char resp = 'S';
	raiz = (NODE*) malloc (sizeof(NODE));
	raiz->left = NULL;
	raiz->right = NULL;


	printf("Quantidade de numeros a ser inseridos: ");
	scanf("%d", &n);
	
	printf("O primeiro valor digitado sera a raiz!\n");
	printf("Raiz: ");
	scanf("%d", &num);
	raiz->chave = num;
	
	for(i=1;i<n;i++){
		printf("No: ");
		scanf("%d", &num);
		novo = (NODE*) malloc (sizeof(NODE));
		novo->chave = num;
		novo->left = NULL;
		novo->right = NULL;
		insere(raiz, novo);
	}
	
	while(resp == 'S'){
		printf("====================================\n");	
		printf("Digite um numero para buscar: ");	
		scanf("%d", &num);
		printf("\n");	
		teste = busca(raiz,num);
		
		if(teste == 1){
			printf("Existe\n\n");
		} else {
			printf("Nao Existe\n\n");
		}	
		printf("Deseja fazer outra busca? (S para continuar)");
		scanf("%s", &resp);
	}
	
}
