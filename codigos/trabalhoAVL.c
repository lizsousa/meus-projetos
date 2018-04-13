#include <stdio.h>
#include <stdlib.h>

struct node {

    int chave, item;
    struct node *left;
    struct node *right;
};

typedef struct node Node; 
typedef struct node *ponteiro;
//prototipos para sa funçoes

int maior_no (int x, int y);
int altura (ponteiro raiz);
void imprimir(ponteiro raiz);
int buscar (Node* raiz, int x);
ponteiro criar (int x);
ponteiro rotation_right (ponteiro raiz);
ponteiro rotation_left (ponteiro raiz);
ponteiro right_left( ponteiro raiz);
ponteiro left_right(ponteiro raiz);
ponteiro atualiza(ponteiro raiz);
ponteiro balancear(ponteiro raiz);
ponteiro remover(ponteiro raiz, int valor);
ponteiro inserir(ponteiro raiz, int x);


//funçao para criar um novo no
ponteiro criar (int x){

    ponteiro aux;
    aux = (ponteiro) malloc(sizeof(Node));
    aux->chave= x;
    aux->right=NULL;
    aux->left=NULL;
    aux->item=0;

    return aux;


}
//funçao recebe a raiz da arvore e insere um elemento
ponteiro inserir(ponteiro raiz, int x){


    if(raiz==NULL){
        return criar(x);
    }if(x<raiz->chave){

        raiz->left=inserir(raiz->left,x);

    }if(x>raiz->chave)

            raiz->right=inserir(raiz->right,x);

    raiz=balancear(raiz);

    raiz=atualiza(raiz);

    return raiz;
}
//para excluir o no

ponteiro remover (ponteiro raiz, int valor){

    ponteiro aux;

    if (raiz == NULL){

        return NULL;
    }
    if (valor<raiz->chave) raiz->left = remover(raiz->left, valor);

    if (valor>raiz->chave)  raiz->right =remover(raiz->right, valor);

    if(valor==raiz->chave){
        if (raiz->left == NULL && raiz->left == NULL) {
            free (raiz);
            raiz = NULL;
        }
        else if (raiz->left == NULL) {
            aux=raiz;
            raiz = raiz->right;
            free (raiz);
        }

    else if (raiz->right == NULL) {
        aux = raiz;
        raiz = raiz->left;
        free (raiz);
    }

    else {
        Node* temp = malloc(sizeof(aux->chave));
        aux = raiz->left;
        while (aux->right != NULL)
            aux= aux->right;
            aux->right = temp;
            aux->chave = valor;
            aux->left = remover(raiz->left,valor);
            free(temp);
    }
}



    raiz=balancear(raiz);
    raiz=atualiza(raiz);

     return raiz;

}

//funçao para  verificar qual maior e retorna o mesmo 
int maior_no (int x, int y){ 

    if (x>y){
        return x;
    }else{
        return y;
    }
}
//funçao verifica a altura
int altura (ponteiro raiz){ 


    if (raiz==NULL){
        return -1;
    }else{
        return raiz->item;
    }
}
//rotacao simples para a direita
ponteiro rotation_right (ponteiro raiz){

    ponteiro aux;
    aux=raiz->left;
    raiz->left=aux->right;
    aux->right=raiz;

    raiz->item= maior_no(altura(raiz->right),altura(raiz->left))+1;
    aux->item=maior_no(altura(raiz->left),raiz->item)+1;

    return aux;
}
//rotacao simples para a esquerda
ponteiro rotation_left (ponteiro raiz){
    ponteiro aux;
    aux=raiz->right;
    raiz->right=aux->left;
    aux->left=raiz;

    raiz->item= maior_no(altura(raiz->right),altura(raiz->left))+1;
    aux->item= maior_no(altura(raiz->right),raiz->item)+1;

    return aux;

}
//rotacao dupla direita esquerda
ponteiro right_left( ponteiro raiz){

    raiz->right=rotation_right(raiz->right);
    return rotation_left(raiz);

}
//rotacao dupla esquerda direita
ponteiro left_right(ponteiro raiz){

    raiz->left=rotation_left(raiz->left);
    return rotation_right(raiz);

}
//atualiza a altura da arvore
ponteiro atualiza(ponteiro raiz){

    if(raiz!=NULL){

        raiz->item= maior_no(altura(raiz->left),altura(raiz->right))+1;
    }
    return raiz;
}
//para balancear a arvore, caso esteja desbalanceada
ponteiro balancear(ponteiro raiz){

  if(raiz!=NULL){


	if (altura(raiz->right)-altura(raiz->left)==-2){

        if(altura(raiz->left->left)>=altura(raiz->left->right)){

            raiz=rotation_right(raiz);
        }
        else{
            raiz=left_right(raiz);
        }

    }if (altura(raiz->right)-altura(raiz->left)==2){

        if(altura(raiz->right->right)>=altura(raiz->right->left)){
            raiz=rotation_left(raiz);
        }
        else 
            raiz=right_left(raiz);

    }


}


	return raiz;
}



//funçao para imprimir a arvore
void imprimir(ponteiro raiz){

    if(raiz!=NULL){

        imprimir(raiz->left);

        printf("%d ",raiz->chave);

        imprimir(raiz->right);

    }


}
//funçao para buscar o elemento
int buscar (Node* raiz, int x){

    if(raiz==NULL){ 
        return 0;

    }
    if (x==raiz->chave){
        return x;
    }else if(x<raiz->chave){

        return buscar(raiz->left,x);

    }else if(x>raiz->chave){
        return buscar(raiz->right,x);
    }

}

int main(){

    int valor, i, variavel, quant;
    char controle;
    ponteiro root= 0;
    ponteiro raiz;



    do{
        printf("\nQual operaçao deseja realizar\n");
    
        printf("\n0: Para Inserir elementos na arvore");
        printf("\n1: Para Remover elementos da arvore");
        printf("\n2: Para imprimir elementos da arvore\n");
        scanf("%d",&variavel);

        switch(variavel){

            case 0:
                
            
                
                printf("\nEntre com os valores : Quando nao quiser colocar mas elementos digite -1\nE para sair da funçao digite 4\n");

                scanf("%d",&valor);

                while(valor!=-1){

                    root=inserir(root,valor);
                    scanf("%d",&valor);
                }
                

            break;

            case 1:

                printf("\nDigite elemento para removido: \n");
                int valor1;
                scanf("%d",&valor1);
                    quant=buscar(root,valor1);
                if(quant==valor1){
                    raiz=remover(root,valor1);
                }else{
                    printf("\nnumero nao encontrado.\n");
                }
                  printf("\nDigite elemento a ser removido: \n");

                break;

            case 2:

                printf("A arvore nao imprimi elementos repitidos\nArvore:\n");
                imprimir(root);

                break;

            default:

                printf("\nEscolha invalida.\n");
                break;

        }

    }while(variavel!= 4);
    

    return 0;

}

