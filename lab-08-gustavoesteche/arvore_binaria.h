#ifndef ARVOREBIN_H
#define ARVOREBIN_H

#include "no.h"

typedef struct arvore *p_arvore; 

struct arvore{
    p_no raiz;
};

void print_arvore(p_no raiz);

int operator(char c);

int numero(p_no no);

p_no construir_arvore(char *expressao);

void destruir_arvore(p_no raiz);

void inordem(p_no raiz);

void simplifica_true(p_no raiz);

void simplifica_false(p_no raiz);

p_no simplificar_arvore(p_no raiz);

p_no construir_arvore_simplificada(char *expressao);

p_no criar_no(char dado);

#endif