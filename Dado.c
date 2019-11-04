#include<time.h>
#include <stdio.h>

#include "Dado.h"

// retorna um numero aleatório com valor máximo parametrizado
int rodarDado(int valorMaximo) {
    srand((int) time(0));
    return rand() % valorMaximo + 1;
}
