#ifndef Mundo_h
#define Mundo_h

#include <stdio.h>
#include "Regioes.h"

// posições pro array da jogada
const int POSICAO_PLAYER = 0;
const int POSICAO_LIVRE_INIMIGO = 1;
const int QUANTIDADE_INICIAL_TROPAS = 2;

// código de cores para alterar o terminal
const char *COR_DEFAULT = "\033[0m";
const char *COR_AZUL = "\033[0;34m";
const char *COR_VERMELHA = "\033[0;31m";

// identificação das regicoes
const Regiao REGIAO_VAZIA = {0,0};
const int REGIAO_SEM_DONO = 0;

// declaração das funções
Regiao *obterRegiaoMundo(int regiao);
void mostrarMundo(int jogadorAtual);
void atualizarMundo(int regiao, int player, int soldados);
void imprimirRosaDosVentos(int linha);
void obterRegiaoJogador(int player, int regioes[2][9]);

//criacao do mundo
Regiao mundo[3][3] = {
    {
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0}
    },
    {
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0}
    },
    {
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0},
        {.player = REGIAO_SEM_DONO, .soldados = 0}
    }
};

// inicia os valores do mundo
void reinicializarMundo() {
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            mundo[i][j].player = REGIAO_SEM_DONO;
            mundo[i][j].soldados = 0;
        }
    }
}

// dar soldados aos jogadores
void darSoldados() {
    printf("\n*****************************************************\n");
    printf("\nAdicionando um soldado em cada território conquistado\n");
    printf("\n*****************************************************\n");
    
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            if (mundo[i][j].player != REGIAO_SEM_DONO) {
                mundo[i][j].soldados++;
            }
        }
    }
}

//Motra a matriz para o player atual
void mostrarMundo(int jogadorAtual) {
    printf("\nEstado do mundo:");
    printf("\t\tRegiões:");
    printf("\n\n");
    
    for (int i = 0 ; i < 3 ; i++) {
        for (int j = 0 ; j < 3 ; j++) {
            // colorindo o console
            if(mundo[i][j].player == jogadorAtual) { // se o território pertencer ao jogador atual fica azul
                printf("%s", COR_AZUL);
            } else if(mundo[i][j].player != REGIAO_SEM_DONO){ // senão se o território tiver dono fica vermelho
                printf("%s", COR_VERMELHA);
            }

            // imprime a quantidade de soldados na regiao
            printf("%d", mundo[i][j].soldados);
            
            // voltando o console para cor normal
            printf("%s", COR_DEFAULT);

            // imprime a barrinha se nao a ultima coluna (separa as colunas do mundo)
            if(j < 2) {
                printf(" | ");
            }
        }
        
        imprimirRosaDosVentos(i);
        
        // imprime a linha separando o mundo
        if(i < 2) {
            printf("\n----------\n");
        } else {
            printf("\n");
        }
    }
    
    // imprime a lengenda do mundo
    printf("\nLegenda:\n");
    printf("%sAzul:%s Você\n", COR_AZUL, COR_DEFAULT);
    printf("%sVermelho:%s Inimigo\n", COR_VERMELHA, COR_DEFAULT);
    printf("Sem cor: Território sem dono\n\n");
}

//Imprime a linha equivalente da rosa dos ventos
void imprimirRosaDosVentos(int linha) {
    switch(linha) {
        case 0:
            printf("\t\t\tNO | N | NE");
            break;
        case 1:
            printf("\t\t\t O | C | E");
            break;
        case 2:
            printf("\t\t\tSO | S | SE");
            break;
    }
}

//de acordo com a regiao atualizar o player e quantos soldados tem na regiao
void atualizarMundo(int regiao, int player, int soldados) {
    Regiao *regiaoMundo = obterRegiaoMundo(regiao);
    regiaoMundo->player = player;
    regiaoMundo->soldados = soldados;
}

//lista as regioes do jogador e as regieos que não são do jogador, receme uma matriz como parametro, onde vai ser salvo o resultado
void obterRegiaoJogador(int player, int regioes[2][9]) {
    int quantidadePlayer = 0;
    int quantidadeNaoPlayer = 0;
    int idTerritorioAtual = 1;
        
    for(int i = 0 ; i < 3 ; i++) {
        for(int j = 0 ; j < 3 ; j++) {
            if(mundo[i][j].player == player) {
                regioes[POSICAO_PLAYER][quantidadePlayer] = idTerritorioAtual;
                quantidadePlayer++;
            } else {
                regioes[POSICAO_LIVRE_INIMIGO][quantidadeNaoPlayer] = idTerritorioAtual;
                quantidadeNaoPlayer++;
            }
            
            idTerritorioAtual++;
        }
    }
}


// obtem uma regiao especifica (retorna regiao) quem é o player e a quantidade de soldados
Regiao *obterRegiaoMundo(int regiao) {
    switch(regiao) {
        case NOROESTE:
            return &mundo[0][0];
            break;
        case NORTE:
            return &mundo[0][1];
            break;
        case NORDESTE:
            return &mundo[0][2];
            break;
        case OESTE:
            return &mundo[1][0];
            break;
        case CENTRO:
            return &mundo[1][1];
            break;
        case LESTE:
            return &mundo[1][2];
            break;
        case SUDOESTE:
            return &mundo[2][0];
            break;
        case SUL:
            return &mundo[2][1];
            break;
        case SUDESTE:
            return &mundo[2][2];
            break;
        default:
            return NULL;
    }
}
#endif /* Mundo_h */

