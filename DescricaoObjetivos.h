#ifndef DescricaoObjetivos_h
#define DescricaoObjetivos_h
#include <stdio.h>

#include "DescricaoObjetivos.h"
#include "Dado.h"
#include "Regioes.h"
#include "Jogador.h"
#include "Mundo.h"

//declaracao das funcoes
int validarObjetivo(void);
void preencherTerritoriosObjetivo(int objetivo[3]);
void obterObjetivos(void);
char *obterDescObjetivo(int objetivo[3]);
int verificarTerritorio(int objetivo[3], int regiao);
int validarMundoTodo(int player);
int validarInimigoExterminado(int inimigo);
int validarTerritorios(int player, int objetivo[3]);

//string com as mensagens para o objetivo do player
char *INICIO_OBJETIVO = "Conquiste os territórios\n";
char *CONQUISTAR_TUDO = "Conquiste o mundo\n";
char *ELIMINAR_INIMIGO = "Eliminar seu inimigo\n";

//criacao dos objetivos
const int CONQUISTAR_TUDO_ID = 1;
const int ELIMINAR_INIMIGO_ID = 2;

//objetivios do player 1
int objetivosP1[3] = {0,0,0}; //array ja instanciado sem objetivos do player 1
int p1ConquistarTudo = 0; // caso seja um o objetivo dele é conquistar tudo
int p1EliminarInimigo = 0; //caso seja um o objetivo é eliminar o inimigo

//objetivos do player 2
int objetivosP2[3] = {0,0,0}; // mesmo do de cima p2
int p2ConquistarTudo = 0; // mesmo do de cima p2
int p2EliminarInimigo = 0; // mesmo do de cima p2

//cria os objetivos para os jogadores
void obterObjetivos() {
    
    // obter objetivo pro player 1
    int valorDado = rodarDado(5);
    printf("player1:\n");
    switch(valorDado) {
        case CONQUISTAR_TUDO_ID:
            p1ConquistarTudo = 1;
            printf("%s", CONQUISTAR_TUDO);
            break;
        case ELIMINAR_INIMIGO_ID:
            p1EliminarInimigo = 1;
            printf("%s", ELIMINAR_INIMIGO);
            break;
        default:
            preencherTerritoriosObjetivo(objetivosP1);
            printf("%s\n", obterDescObjetivo(objetivosP1) ); //mostrar territorio para P1
    };
    
    // obter objetivo pro player 2
    valorDado = rodarDado(5);
    printf("\nplayer2:\n");
    
    switch(valorDado) {
        case CONQUISTAR_TUDO_ID:
            p2ConquistarTudo = 1;
            printf("%s", CONQUISTAR_TUDO);
            break;
        case ELIMINAR_INIMIGO_ID:
            p2EliminarInimigo = 1;
            printf("%s", ELIMINAR_INIMIGO);
            break;
        default:
            preencherTerritoriosObjetivo(objetivosP2);
            printf("%s\n", obterDescObjetivo(objetivosP2));//mostrar territorio para P2
    };
}

//verifica se o objetivo do player atual foi cumprido
int validarObjetivo() {
    if (jogadorAtual == PLAYER_1) {
        if(p1ConquistarTudo == 1) {
            return validarMundoTodo(PLAYER_1);
        } else if (p1EliminarInimigo) {
            return validarInimigoExterminado(PLAYER_2);
        } else {
            return validarTerritorios(PLAYER_1, objetivosP1);
        }
    } else {
        if(p2ConquistarTudo == 1) {
            return validarMundoTodo(PLAYER_2);
        } else if (p2EliminarInimigo) {
            return validarInimigoExterminado(PLAYER_1);
        } else {
            return validarTerritorios(PLAYER_2, objetivosP2);
        }
    }
}

// valida se o jogador recebido como parametro dominou o mundo todo
int validarMundoTodo(int player) {
    for (int i = 1 ; i <= QUANTIDADE_REGIOES ; i++) {
        if (obterRegiaoMundo(i) -> player != player) {
            return 0;
        }
    }
    
    return 1;
}

// vadia se o jogador passado como parametro foi exterminado
int validarInimigoExterminado(int inimigo) {
    for (int i = 1 ; i <= QUANTIDADE_REGIOES ; i++) {
        if (obterRegiaoMundo(i) -> player == inimigo) {
            return 0;
        }
    }
    
    return 1;
}

// valida se o jogador passado como parametro conquistou os territorios passados como parametro
int validarTerritorios(int player, int objetivo[3]) {
    for (int i = 0 ;  i < 3 ; i++) {
        if(obterRegiaoMundo(objetivo[i]) -> player != player) {
            return 0;
        }
    }
    
    return 1;
}

//preencher arrays dos territorios dos players
void preencherTerritoriosObjetivo(int objetivo[3]) {
    objetivo[0] = obterRegiao();
    objetivo[1] = obterRegiao();
    objetivo[2] = obterRegiao();
    
    int indice = 0;
    
    do {
        int regiao = obterRegiao();
        if (verificarTerritorio(objetivo, regiao) == 0){
            objetivo[indice] = regiao;
            indice++;
        }
        
    } while(indice != 3);
}

//retornar int 0 falso e um true
int verificarTerritorio(int objetivo[3], int regiao) {
    for(int i = 0 ; i < 3 ; i++) {
        if(objetivo[i] == regiao) {
            return 1;
        }
    }
    return 0;
}

// retorna uma string correspondendo aos nomes das regioes que o jogador tem que conquistar
char *obterDescObjetivo(int objetivo[3]) {
    char todasRegiao[100] = "";
    for(int i = 0 ; i < 3 ; i++) {
        char *nomeRegiao = obterNomeRegiao(objetivo[i]);
        strcat(todasRegiao, nomeRegiao);
        if(i < 2) {
            strcat(todasRegiao, ", ");
        }
        
    }
    
    return todasRegiao;
}

#endif /* DescricaoObjetivos_h */
