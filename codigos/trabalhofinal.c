#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100
#define true = 1;
#define false = 0;

typedef char TipoChave;
typedef struct CelulaStr *Apontador;

typedef struct {
  TipoChave Chave; //Valores a serem armazenados na pilha.
} TipoItem;

typedef struct CelulaStr {
   TipoItem Item; 
   Apontador Proximo;
} Celula;

typedef struct { 
   Apontador Fundo, Topo;
}TipoPilha;
/***********Prototipos da Pilha**************/
void Empilha (TipoItem , TipoPilha *);
void Desempilha (TipoItem *, TipoPilha *);
void FpVazia (TipoPilha *);
int Vazia (TipoPilha);
int main () {
   TipoItem item;
   TipoPilha pilha;
   int i = 0;
   int controle;
   char expressao[max], tipo, verifica;
   printf("Digite a expressao matematica : ");
   scanf("%s",expressao);
   FpVazia(&pilha);
   
   
      while (expressao[i] != '\0') { //Enquanto não encontrar o final da string
         if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {         
            item.Chave = expressao[i]; //Empilhando somente parenteses, chaves e colchetes.
            Empilha(item, &pilha);
         }
         else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']') {         
            Desempilha(&item, &pilha); //Desempilhando e testando se está fechado corretamente.
            switch (item.Chave) {
               case '(' : 
                  if (expressao[i] == ')'){
                     controle = 1;
                  }else {
                     controle = 0;
                     tipo = expressao[i];
                     verifica = item.Chave;                     
                  }
               break;
               case '{' :
                  if (expressao[i] == '}'){
                     controle = 0;
                  }else {
                     controle = 1;
                     tipo = expressao[i];
                     verifica = item.Chave;                                 
                  }
               break;
               case '[' :
                  if (expressao[i] == ']'){
                     controle = 0;
                  }else { 
                     controle = 1;            
                     tipo = expressao[i];
                     verifica = item.Chave;                    
                  }
               break;
               default : 
                  controle = 0; //Se for digitado ') } ]' e não tiver sido aberto antes
            }
         }     
      }

      if (controle==0 ){
         printf("Expressao Incorreta! Esperado '%c', Digitado '%c'\n", verifica, tipo);
      }else if (expressao[i-1] == '(' || expressao[i-1] == '{' || expressao[i-1] == '['){
         printf("Expressao Incorreta!\n");
      }else{ 
         printf("Expressao Correta!\n");
      }
   return 0;
}   


/***********Funções da Pilha**************/   

void FpVazia (TipoPilha *Pilha){
   Pilha->Topo = (Apontador) malloc(sizeof(Celula));
   Pilha->Fundo = Pilha->Topo;
   Pilha->Topo->Proximo = NULL;
}

void Empilha (TipoItem x, TipoPilha *Pilha){
   Apontador Aux;
   Aux = (Apontador) malloc (sizeof (Celula));
   Pilha->Topo->Item = x;
   Aux->Proximo = Pilha->Topo;
   Pilha->Topo = Aux;
}

int Vazia (TipoPilha Pilha) {
   return (Pilha.Topo == Pilha.Fundo);
}
void Desempilha(TipoItem *Item, TipoPilha *Pilha) {
   Apontador Aux;
   if (Vazia(*Pilha)){
      return;
   }else {
   Aux = Pilha->Topo;
   Pilha->Topo = Aux->Proximo;
   *Item = Aux->Proximo->Item;
   free(Aux);
   }
}
/*Esxemplo: 
[(8*7) + (6-5)] / {[(6+5)*2]/4} 
VÁLIDA
*8+7+ (/6 2) 
INVÁLIDA
9+3)– 6*2 + {[(6+5)*2/4} 
INVÁLIDA*/
