#ifndef CIRCUITO_H
#define CIRCUITO_H

typedef struct circ{
    int ID, n_participantes;
    int *jogadas;
} circuito ;

circuito *criar_circuito();

void ler_info_circuito(circuito *c, int n_participantes);

int *alloc_circuito(circuito *c);

void liberar_mem_circuito(circuito *c);

#endif