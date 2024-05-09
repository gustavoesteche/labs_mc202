#ifndef PILHA_H
#define PILHA_H

#include "no.h"


typedef struct pilha *p_pilha;

struct pilha{
    int max, total;
    p_no topo;
};

p_pilha criar_pilha(int max);

void destruir_pilha(p_pilha pilha);

void empilhar(p_pilha pilha, int tempo);

int desempilha(p_pilha pilha);
#endif