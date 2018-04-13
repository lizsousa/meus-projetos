#include<stdio.h>
#include<stdlib.h>
#define red 'R'
#define black 'B'
#define TAM 10

typedef struct no{
	int info;
	struct no *esq;
	struct no *dir;
	int cor;
}no;

typedef struct no* node;

int consulta (node* raiz, int valor);
struct no* rotacao_dir(struct no* a);
int removeArvore(node* raiz, int valor);
int cor(struct no* h);
void trocar_cor (struct no *h);
struct no* rotacao_esq(struct no* a);
struct no* move_2_esq_red(struct no* h);
struct no* move_2_dir_red(struct no* h);
struct no* balancear(struct no* h);
struct no* removerMenor(struct no* h);
struct no* procuraMenor(struct no* atual);
int inserir(node* raiz, int valor);
struct no* inserirNo(struct no* h, int valor, int *resp);
struct no* removeNo(struct no* h, int valor);
void  imprimir(no* raiz);




//Acessando a cor 
int cor(struct no* h){
	if(h==NULL){
		return black;
	}else{
		return h->cor;
	}
}
//trocar cor
void trocar_cor(struct no* h){
	h->cor = !h->cor;//o no da arvore recebe o inverso(se fo preto sera vermelho)
	if(h->esq!=NULL){
		h->esq->cor= !h->esq->cor;	
	}if(h->dir!=NULL){
		h->dir->cor= !h->dir->cor;
	}
}
//rotacao para esquerca
struct no* rotacao_esq(struct no* a){
	struct no* b=a->dir;
	a->dir=b->esq;
	b->esq=a;
	b->cor=a->cor;
	a->cor=red;
	return b;
	
}
struct no* rotacao_dir(struct no* a){
	struct no* b=a->esq;
	a->esq=b->dir;
	b->dir=a;
	b->cor=a->cor;
	a->cor=red;
	return b;


}
//mover um no vermelho para a esquerda
struct no* move_2_esq_red(struct no* h){
	trocar_cor(h);
	if(cor(h->dir->esq)==red){
		h->dir=rotacao_dir(h->dir);
		h=rotacao_esq(h);
		trocar_cor(h);
	}
	return h;
}
//mover um no vermelho para a direita 
struct no* move_2_dir_red(struct no* h){
	trocar_cor(h);
	if(cor(h->esq->esq)==red){
		h=rotacao_dir(h);
		trocar_cor(h);
	}
}
//balancear
struct no* balancear(struct no* h){
	if(cor(h->dir)==red){
		h=rotacao_esq(h);
	}if(h->esq!=NULL && cor (h->dir)==red && cor(h->esq->esq)==red){
		h=rotacao_dir(h);
	}if(cor(h->esq)==red && cor(h->dir)== red){
		trocar_cor(h);
	}
	return h;
}
// inserir 
int inserir(node* raiz, int valor){
	int resp;
	*raiz =  inserirNo(*raiz, valor, &resp);
	if((*raiz)!=NULL){
		(*raiz)->cor=black;
	}
	return resp;
}
//Auxiliar para inserir um novo no
struct no* inserirNo(struct no* h, int valor, int *resp){
	if(h==NULL){
		struct no *novo;
		novo =(struct no *)malloc (sizeof (struct no));
		if(novo==NULL){
			*resp = 0;
			return NULL;
		}else {
			novo->info=valor;
			novo->cor=red;
			novo->dir=NULL;
			novo->esq=NULL;
			*resp=1;
			return novo;
		}
	}if(valor==h->info){
		*resp=0;// valor ja existe, valor duplicado
	}else{
		if(valor<h->info){
			h->esq=inserirNo(h->esq, valor, resp);
		}else{
			h->dir=inserirNo(h->dir, valor, resp);
		}

	}if(cor(h->dir)==red && cor(h->esq)==black){
		h=rotacao_esq(h);

	}if(cor(h->esq)==red && cor(h->esq->esq)==red){
		h=rotacao_dir(h);
	}if(cor(h->esq)==red && cor(h->dir)==red){
		trocar_cor(h);

	}
	return h;
}
int consulta (node* raiz, int valor){
	if(raiz==NULL){
		return -1;
	}else{
		struct no* atual = *raiz;
		while(atual!=NULL){
		    if (valor == atual->info){
		    	return 2;
		    }if (valor > atual->info){
		    	atual = atual->dir;
		    }else{
		    	atual = atual->esq;
		    }
		}
	}
	return -1;
	

}
//funcao remover
int removeArvore(node* raiz, int valor){
	if(consulta(raiz, valor)){
		struct no* h = *raiz;
		*raiz = removeNo(h, valor);
		if((*raiz)!= NULL){
			(*raiz)->cor=black;
			return 1;
		}else{
			return 0;
		}
	}

}	

