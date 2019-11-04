#include <stdio.h>
#include <stdbool.h>
// define se a posição foi ocupada
// true no = 1;

//matriz principal
int regioes[3][3];
//dado
int dadoMatriz;
// criacao do elemento da matriz
int *no;
int *n;
int *ne;
int *o;
int *c;
int *e;
int *so;
int *s;
int *se;


//atribuicao de valores para os elementos da matriz
int main(void){

  no = &regioes[0][0];
  n = &regioes[0][1];
  ne = &regioes[0][2];
  o = &regioes[1][0];
  c = &regioes[1][1];
  e = &regioes[1][2];
  so = &regioes[2][0];
  s = &regioes[2][1];
  se = &regioes[2][2];

  //necessário para o rand não assumir o mesmo valor sempre
  srand((int) time(0));
  //gera um valor aleatório, divede por 6 e soma 1 para ignorar o zero
  dadoMatriz = rand() % 8 + 1 ;
  // testar dado
  printf ("%d", dadoMatriz);
  switch(dadoMatriz){
    case 1:
      regioes[0][0] = 1;
      break;
    case 2:
      regioes[0][1] = 1;
      break;
    case 3:
      regioes[0][2] = 1;
      break;
    case 4:
      regioes[1][0] = 1;
      break;
    case 5:
      regioes[1][1] = 1;
      break;
    case 6:
      regioes[1][2] = 1;
      break;
    case 7:
      regioes[2][0] = 1;
      break;
    case 8:
      regioes[2][1] = 1;
      break;
    case 9:
      regioes[2][2] = 1;
      break;
  }

 printf ("%d", regioes[0][0]);
 return 0;}

int rodarDado() {
  srand((int) time(0));
  return rand() % 8 + 1;
}
