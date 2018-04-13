
#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int info;   // chave
    struct No* left;    // ponteiro para a sub-árvore da esquerda
    struct No* right;    // ponteiro para a sub-árvore da direita

}No;


int Arvore() {
    int a;
    struct No* raiz;
    raiz = 0;
}
int localiza(int valor){
struct No *raiz;
struct No * tual = raiz;      // começamos pela raiz
    if (!atual){
      return 0;  // árvore vazia!  
    }
    
    while (atual->info != valor){
        if (valor < atual->info){
            atual = atual->left;
        } else {
            atual = atual->right;
        }if (!atual){
            return 0;  // não há filho, não encontrou!
        }
            
    }
    
    return atual; // encontrou!
}
int insere(int valor) {
    struct No* novo = new No(valor);  // cria o novo nó
    if (!raiz) {
        raiz = novo;
        return;
    }
    struct No* atual = raiz;  // começamos pela raiz
    struct No* pai = 0;       // guardamos o pai de cada um
     while (true) {
        pai = atual;   // atualiza o pai a cada iteração
        if (valor < atual->info) { // vai para esquerda?
            atual = atual->left;
            if (!atual) {          // fim da linha?
                pai->left = novo;   // insere aqui
                return;
            }
        }else{
            atual = atual->sad;    // vai para direita?
            if (!atual) {          // fim da linha?
                pai->right = novo;   // insere aqui
                    return;
            }
        }
    }
}
void emOrdem(No* atual) {
    if (!atual) return;  // no vazio?
    emOrdem(atual->left);
        printf("%i ", atual->info);
    emOrdem(atual->right);
}
void preOrdem(No* atual) {
    if (!atual) return;
        printf("%i ", atual->info);
    preOrdem(atual->left);
    preOrdem(atual->right);
}
void posOrdem(No* atual) {
    if (!atual) return;
    posOrdem(atual->left);
    posOrdem(atual->right);
        printf("%i ", atual->info);
    }
int menor(){
    No* atual = raiz;
    if (!atual) return 0;
    while(atual->left){
        atual = atual->left;
    }
    return atual->info;
}
int maior(){
    No* atual = raiz;
    if (!atual) return 0;
    while(atual->right){
        atual = atual->right;
    }
    return atual->info;
}
struct No *sucessor(No* atual){
    No* pai = atual;
    atual = atual->right; // primeira à direita
    if (atual->left != 0){
        while(atual->sae != 0){
            pai = atual;
            atual=atual->left;
        }
        if (atual->right != 0){
            pai->left = atual->right;
        } else {
            pai->left = 0;
        }
    } else {
        pai->right = atual->right;
    }
    return atual;
}
int remove(int valor){
    struct No* atual = raiz; // começamos pelo início :-)
    No* pai = 0; // raiz não tem pai :-(
    while(atual->info != valor){
        pai = atual;
        if (valor < atual->info) {
            atual = atual->left;
        }else {
            atual = atual->right;
        }if (atual == 0) 
            return; // não encontrou o valor a remover.
        }
        if (atual->left==0 && atual->right==0) { // remove folhas...
        if (atual == raiz) {
            raiz = 0;
            delete atual;
            return;
        }if (pai->left == atual) {
            pai->left = 0;
        } else {
            pai->right = 0;
        }
        delete atual;
    } else if (atual->right == 0) { // tem um filho esquerdo
        if (atual==raiz){
            raiz = atual->left;
            delete atual;
            return;
        }
        if (pai->left == atual){
            pai->left = atual->left;
        } else {
            pai->right = atual->left;
        }
    } else if (atual->left == 0) { // tem um filho direito
        if (atual==raiz) {
            raiz = atual->right;
            delete atual;
            return;
        }
        if (pai->left == atual) {
            pai->left = atual->right;
        } else {
            pai->right = atual->right;
        }
        delete atual;
    }
    if (atual->left!=0 && atual->right!=0){ // remove nó com dois filhos
        Struct No* suce = sucessor(atual);
        if (pai->left == atual) {
            pai->left = suce;
        } else {
            pai->right = suce;
        }
        suce->left = atual->left;
        suce->right = atual->right;
        delete atual;
    }
}
int nivel(int valor){
    struct  No* atual = raiz;      // começamos pela raiz
    if (atual==0) return 0;  // árvore vazia!
    int n = 1;
    while (atual->info != valor) {
        if (valor < atual->info) {
            n++;
            atual = atual->left;
        } else {
            n++;
            atual = atual->right;
        }
        if (atual==0) return 0;  // não há filho, não encontrou!
    }
    return n;
}
int altura(No* atual) {
    if (atual == 0) return 0; // a altura de uma árvore vazia é 0.
    int altleft = altura(atual->left);
    int altright = altura(atual->right);
    if (altleft > altright) return altleft + 1;
    else return altright + 1;
}
int qtdNos(No* atual) {
    if (atual == 0) return 0; // a altura de uma árvore vazia é 0.
    int qtdleft = qtdNos(atual->left);
    int qtdright = qtdNos(atual->right);
    return qtdleft + qtdright;
}
void insereBal(int vet[], int ini, int fim) {
    if (fim < ini) return;
    int meio = (ini + fim)/2;
    insere(vet[meio]);
    insereBal(vet,ini,meio-1);
    insereBal(vet,meio+1,fim);
}
};
int main() {
    int tam;    // tamanho do vetor ou quantidade de elementos da árvore
    int *vet;
    struct node *raiz;
       // vetor auxiliar na montagem da árvore balanceada
    arvore avl; // árvore
    printf("Informe a quantidade de nos da arvore: ");
    scanf("%d",&tam);
    vet = (int*) malloc (tam* sizeof(int));
    // insere no vetor para depois ordenar
    for (int i = 0; i < tam; i++)	{
        printf("Digite o proximo elemento: ");
        scanf("%d",&vet[i]);
        // vet[i] = i+1;
	}
	//ordenando o vetor
	int aux;
	for (int i = 0; i < tam-1; i++){
	    for (int j = 0; j < tam-1-i; j++){
	        if (vet[j] > vet[j+1]) { // troca
	            aux = vet[j];
	            vet[j] = vet[j+1];
	            vet[j+1] = aux;
	        }
	    }
	}
    // criando a árvore balanceada!
    insereBal(vet, 0, tam-1);
    printf("Pre-ordem...");
    preOrdem(raiz);
    printf("Altura:");
    altura(raiz);

}