#ifndef Dado_h
#define Dado_h

#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int rodarDado(int valorMaximo);

// melhorar a aleatoriedade dos numeros (código da internet)
unsigned long mix(unsigned long a, unsigned long b, unsigned long c) {
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}

// retorna um numero aleatório com valor máximo parametrizado
int rodarDado(int valorMaximo) {
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    return rand() % valorMaximo + 1;
}
#endif /* Dado_h */
