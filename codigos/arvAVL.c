#include <stdio.h>
#include <stdlib.h>

struct node {

    int chave,h;
    struct node *esq;
    struct node *dir;

};

typedef struct node Node;
typedef struct node *pont;


pont inicializa (){


    return NULL;

}

pont cria_no (int x){


    pont aux;
    aux = (pont) malloc (sizeof(Node));
    aux->chave=x;
    aux->dir=NULL;
    aux->esq=NULL;
    aux->h=0;

    return aux;


}

int max (int a, int b){

    if (a>b) return a;
    else return b;
}

int altura (pont raiz){


    if (raiz==NULL) return -1;
    else return raiz->h;


}

pont direita (pont raiz){

    pont aux;
    aux=raiz->esq;
    raiz->esq=aux->dir;
    aux->dir=raiz;

    raiz->h=max(altura(raiz->dir),altura(raiz->esq))+1;
    aux->h=max(altura(raiz->esq),raiz->h)+1;

    return aux;

}

pont esquerda (pont raiz){


    pont aux;
    aux=raiz->dir;
    raiz->dir=aux->esq;
    aux->esq=raiz;


    raiz->h=max(altura(raiz->dir),altura(raiz->esq))+1;
    aux->h=max(altura(raiz->dir),raiz->h)+1;

    return aux;

}
pont direitaEsquerda( pont raiz){

    raiz->dir=direita(raiz->dir);
    return esquerda(raiz);

}

pont esquerdaDireita(pont raiz){

    raiz->esq=esquerda(raiz->esq);
    return direita(raiz);

}

pont atualiza(pont raiz){

    if(raiz!=NULL){

        raiz->h=max(altura(raiz->esq),altura(raiz->dir))+1;

    }

    return raiz;

}

pont balancear(pont raiz){

  if(raiz!=NULL){


	if (altura(raiz->dir)-altura(raiz->esq)==-2){

                if(altura(raiz->esq->esq)>=altura(raiz->esq->dir)){

                      raiz=direita(raiz);
                }

                else raiz=esquerdaDireita(raiz);

    }

       if (altura(raiz->dir)-altura(raiz->esq)==2){

            if(altura(raiz->dir->dir)>=altura(raiz->dir->esq)){

                    raiz=esquerda(raiz);
            }

            else raiz=direitaEsquerda(raiz);

    }


}


	return raiz;
}

pont remover_no (pont raiz, int valor)

{

    pont aux;

    if (raiz == NULL)

        return NULL;

    if (valor<raiz->chave) raiz->esq = remover_no(raiz->esq, valor);

    if (valor>raiz->chave)  raiz->dir =remover_no(raiz->dir, valor);

    if(valor==raiz->chave){
        if (raiz->esq == NULL && raiz->dir == NULL) {
            free (raiz);
            raiz = NULL;
        }
        else if (raiz->esq == NULL) {
            aux=raiz;
            raiz = raiz->dir;
            free (raiz);
        }

    else if (raiz->dir == NULL) {
        aux = raiz;
        raiz = raiz->esq;
        free (raiz);
}

    else {

        aux = raiz->esq;
        while (aux->dir != NULL)
                aux= aux->dir;
        aux->chave = aux->chave;
        aux->chave = valor;
        aux->esq = remover_no(raiz->esq,valor);
}
}



    raiz=balancear(raiz);
    raiz=atualiza(raiz);

     return raiz;

}

pont inserir(pont raiz, int x){


    if(raiz==NULL) return cria_no(x);

    if(x<raiz->chave)

            raiz->esq=inserir(raiz->esq,x);

    if(x>raiz->chave)

            raiz->dir=inserir(raiz->dir,x);

    raiz=balancear(raiz);

    raiz=atualiza(raiz);

    return raiz;


}


int busca_no (Node* raiz, int x){


    if(raiz==NULL) return 0;

    if (x==raiz->chave) return x;

    else if(x<raiz->chave) return busca_no(raiz->esq,x);

    else if(x>raiz->chave) return busca_no(raiz->dir,x);




}

void imprime(pont raiz){


    if(raiz!=NULL){

        imprime(raiz->esq);

        printf("| %d |\t",raiz->chave);

        imprime(raiz->dir);

    }


}

int main()
{
    int x;
    pont raiz=NULL;
    int escolha;
    int continuar=1;
    int num;
    while(continuar==1) {

        printf("\n\t\tMENU\n");
        printf("\n1 - Insert\n");
        printf("\n2 - Remove\n");
        printf("\n3 - Print\n");
        printf("\nDigite sua escolha: \n");
        scanf("%d",&escolha);
        system("cls");
        switch(escolha){

            case 1:

                printf("\nDigite os elementos. A contagem é interrompida, quando o -1 é identificado. \n");

                scanf("%d",&x);

                while(x!=-1){

                    raiz=inserir(raiz,x);
                    scanf("%d",&x);
                }
                system("cls");

            break;

            case 2:

                printf("\nDigite elemento a ser removido: \n");

                int r;
                scanf("%d",&r);
                num=busca_no(raiz,r);
                if(num==r) raiz=remover_no(raiz,r);
                else printf("\nNo nao encontrado.\n");
                system("cls");

                break;

            case 3:

                printf("Arvore:\n");
                imprime(raiz);

                break;

            default:

                printf("\nEscolha invalida.\n");
                break;



    }
        printf("\nDeseja continuar no MENU? 1-Sim / 0 - Nao\n");
        scanf("%d",&continuar);
        system("cls");

    }

    return 0;

}

