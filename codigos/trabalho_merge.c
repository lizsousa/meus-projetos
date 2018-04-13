#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int *chave;
	struct node *esq;
	struct node *dir;
	
}node;	

	
/* ordena o vetor v[0..n-1] */

struct node *merge_sort( node *arvore, int n){
	node *no =  malloc(sizeof(int) * n);
	* merge_sort_ordena(arvore, 0, n-1);
	free(no);
}

/* ordena o vetor v[esq..dir] */
struct node *merge_sort_ordena(node *arvore, node *esq, node *dir) { 
	if (esq == dir){

		return 0;

	}else{
	
	node *meio = (esq + dir)/2;
	merge_sort_ordena(*arvore, *esq, *meio);
	merge_sort_ordena(*arvore, *meio+1, *dir);
	merge_sort_intercala(*arvore, *esq, *meio, *dir);

	}return 0;

}

/* intercala os vetores v[esq..meio] e v[meio+1..dir] */
struct node *merge_sort_intercala(node *arvore, int *esq, int *meio, int *dir) { 
int i, j, k;
int a_tam = meio-esq+1;
int b_tam = dir-meio;    
struct node *a = (node*) malloc(sizeof(node) * a_tam);
struct node *b = (node*) malloc(sizeof(node) * b_tam);
	for(i = 0; i < a_tam; i++) a[i] = v[i+esq];    
	for(i= 0; i< b_tam; i++) b[i] = v[i+meio+1];
	for(i = 0, j = 0, k = esq; k <= dir; k++) {        
		if(i== a_tam) v[k] = b[j++];
		else if(j == b_tam) v[k] = a[i++];
		else if(a[i].chave< b[j].chave) v[k] = a[i++];
		else v[k] = b[j++];

			}
		}
	}

	free(a); 
	free(b);
} 
