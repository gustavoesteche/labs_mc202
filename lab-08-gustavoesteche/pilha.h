#ifndef PILHA_H
#define PILHA_H 
#include "no.h"

typedef struct pilha *p_pilha;

struct pilha{
    p_no *itens;
    int topo;
};

p_pilha criar_pilha(int tamanho);

void empilhar(p_pilha pilha, p_no no);

p_no desempilhar(p_pilha pilha);


#endif 