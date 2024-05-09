#ifndef VETOR_ITENS_H
#define VETOR_ITENS_H

#include "fila_prioridade.h"

typedef struct vetor_itens *p_vitens;

struct vetor_itens{ 
    Item *data;
    int n, tamanho;
};

// criar o vetor que armazena os itens
p_vitens criar_vitens(int tam);

// adiciona o Item no vetor vitens na ultima posicao 
void adiciona_item(p_vitens vitens, Item item);

// libera a memoria armazenada pelo vetor de itens
void destruir_vitens(p_vitens vitens);


#endif