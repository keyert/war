#include "Mundo.h"
#include "Regioes.h"

const Regiao REGIAO_VAZIA = {0,0};

//criacao do mundo
Regiao mundo[3][3] = {
    {
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0}
    },
    {
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0}
    },
    {
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0},
        {.player = 0, .soldados = 0}
    }
};

//de acordo com a regiao atualizar o player e quantos soldados tem na regiao
void atualizarMundo(int regiao, int player, int soldados) {
    switch(regiao) {
        case no:
            mundo[0][0].player = player;
            mundo[0][0].soldados = soldados;
            break;
        case n:
            mundo[0][1].player = player;
            mundo[0][1].soldados = soldados;
            break;
        case ne:
            mundo[1][0].player = player;
            mundo[1][0].soldados = soldados;
            break;
        case o:
            mundo[1][1].player = player;
            mundo[1][1].soldados = soldados;
            break;
        case c:
            mundo[0][2].player = player;
            mundo[0][2].soldados = soldados;
            break;
        case e:
            mundo[2][0].player = player;
            mundo[2][0].soldados = soldados;
            break;
        case so:
            mundo[2][2].player = player;
            mundo[2][2].soldados = soldados;
            break;
        case s:
            mundo[1][2].player = player;
            mundo[1][2].soldados = soldados;
            break;
        case se:
            mundo[2][1].player = player;
            mundo[2][1].soldados = soldados;
            break;
    }
}

// obtem uma regiao especifica
Regiao obterRegiao(int regiao) {
    switch(regiao) {
        case no:
            return mundo[0][0];
            break;
        case n:
            return mundo[0][1];
            break;
        case ne:
            return mundo[1][0];
            break;
        case o:
            return mundo[1][1];
            break;
        case c:
            return mundo[0][2];
            break;
        case e:
            return mundo[2][0];
            break;
        case so:
            return mundo[2][2];
            break;
        case s:
            return mundo[1][2];
            break;
        case se:
            return mundo[2][1];
            break;
        default:
            return REGIAO_VAZIA;
    }
}
