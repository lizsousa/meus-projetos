/*
   Programa: Labirinto  [Recursivo]
*/

#include <stdio.h>
#include <stdlib.h>





int percorer(int x, int y, int matrix[][10]){

if((x >= 0 && x < 10)&&(y >= 0 && y < 10)){
  if(matrix[x][y] == 3){printf("\n%d ,%d",x,y);
return 1;
}



if(matrix[x][y] == 0||matrix[x][y]>2){return 0;}
else{
matrix[x][y] = 0;

if(percorer(x + 1, y, matrix) == 1){
            
printf("\n %d ,%d",x,y);
return 1;}

if(percorer(x, y + 1, matrix) == 1){
printf("\n %d ,%d",x,y);
return 1;}

if(percorer(x - 1, y, matrix) == 1){
printf("\n %d ,%d",x,y);
return 1;}

if(percorer(x, y - 1, matrix) == 1){
printf("\n %d ,%d",x,y);
return 1;}

  }
}
else
return 0;
}


int main{

  int m[10][10]={
    {0,0,0,0,0,0,0,0,0,0},
    {1,1,0,1,0,0,1,1,1,0},
    {0,1,0,1,0,0,1,0,1,0},
    {0,1,1,1,0,0,1,1,1,0},
    {0,0,1,0,0,0,1,0,0,0},
    {0,0,1,1,1,0,1,0,0,0},
    {0,1,0,0,1,1,1,0,0,0},
    {0,1,0,0,1,0,1,0,1,1},
    {0,1,1,1,1,0,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0}

  };


  printf("%d\n",percorer(0,0,&m));

}
