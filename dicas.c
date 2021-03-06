#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "verificacao.h"

typedef struct Linha Linha;
struct Linha {
  int numLine;
  int* sudoku;
};

void* verificarLinha(void *v){
  struct Linha* linha=v;
  int* toReturn=malloc(3*sizeof(int));
  int numLine = (*linha).numLine;
  int *sudoku = (*linha).sudoku;
  int *numlinha;
  numlinha = sudoku+numLine*9;
  short int *ja = malloc(9*sizeof(short int));
  int i;
  int j;

  for(i=0;i<9;i++){
    ja[i]=0;}

  for(i=0;i<9;i++){
    j= *(numlinha+i);
    ja[j] = 1;
  }
  //Apos a verificacao dos números, exibe na tela os valores possíveis nas posições vazias. 
  //printf("Valores possíveis em %d:\n", numLine+1);
  for (i = 0; i < 9; i++){
    j= *(numlinha+i);
    if (ja[j]==0) printf("%d", j);
    printf("\n");
  }
  toReturn[0]=1;
  toReturn[1]=numLine+1;
  toReturn[2]=j;
  return (void*) ja;
}

int dica(){
  short int *retorno;
  pthread_t thr[9];
  int *sudoku = malloc(81*sizeof(int));
  int i=0, j=0;
  short int *ja;
  printf("Escrever o Sudoku a verificar linha por linha\n");

  scanf( "%i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i %i", &sudoku[0], &sudoku[1], &sudoku[2],&sudoku[3],&sudoku[4],&sudoku[5],&sudoku[6],&sudoku[7],&sudoku[8],&sudoku[9],&sudoku[10], &sudoku[11], &sudoku[12],&sudoku[13],&sudoku[14],&sudoku[15],&sudoku[16],&sudoku[17],&sudoku[18],&sudoku[19],&sudoku[20], &sudoku[21], &sudoku[22],&sudoku[23],&sudoku[24],&sudoku[25],&sudoku[26],&sudoku[27],&sudoku[28],&sudoku[29],&sudoku[30], &sudoku[31], &sudoku[32],&sudoku[33],&sudoku[34],&sudoku[35],&sudoku[36],&sudoku[37],&sudoku[38],&sudoku[39],&sudoku[40], &sudoku[41], &sudoku[42],&sudoku[43],&sudoku[44],&sudoku[45],&sudoku[46],&sudoku[47],&sudoku[48],&sudoku[49],&sudoku[50], &sudoku[51], &sudoku[52],&sudoku[53],&sudoku[54],&sudoku[55],&sudoku[56],&sudoku[57],&sudoku[58],&sudoku[59],&sudoku[60], &sudoku[61], &sudoku[62],&sudoku[63],&sudoku[64],&sudoku[65],&sudoku[66],&sudoku[67],&sudoku[68],&sudoku[69],&sudoku[70], &sudoku[71], &sudoku[72],&sudoku[73],&sudoku[74],&sudoku[75],&sudoku[76],&sudoku[77],&sudoku[78],&sudoku[79],&sudoku[80]);
  struct Linha linha;
  linha.sudoku=sudoku;


  for (i = 0; i < 9; i++) {
    linha.numLine=i;
    pthread_create(&thr[i], NULL, verificarLinha, (void*) &linha);
  }

  for (i = 0; i < 9; i++) {
    pthread_join(thr[i], (void **) retorno);
    ja = (short int *) retorno;
    printf("Para a linha %d:\n",i);
    printf("(");
    for (j = 0; j < 9; j++){
      if (ja[j]==0) printf("%d", j);
    }
    printf(")");
    /* if (*retorno == 0){
       printf("Thread encerrou normalmente.\n");}
       else{
    //  printf("Thread encerrou com valor: %d\n", retorno[0]);
    printf("A linha %d contém duas ocorerencias do numero %d",retorno[1],retorno[2]);
    }*/

  } 



  return 0;

}

int main(){
  dica();
  return 0;
}
