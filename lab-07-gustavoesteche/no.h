#ifndef NO_H
#define NO_H

typedef struct no *p_no;

struct no{
    int tempo_emb, tempo_cla; // Dados contidos em cada no
    p_no prox;
};
#endif