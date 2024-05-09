#pragma once

#define MAX 2503
typedef struct no *p_no;

struct no{
    char chave[15];
    int dado;
};

typedef struct hash *p_hash;

struct hash{
    p_no vetor[MAX];
};

p_hash criar_hash();

void destruir_hash(p_hash hash_t);

int hash_1(char* chave);

int hash_2(char *chave);

void inserir(p_hash hash_t, char *chave, int dado);

int remover(p_hash hash_t, char *chave);

p_no buscar(p_hash hash_t, char *chave);

int remover_doces(p_hash hash_t, char *chave, char *nota);