//funcao auxiliar remover 
struct no* removeNo(struct no* h, int valor){
	if(valor < h->info){
		if(cor(h->esq)==black && cor(h->esq->esq)==black){
			h=move_2_esq_red(h);
		}else{
			h->esq=removeNo(h->esq, valor);
		}
	}else{
		if(cor(h->esq)==red){
			h=rotacao_dir(h);
		}if(valor==h->info && h->dir==NULL){
			free(h);
			return NULL;
		}if(cor(h->dir)==black && cor(h->dir->esq)==black){
			h=move_2_dir_red(h);
		}if(valor==h->info){
			struct no* x=procuraMenor(h->dir);
			h->info=x->info;
			h->dir=removerMenor(h->dir);
		}else{
			h->dir=removeNo(h->dir, valor);
		}

	}
	return balancear(h);	
}
//remover menor
struct no* removerMenor(struct no* h){
	if(h->esq == NULL){
		free(h);
		return NULL;
	}if(cor(h->esq )== black && cor(h->esq->esq)== black){
		h=move_2_esq_red(h);

	}else{
		h->esq=removerMenor(h->esq);
		
	}
	return balancear(h);

}
// localioza menor a esquerda
struct no* procuraMenor(struct no* atual){
	struct no* node1 = atual;
	struct no* node2 = atual->esq;
	while(node2!=NULL) {
	    node1=node2;
	    node2=node2->esq;
	}
	return node1;
}
void  imprimir(no* raiz){

    if(raiz!=NULL){

        imprimir(raiz->esq);

        printf("%d",*(int*) raiz->info);

        imprimir(raiz->dir);

    }


}
int main(){
	struct node* raiz;
	int quant, valor,i, opcao;

	
	INICIO:
	system("clear");
	printf("****************************ARVORE***************************");
	printf("*************************************************************");
	
	printf("\n\n(1) PARA INSERCAO");
	printf("\n(2) PARA BUSCA");
	printf("\n(3) PARA EXCLUSAO");
	printf("\n(4) PARA IMPRESSAO");
	printf("\n(0) PARA SAIR DO SISTEMA");
	printf("\n\nEntre com uma opcao acima: ");
	scanf("%d",&opcao);
	switch(opcao){
		case 1:
			system("clear");
			printf("*******************INSERCAO*******************\n\n");
			printf("\nEntre com os valores : Quando nao quiser colocar mas elementos digite -1\nE para sair da funçao digite 4\n");
			scanf("%d",&valor);
			while(valor!=-1){
			raiz=inserir(raiz,valor);
            scanf("%d",&valor);
            }
	
			system("pause");
			break;
		case 2:
			system("clear");
			printf("*******************CONSULTA*******************\n\n");
			consulta(raiz, valor);
			system("pause");
			break;
		case 3:

			system("clear");
			printf("*******************REMOÇAO*******************\n\n");
			printf("\nDigite elemento para removido: \n");
            int valor1;
            scanf("%d",&valor1);
            printf("\nDigite elemento a ser removido: \n");

			system("pause");

			break;
		case 4:
			system("clear");
			printf("*******************IMPRESSAO*******************\n\n");
            imprimir(raiz);
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
	if(opcao)
		goto INICIO;
	else		getchar();

	return -1;
}



	
