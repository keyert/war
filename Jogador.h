#ifndef Jogador_h
#define Jogador_h

#include "Mundo.h"
#include "DescricaoObjetivos.h"

const int TAMANHO_JOGADA = 3;

const int TERRITORIO_ORIGEM = 0;
const int QUANTIDADE_TROPAS = 1;
const int TERRITORIO_DSTINO = 2;

//constantes para definir jogadores
const int PLAYER_1 = 1;
const int PLAYER_2 = 2;

//variavel para controlar o jogador atual
int jogadorAtual = PLAYER_1;

//controla se existe vencedor
int vencedor = 0;

// declaração das funções
void jogar(void);
void receberJogada(int jogada[TAMANHO_JOGADA]);
void darTerritoriosIniciais(void);
void processarJogada(int jogada[TAMANHO_JOGADA]);
int validarTrapaca(int jogada[TAMANHO_JOGADA]);
void trocarJogador(void);

//funcao para o player jogar
void jogar() {
    printf("\n*****************\n");
    printf("\n     Player %d\n", jogadorAtual);
    printf("\n*****************\n");

    mostrarMundo(jogadorAtual);     // imprime o mundo para o jogador tomar a decisao
    
    int jogada[TAMANHO_JOGADA];     // array para armazenar a jogada
    
    receberJogada(jogada);          // recebe a jogada
    
    if(validarTrapaca(jogada) == 1) { // se o jogador estiver trapaceando
        trocarJogador();    // troca o jogador
        vencedor = 1;       // informa que o jogador atual é o vencedor
        return;             // sai da função
    }
    
    processarJogada(jogada);    // se o jogador não tiver trapaceado, processa a jogada
    
    if (validarObjetivo() == 1) {   // valida se o objetivo do jogador atual foi cumprido
        vencedor = 1;               // se sim, informa que o jogador atual é o vencedor
    } else {
        trocarJogador();            // senão troca de jogador
    }
}

// troca o jogador atual se o outro jogador ainda existir
void trocarJogador() {
    if (validarInimigoExterminado(jogadorAtual == PLAYER_1 ? PLAYER_2 : PLAYER_1) == 0) {
        if (jogadorAtual == PLAYER_1) {
            jogadorAtual = PLAYER_2;
        } else {
            jogadorAtual = PLAYER_1;
        }
    }
}

// valida caso o jogador tenha entrado com dados inválidos para jogada
int validarTrapaca(int jogada[TAMANHO_JOGADA]) {
    Regiao *regiaoOrigem = obterRegiaoMundo(jogada[TERRITORIO_ORIGEM]);
    
    if(regiaoOrigem->player != jogadorAtual) {
        printf("\nTRAPACEOU, REGIÃO DE ORIGEM NÃO É SUA\n");
        return 1;
    }
    
    if(regiaoOrigem->soldados < 2) {
        printf("\nTRAPACEOU, REGIÃO DE ORIGEM NÃO TEM SOLDADOS SUFICIENTES\n");
        return 1;
    }
    
    if(regiaoOrigem->soldados - 1 < jogada[QUANTIDADE_TROPAS]) {
        printf("\nTRAPACEOU, QUANTIDADE DE SOLDADOS INVÁLIDA\n");
        return 1;
    }
    
    if(jogada[TERRITORIO_ORIGEM] == jogada[TERRITORIO_DSTINO]) {
        printf("\nTRAPACEOU, TERRTÓRIO ORIGEM IGUAL O DESTINO\n");
        return 1;
    }
    
    return 0;
}

