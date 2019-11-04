#include "Dado.h"
#include "Regioes.h"

//obtem um numero inteiro que simboliza um regiao
int obterRegiao() {
    return rodarDado(9);
}

//apartir do numero da regiao ele retorna o nome da regiao.
char *obterNomeRegiao(int regiao){
    switch(regiao) {
        case no:
            return "no";
            break;
        case n:
            return "n";
            break;
        case ne:
            return "ne";
            break;
        case o:
            return "o";
            break;
        case c:
            return "c";
            break;
        case e:
            return "e";
            break;
        case so:
            return "so";
            break;
        case s:
            return "s";
            break;
        case se:
            return "se";
            break;
        default:
            return "";
    }
}
