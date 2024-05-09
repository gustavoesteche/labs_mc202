#ifndef FILA_H
#define FILA_H

#include "no.h"

typedef struct fila *p_fila;

struct fila{
    int max, total;
    p_no ini, fim;
};

p_fila criar_fila(int max);
// criar e retorna a fila com o tamanho maximo definido

void destruir_fila(p_fila fila);
// libera a memória alocada pela fila

void inserir_fila(p_fila fila, int *tempo);
// insere no final da fila o elemento passado pelo ponteiro tempo 

int remove_fila(p_fila fila, int *t_emb);
/*remove o início da fila e retorna o tempo da classificação 
e passa por referência o tempo de embalagem*/ 

#endif