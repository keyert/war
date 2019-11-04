#ifndef Regioes_h
#define Regioes_h

#include <stdio.h>

//definicao da identificacao do territorio
const int no = 1;
const int n = 2;
const int ne = 3;
const int o = 4;
const int c = 5;
const int e = 6;
const int so = 7;
const int s = 8;
const int se = 9;

//criando uma estrutura de dados para representar uma regiao no mundo
typedef struct {
    int player;
    int soldados;
} Regiao;

int obterRegiao(void);

#endif /* Regioes_h */