// processa os dados informados pelo jogador e atualiza o mundo
void processarJogada(int jogada[TAMANHO_JOGADA]) {
    Regiao *regiaoOrigem = obterRegiaoMundo(jogada[TERRITORIO_ORIGEM]);
    Regiao *regiaoDestino = obterRegiaoMundo(jogada[TERRITORIO_DSTINO]);
    
    if (regiaoDestino -> player != 0 && regiaoDestino->player != jogadorAtual) {
        printf("\nRolando dados:\n");
        do {
            int valorDadoAtaque = rodarDado(6);
            int valorDadoDefesa = rodarDado(6);
            
            printf("\nVocê tirou: %d", valorDadoAtaque);
            printf("\nSeu inimigo tirou: %d", valorDadoDefesa);
            
            if(valorDadoAtaque > valorDadoDefesa) {
                regiaoDestino -> soldados--;
            } else if(valorDadoAtaque < valorDadoDefesa) {
                jogada[QUANTIDADE_TROPAS]--;
                regiaoOrigem -> soldados--;
            }
            
        } while(jogada[QUANTIDADE_TROPAS] > 0 && regiaoDestino->soldados > 0);
        
        if(regiaoDestino -> soldados == 0 && jogada[QUANTIDADE_TROPAS] > 0) {
            regiaoOrigem -> soldados -= jogada[QUANTIDADE_TROPAS];
            regiaoDestino -> player = jogadorAtual;
            regiaoDestino -> soldados = jogada[QUANTIDADE_TROPAS];
        }
    } else if (regiaoDestino -> player == jogadorAtual) {
        regiaoDestino -> soldados += jogada[QUANTIDADE_TROPAS];
    } else {
        regiaoOrigem -> soldados -= jogada[QUANTIDADE_TROPAS];
        regiaoDestino -> player = jogadorAtual;
        regiaoDestino -> soldados = jogada[QUANTIDADE_TROPAS];
    }
}

// recebe a jogada do jogador atual
void receberJogada(int jogada[TAMANHO_JOGADA]) {
    int regioesPlayer[2][9] = {{0,0,0,0,0,0,0,0,0}, {0,0,0,0,0,0,0,0,0}};
    obterRegiaoJogador(jogadorAtual, regioesPlayer);

    printf("\n\n-------------------------------------------\n\n");
    printf("Escolha a região de origem: \n");
    
    int i = 0;
    
    // loop nas regiões que o jogador atual possui
    while(i < 9 && regioesPlayer[POSICAO_PLAYER][i] != 0) {
        Regiao *regiao = obterRegiaoMundo(regioesPlayer[POSICAO_PLAYER][i]);
        
        // imprime se o jogador tiver mais que 1 soldado nessa região (regiao que pode ser retirado soldados)
        if(regiao->soldados > 1) {
            char *nomeRegiao = obterNomeRegiao(regioesPlayer[POSICAO_PLAYER][i]);
            printf("%s = %d\n", nomeRegiao, regioesPlayer[POSICAO_PLAYER][i]);
        }
        
        i++;
    }
    
    printf("\nObpção: ");
    
    scanf("%d", &jogada[TERRITORIO_ORIGEM]);
    
    Regiao *regiaoOrigem = obterRegiaoMundo(jogada[TERRITORIO_ORIGEM]);
    
    printf("\nQuantas tropas deseja utilizar? (deve ser menor que %d) \n", regiaoOrigem->soldados);
    
    printf("\nObpção: ");
    
    scanf("%d", &jogada[QUANTIDADE_TROPAS]);
    
    printf("\nEscolha a região para atacar: \n");
    
    i = 0;
    
    // imprime os terrirórios inimigos e livres
    while(i < 9 && regioesPlayer[POSICAO_LIVRE_INIMIGO][i] != 0) {
        char *nomeRegiao = obterNomeRegiao(regioesPlayer[POSICAO_LIVRE_INIMIGO][i]);
        printf("%s = %d\n", nomeRegiao, regioesPlayer[POSICAO_LIVRE_INIMIGO][i]);
        i++;
    }
    
    printf("\nOu para mover: \n");
    
    i = 0;

    // imprime os territórios que o jogador pode mover seus soldados
    while(i < 9 && regioesPlayer[POSICAO_PLAYER][i] != 0) {
        if (regioesPlayer[POSICAO_PLAYER][i] != jogada[TERRITORIO_ORIGEM]) {
            char *nomeRegiao = obterNomeRegiao(regioesPlayer[POSICAO_PLAYER][i]);
            printf("%s = %d\n", nomeRegiao, regioesPlayer[POSICAO_PLAYER][i]);
        }

        i++;
    }
    
    printf("\nObpção: ");
    
    scanf("%d", &jogada[TERRITORIO_DSTINO]);
    
    printf("\n");
}

// distribui os territórios para iniciar o jogo
void darTerritoriosIniciais() {
    int regiaoP1 = rodarDado(9);
    int regiaoP2 = rodarDado(9);
    
    while(regiaoP1 == regiaoP2) {
        regiaoP2 = rodarDado(9);
    }
    
    atualizarMundo(regiaoP1, PLAYER_1, QUANTIDADE_INICIAL_TROPAS);
    atualizarMundo(regiaoP2, PLAYER_2, QUANTIDADE_INICIAL_TROPAS);
}
#endif /* Jogador_h */
