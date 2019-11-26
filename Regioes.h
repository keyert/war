#ifndef Regioes_h  //para nao usar duas vezes o arquivo
#define Regioes_h  // ''

#include <stdio.h>

#include "Dado.h"

//criando uma estrutura de dados para representar uma regiao no mundo
typedef struct {
    int player;
    int soldados;
} Regiao;

const int QUANTIDADE_REGIOES = 9;

//definicao da identificacao do territorio
const int NOROESTE = 1;
const int NORTE = 2;
const int NORDESTE = 3;
const int OESTE = 4;
const int CENTRO = 5;
const int LESTE = 6;
const int SUDOESTE = 7;
const int SUL = 8;
const int SUDESTE = 9;

//obtem um numero inteiro que simboliza uma regiao
int obterRegiao() {
    return rodarDado(9);
}

//apartir do numero da regiao ele retorna o nome da regiao.
char *obterNomeRegiao(int regiao){
    switch(regiao) {
        case NOROESTE:
            return "Noroeste";
            break;
        case NORTE:
            return "Norte";
            break;
        case NORDESTE:
            return "Nordeste";
            break;
        case OESTE:
            return "Oeste";
            break;
        case CENTRO:
            return "Centro";
            break;
        case LESTE:
            return "Leste";
            break;
        case SUDOESTE:
            return "Sudoeste";
            break;
        case SUL:
            return "Sul";
            break;
        case SUDESTE:
            return "Sudeste";
            break;
        default:
            return "";
    }
}
#endif /* Regioes_h */
