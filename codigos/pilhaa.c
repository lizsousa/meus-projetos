#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAMANHO 20
typedef struct pilha
{
	int topo;
	char elementos[TAMANHO];
}pilha;

int tamanho_string(char *st);
int pilha_vazia(struct pilha p);
void empilhar(struct pilha *p, char simbolo);
char desempilhar(struct pilha *p);
char topo_da_pilha(struct pilha p);
int main(){

   	int i = 0;
   	bool check;

   	char expressao[TAMANHO];

   	printf("Digite a expressao matematica : ");

   	scanf(expressao);

   	pilha_vazia(&pilha); 

      while (expressao[i] != '{FONTE}') { //Enquanto não encontrar o final da string

         if (expressao[i] == '(' || expressao[i] == '{' || expressao[i] == '[') {         

            item.Chave = expressao[i]; //Empilhando somente parenteses, chaves e colchetes.

            Empilha(item, &pilha);

         }

         else if (expressao[i] == ')' || expressao[i] == '}' || expressao[i] == ']') {         

            Desempilha(&item, &pilha); //Desempilhando e testando se está fechado corretamente.

               switch (item.Chave) {

                  case '(' : 

                     if (expressao[i] == ')')

                        check = true;

                     else {

                        check = false;

                        tipo = expressao[i];

                        verifica = item.Chave;                     

                     }

                  break;

                  case '{' :

                     if (expressao[i] == '}')

                        check = true;

                     else {

                        check = false;

                        tipo = expressao[i];

                        verifica = item.Chave;                                 

                     }

                  break;

                  case '[' :

                     if (expressao[i] == ']')

                        check = true;

                     else { 

                        check = false;             

                        tipo = expressao[i];

                        verifica = item.Chave;                     

                     }

                  break;

                  default : 

                     check = false; //Se for digitado ') } ]' e não tiver sido aberto antes

               }

         }      

      i++;

      }

      if (!check)

         printf("Expressao Incorreta! Esperado '%c', Digitado '%c'\n", verifica, tipo);

      else if (expressao[i-1] == '(' || expressao[i-1] == '{' || expressao[i-1] == '[')

         printf("Expressao Incorreta!\n");

      else 

         printf("Expressao Correta!\n");

            

   return 0;

}   


	char expressao[TAMANHO], elem;
	int cont, i, valida, tamanho;
 	struct pilha p;
	int opcao;

	
		do{
			printf("\nDigite a expressao matematica desejada: ");
			scanf("%s",expressao);
			tamanho = tamanho_string(expressao);
			printf("%d",tamanho);
			p.topo = -1;
			cont = 0;
			valida = 1;
			elem = expressao[cont];

			for ( cont = 0; expressao[cont] != '\0'; ++i) {
      		char c;
      		switch (expressao[cont]) {
	         	case ')': 
	         		if (pilha_vazia (p)) 
	         			return 0;
	                	c = desempilhar(  p);
	                if (c != '(') 
	                	return 0;
	            break;
         		case ']': 
         			if (pilha_vazia (p))
         				return 0;
                   		c = desempilhar ( struct p);
                   if (c != '[') return 0;
                break;

                case '}': 
         			if (pilha_vazia (p))
         				return 0;
                   		c = desempilhar( struct p);
                   if (c != '{') return 0;
                break;

         		default:  empilhar (expressao[cont]);
     		}
   
			
			}
		    if(valida==1 && pilha_vazia(s)){
				printf("Expressao Valida\n");
			}else{
				printf("Expressao Invalida\n");
			
			}
		    printf("deseja repitir a operaçao? (1/sim (0/nao\n");
	        scanf(" %d",&opcao);

	    }while(opcao != 0);  	
	
}
int tamanho_string(char *st){
	int i;
	for(i=0;st[i]!='\0';i++);
	return(i);
}
int pilha_vazia(struct pilha p){
	if(p.topo == -1)
		return(1);
	else
		return(0);
}
void empilhar(struct pilha *p, char simbolo){
	int top;
	top = p->topo;
	p->elementos[top+1] = simbolo;
	p->topo = top + 1;
}
char desempilhar(struct pilha *p){
	char aux;
	int top;
	if(pilha_vazia(*p))
	{
		printf("\nA pilha esta vazia, impossivel desempilhar");
		return('0');
	}
	else{

		aux = p->elementos[p->topo];
		top = p->topo;
		p->topo = top - 1;
		return(aux);
	}
}

char topo_da_pilha(struct pilha p){
	return(p.elementos[p.topo]);
}



