#include<stdio.h>
#include<stdlib.h>
int main(){
 
int  ja, peso, dia, sexo=5,idade;
char nome[30];

int pode_doar=5;

    printf("Digite seu nome:\n");
    scanf("%s",nome);
 	
    printf("\n%s, Voce esta se sentindo bem de saude,\nE nao ingeriu alimentos gordurosos nas ultimas 4 horas?\n\nDigite 1, para sim e 0,caso contrario:\n", nome );
    scanf("%d", &pode_doar);
    while(pode_doar>1){
    	printf("Numero invalido, favor digitar 0 ou 1 \n");
    	scanf("%d", &pode_doar);
    }
    

    if(pode_doar ==1){
			
   			printf("\n%s, Digite seu sexo!\n\n1 para sexo masculino 0 para sexo feminino:\n", nome);
   			scanf("%d", &sexo);
   			while(sexo>1){
   				printf("Numero invalido, favor digitar 0 ou 1 \n");
   				scanf("%d", &sexo);
   				
   			}
   			switch (sexo){
		    	case 0:	


		    		printf("\n%s, Qual seu peso?\n", nome);
		    		scanf("%d", &peso);


		    		printf("\n%s, Qual sua idade?\n", nome);
		    		scanf("%d", &idade);

		    		if( peso>=50 && idade>=16 && idade<= 59){
		    				printf("\n%s, Voce ja doou sangue antes\n1 caso ja tenha doado e 0 caso contrario\n", nome);
		    				scanf("%d",&ja);
		    				if ( ja==1){
		    					printf("\n%s, Tem quantos dias que voce doou sangue pela ultima vez?\n", nome);
			    				scanf("%d",&dia);
			    				if ( dia>=90){
		    						printf("\n%s, Parabéns, voce esta apta para doar sangue\n", nome);
		    				
		    					}else{
		    						printf("\n%s, Infelizmente, voce nao esta apta para doar sangue\nvolte quando estiver com mas de 90 dias, obrigado\n", nome);
		    					}

		    				}else if(ja==0){
		    					if(idade>=60){
		    						printf("\n%s, Infelizmente, voce nao esta apta para doar sangue\nvolte quando estiver com mas de 90 dias, obrigado\n", nome);
		    					}else{
		    							printf("\n%s, Parabéns, voce esta apta para doar sangue\nprocura o Hemocentro mais proxima e salve vidas\n", nome);
		    					}
		    				}else{
		    					printf("\n ERRO\n");	
		    				}
		    				
		    		}
					else{
		    			printf("%s, Infelizmente, voce nao esta apta para doar sangue, obrigado\n", nome);
		    		}
		    	break;	
		    	case 1:	

		    		printf("\n%s, Qual seu peso?\n", nome);
		    		scanf("%d", &peso);

		    		printf("\n%s, Qual sua idade?\n", nome);
		    		scanf("%d", &idade);

		    		if( peso >=50 && idade>=16 && idade <= 59 ){

		    				printf("\n%s, Voce ja doou sangue antes\n1 caso ja tenha doado e 0 caso contrario\n", nome);
		    				scanf("%d",&ja);
		    				if ( ja==1){
		    					printf("\n%s, Tem quantos dias que voce doou sangue pela ultima vez?\n", nome);
			    				scanf("%d",&dia);
			    				if ( dia>=60){
		    						printf("\n%s, Parabéns, voce esta apto para doar sangue\n", nome);
		    				
		    					}else{
		    						printf("\n%s, Infelizmente, voce nao esta apto para doar sangue\nvolte quando estiver com mas de 90 dias, obrigado\n", nome);
		    					}

		    				}else if(ja==0){
		    					if(idade>=60){
		    						printf("\n%s, Infelizmente, voce nao esta apto para doar sangue\nvolte quando estiver com mas de 90 dias, obrigado\n", nome);
		    					}else{
		    							printf("\n%s, Parabéns, voce esta apto para doar sangue\nprocura o Hemocentro mais proxima e salve vidas\n", nome);
		    					}
		    				}else{
		    					printf("\n ERRO\n");	
		    				}
		    				
		    		}
		    	break;

		    	default:
		    		printf("Valor invalido\n");

	    	}		
		
	
	}else{
		printf("\n%s, Infelismente voce nao esta apta(o) para doar sangue\nvolte quando preencher os requisitos minimos, obrigado\n", nome);
	}

    return 0;
}