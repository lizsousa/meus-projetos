#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int maim(void){
	int l, c,i,j,encontrou=0;
	srand(time==NULL);
	printf("digite a quantidades de linhas\n");
	scanf("%d",&l);
	printf("digite a quantidades de colunas\n");
	scanf("%d",&c);
	int** m=calloc(l,sizeof(int *));
	if(m==NULL){
		printf("impossivil alocar memoria\n");
		exit(EXIT_FAILURE);
	}
	m[0]=calloc(l*c,sizeof(int *));
	if(m[0]==NULL);
		printf("impossivel alocar memoria\n");
		exit(EXIT_FAILURE);

	for(j=1; j<l; j++){
		m[j]=m[0]+j*c;
	}
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			m[i][j]= rand()%1000;
		}
	}
	for(i=0; i<l; i++){
		for(j=0; j<c; j++){
			if(m[i]==m[j]){
				encontrou=1;
				printf("valor repitido\n");
				printf("elemento eh:%d\n",i);
				printf("%d",m[i]);
				printf("elemento eh:%d\n",j);
				printf("%d",m[j]);
			}
			if(encontrou==0){
				printf("nenhum valor repitido\n");
		}
	}
	 for(i=0;i<l;i++){
        for(j=0;j<c;j++){
            printf("%3d ",m[i][j]);
        }
        printf("\n");
    }
    free(m[0]);
    free(m);


return 0;
}
