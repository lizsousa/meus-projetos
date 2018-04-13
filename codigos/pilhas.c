#define N 100
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char pilha[N];
int t;
void criapilha (void);
void empilha (char y);
char desempilha (void);
char desempilha (void);
int pilhavazia (void);
// Esta função devolve 1 se a string s contém uma
// sequência bem-formada de parênteses e colchetes
// e devolve 0 se a sequência é malformada.
int main () {
  char s[N];
  char expressao[N];
  criapilha ();

  int i, valida=1;

  printf("\nDigite a expressao matematica desejada: ");
  scanf("%s",s);
  for (i = 0; s[i] != '\0'; i++) {
  
  

    char c;
    switch (s[i]) {
      case ')': 
        if (pilhavazia ()) 
          printf("1\n");
          return 0;
          c = desempilha ();
        if (c != '(') 
          return 0;
      break;
      case ']': 
        if (pilhavazia ()) 
          return 0;
          c = desempilha ();
        if (c != '[') return 0;
      break;
      case '}': 
        if (pilhavazia ()) 
          return 0;
          c = desempilha ();
        if (c != '{') return 0;
      break;
      default:  
        empilha (s[i]);
    }
    if(valida == 1 && pilhavazia()){
      printf("Expressao Matematica Valida!!!");
    }
    else{
      printf("Expressao Matematica Invalida!!!");
    }
  }
   
}


void criapilha (void) {
   t = 0;

}

void empilha (char y) {
   pilha[t++] = y;
}

char desempilha (void) {
   return pilha[--t];
} 

int pilhavazia (void) {
   return t <= 0;
}