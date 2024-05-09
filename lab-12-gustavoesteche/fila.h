#ifndef FILA_H
#define FILA_H
#include "no.h"

typedef struct fila *p_fila;

struct fila{
    int total;
    p_no ini, fim;
};

p_fila criar_fila();
// criar e retorna a fila 

void destruir_fila(p_fila fila);
// libera a memória alocada pela fila

void inserir_fila(p_fila fila, int valor);
// insere no final da fila o elemento passado pelo inteiro valor

int remove_fila(p_fila fila);
/*remove o primeiro item da fila*/ 

#endif