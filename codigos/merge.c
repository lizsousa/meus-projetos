#include<stdio.h>
#include<stdlib.h>

int merge(int v[], int inicio, int meio, int fim){
   int * temp, p1, p2, tamanho, i, j, k;
   int fim1 = 0, fim2 = 0;
   tamanho = fim - inicio + 1;
   p1 = inicio;
   p2 = meio + 1;
   temp = (int *) malloc (tamanho*sizeof(int));
   if(temp != NULL){
      for (i=0;  i<tamanho; i++){
         if (!fim1 && !fim2){
            if (v[p1] < v[p2]){//cobinar ordenado
               temp[i] = v[p1++];
            }else{
               temp[i]=v[p2++];
            }if (p1>meio){//vetor acabou?????
               fim1=1;
            }if (p2>fim){
               fim2=1;
            }
         }else{
            if (!fim1){//copiar o que sobrou
               temp[i]=v[p1++];
            
            }else{
               temp[i]=v[p2++];
               

            }
         }
         
      }
      for (j=0, k=inicio; j<tamanho; j++, k++) {//copiar do auxiliar para o original
         v[k]=temp[j];
      
      }

   }
   
   free(temp);
}

int merge_sort(int v[], int inicio, int fim){
   int meio;

   if(inicio<fim){
      meio = (inicio + fim)/2;
      merge_sort(v, inicio, meio);//chama a funçao para as duas metades
      merge_sort(v, meio+1, fim);
      merge(v, inicio, meio, fim);//cobina as 2 metades de forma ordenada

   }
}

int main(){

   int v[5], i;

   int inicio, fim, meio;

   
   printf("\nDigite o conteudo do vetor:\n");
   for (i=0; i<5; i++){
      scanf("%d",&v[i]);     
   }

   printf("\nConteudo digitado para o vetor:\n");
   for (i=0; i<5; i++){
      printf("%d\n",v[i] );   
   }
   
   merge_sort( v,0, 4);
   printf("vetor ordenado\n");
   for (i=0; i<5; i++){
      printf("%d\n",v[i] );
      
   }

   return 0;
}
