#ifndef PILHA_H
#define PILHA_H

#include "no.h"


typedef struct pilha *p_pilha;

struct pilha{
    int total;
    p_no topo;
};

p_pilha criar_pilha();

void destruir_pilha(p_pilha pilha);

void empilhar(p_pilha pilha, int valor);

int desempilha(p_pilha pilha);
#endif