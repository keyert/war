#include <stdio.h>

#include "DescricaoObjetivos.h"
#include "Jogador.h"
#include "Mundo.h"

int rodada = 0;

int main() {
    obterObjetivos();
    
    darTerritoriosIniciais();
    
    // loop de execução do jogo
    // utilizado do while pois sempre haverá no minimo uma rodada
    do {
        rodada++;
        jogar();

        // dá soldados aos jogadores apenas a cada duas jogadas
        if(rodada % 2 == 0) {
            darSoldados();
        }
    } while(vencedor == 0);

    printf("\nPlayer %d venceu!!!\n", jogadorAtual);
    
    return 0;
}
