#include "DescricaoObjetivos.h"
#include "Dado.h"
#include "Regioes.h"

//string com as mensagens para o objetivo do player
char *INICIO_OBJETIVO = "Conquiste os territórios";
char *CONQUISTAR_TUDO = "Conquiste o mundo";
char *ELIMINAR_INIMIGO = "Conquiste o mundo";

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

void obterObjetivos() {
    // obter objetivo pro player 1

    int valorDado = rodarDado(5);
    printf("player1: ");
    switch(valorDado) {
        case CONQUISTAR_TUDO_ID:
            p1ConquistarTudo = 1;
            printf(CONQUISTAR_TUDO);
            break;
        case ELIMINAR_INIMIGO_ID:
            p1EliminarInimigo = 2;
            printf(ELIMINAR_INIMIGO);
            break;
        default:
            preencherTerritoriosObjetivo(objetivosP1);
    };
    
    // obter objetivo pro player 2
    
    valorDado = rodarDado(5);
    
    switch(valorDado) {
        case CONQUISTAR_TUDO_ID:
            p2ConquistarTudo = 1;
            break;
        case ELIMINAR_INIMIGO_ID:
            p2EliminarInimigo = 2;
            break;
        default:
            preencherTerritoriosObjetivo(objetivosP2);
    };
}

int validarObjetivo() {
    return 0;
}

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
//fazer um algoritmo que percorra uma lista e veja se já tem tal valor nela
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
char *obterNomesRegiao(int objetivo[3]){
    //percoorrer e dar o nome
}
