
#include<stdio.h>
#include<stdlib.h>
/*desenvover um sistema que insere, e rempve elementos em uma arvore binaria balanceada, utilizando o algoritmo AVL. 
O sistema será composto de um menu que conterá os itens, inserçao, remoçao , impressao da arvore(ERD-esquerda, Raiz direita)*/
typedef struct node{
	int chave;
	int no;
	int fb;
	struct node *left;
	struct node *right;

}node;

int altura (node *raiz) {
   if (raiz == NULL) 
      return -1; // altura da árvore vazia
   else {
      int hl = altura (raiz->left);
      int hr = altura (raiz->right);
      if (hl < hr){
      	return hr + 1;
      }else{
      	return hl + 1;
      } 
   }
}

int fator_balanceamento(node *raiz, int fb){
	raiz->fb = altura(raiz->right) - altura(raiz->left);
	if(raiz == NULL){
		return 0;
	} else {
		return 1;
	}
}
int rotacao_dir(node *raiz){
	node *b=0;
	node *a=0;
	*b=*raiz;
	*a=*b->left;
	b->left=a->right;
	a->right=b;
	a->fb=0;
	b->fb=0;
	*raiz=*a;
}
int rotacao_esq(node *raiz){
	node *b=0;
	node *a=0;
	*b = *raiz;
	*a=*b->right;
	b->right=a->left;
	a->left=b;
	a->fb=0;
	b->fb=0;
	*raiz=*a;
}
int rotacao_dupla_esq_dir(node *raiz){
	node *c= 0;
	*c=*raiz;
	node *a=c->left;
	node *b=a->right;
	c->left=b->right;
	a->right=b->left;
	b->left=a;
	b->right=c;
}

/*funçao inserir elemento na arvore*/
int inserir(node *raiz, int no){
	node *aux;
	aux =(node*)malloc(sizeof(node));
	aux->chave = no;
	if(raiz->chave > aux->chave){
		if(raiz->left == NULL){
			raiz->left = aux;
			//printf("\nO elemento foi inserido a esquerda da raiz\n");
		}else{
			inserir(raiz->left, no);
			//printf("\nO elemento foi inserido a direita da esquerda da raiz\n");
		}
	}else{
		if(raiz->right == NULL){
			raiz->right = aux;
			//printf("\nO elemento foi inserido a direita da raiz\n");
		}else{
			inserir(raiz->right, no);
			//printf("\nO elemento foi inserido a esquerda da direita da raiz\n");
		}
	}
	return 0;
	
}



void remover(node *raiz, int valor){ 
   node aux;   
    if(!arvore_vazia(*raiz)){   
       // se o valor que será removido for menor que o nó atual,   
       if(valor < (*raiz)->info){    
           remover(&((*raiz)->left), valor); // faz recursividade á esquerda   
       }else{   
            // se o valor que será removido for maior que o nó atual,   
            if(valor > (*raiz)->info){    
                 remover(&((*raiz)->right), valor); // faz recursividade á direita.   
             }else{ // encontrou   
                // quando o nó a ser removido for encontrado,   
                if( !arvore_vazia((*raiz)->left) && !arvore_vazia((*raiz)->right) ){    
                     // verificamos se os nós filhos da esquerda e direita não são null.   
                     // se não forem null, buscamos o menor nó a partir do nó da direita.   
                     aux = minimo((*raiz)->right);    
                     (*raiz)->info = (aux->info);   
                     remover(&(*raiz)->right, (*raiz)->info);   
                }else{    
                       // caso os nó da direita e da esqueda, ou somente o da direita for null,    
                       // precisamos apenas remover   
                       aux = *raiz;    
                       // o nó atual e fazer ajustar os ponteiros    
                       if(arvore_vazia((*raiz)->left)){    
                           // se o nó da esquerda for vazio   
                           // o nó pai do atual, apontará para o filho da direita do nó atual.   
                           *raiz = (*raiz)->right;   
                       }    
                       else {   
                            // se o nó da esquerda não for vazio.   
                            // o nó pai do atual, apontará para o filho da esquerda do nó atual.   
                            *raiz = (*raiz)->left;                          
                       }   
                free(aux);   
                }   
            }        
       }    
    }     
}

tArv minimo(node *raiz){// procura o nó com valor mínimo   
    if(raiz == NULL{   
        printf("vazia");  
    }else{   
          if( arvore_vazia(raiz->left) ){   
              return raiz;   
          }else{   
              return minimo(raiz->right);   
          }   
    }   
}
tArv maximo(node *raiz){// procura o nó com valor máximo   
     if( !arvore_vazia(raiz) ){   
       while(raiz!= (raiz->right) ){   
          raiz = raiz->right;   
       }   
     }   
       return raiz;   
}/
int exibir_em_ordem(node* raiz){
    if(raiz != NULL){
        exibir_em_ordem(raiz->left);
        printf("%i ", raiz->chave);
        exibir_em_ordem(raiz->right);
    }
 
}
int exibir_pos_ordem(node* raiz){
    if(raiz != NULL){
        exibir_pos_ordem(raiz->left);
        exibir_pos_ordem(raiz->right);
        printf("%i ", raiz->chave);
        
       	
    }
 
}
int exibir_pre_ordem(node* raiz){
    if(raiz != NULL){
    	printf("%i ", raiz->chave);
        exibir_pre_ordem(raiz->left);
        exibir_pre_ordem(raiz->right);
        
       	
    }
 
}
	int imprimir(node *raiz){
		if (raiz == NULL){
			printf("\nvazia\n");
			return 0;
		}

		if((raiz->left==NULL)&& (raiz->right == NULL)) {
	        printf("%d ", raiz->chave);
	    }else{
	 
	        if (raiz->left!=NULL){
	        	
	            imprimir(raiz->left);
	            printf("%d ", raiz->chave);
	        }
	        if(raiz->right!=NULL) {
	            imprimir(raiz->right);
	        }
	    }
	    return 0;
	}
int main(){

	int num, num1;
	int teste, teste0, teste1, teste2, teste3;
	int i, n;
	struct node *raiz;
	struct node *no;
	int variavel;
	raiz = (node*) malloc (sizeof(node));
	raiz->left = NULL;
	raiz->right = NULL;
	

	do{
		printf("\nqual operaçao deseja realizar\n");
	
		printf("\n0: Para Inserir elementos na arvore");
		printf("\n1: Para Remover elementos da arvore");
		printf("\n2: Para imprimir elementos da arvore\n");
		scanf("%d",&variavel);

	switch(variavel){
		case 0:
			printf("Quantidade de numeros a ser inseridos:\n");
			scanf("%d", &n);
	
			printf("O primeiro valor digitado sera a raiz!\n");
			printf("Raiz: ");
			scanf("%d ", &num);
			
			
				raiz->chave = num;
				for(i=0;i<n-1;i++){
					scanf("%d", &num);
				
					no->chave = num;
					no->left = NULL;
					no->right = NULL;
					teste=inserir(raiz, num);	
				}
			
		break;

		case 1:
			printf("Digite um numero para excluir: ");	
			scanf("%d", &num);	
			teste = remover(raiz,num1);
			
		break;
		case 2:
			teste0 = imprimir(raiz);
			printf("\n ");

			teste3= exibir_em_ordem(raiz);
			printf("\n ");
			
			teste1= exibir_pos_ordem(raiz);
			printf("\n ");
			teste2= exibir_pre_ordem(raiz);
			printf("\n ");
			
		break;
	}


	}while(variavel!= 3);
	
	
		
}
	



