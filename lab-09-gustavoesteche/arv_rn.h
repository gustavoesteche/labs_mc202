#ifndef ARVRN_H
#define ARVRN_H

enum cor {VERMELHO, PRETO};

typedef struct no *p_no;

struct no{
    char *chave; // nocaso acredito que a chave sera um vetor de char, entao temos que redefinir > e <
    char *tipo;
    enum cor cor;
    p_no esq, dir;
};

int ehVermelho(p_no x);

int ehPreto(p_no x);

p_no rotaciona_esquerda(p_no raiz);

p_no rotaciona_direita(p_no raiz);

void sobe_vermelho(p_no raiz);

p_no inserir_rec(p_no raiz , char *chave, char *tipo);

p_no inserir(p_no raiz, char *chave, char *tipo);

void printar_arvore(p_no raiz);

p_no buscar_chave(p_no raiz, char *chave);

void destruir_arvore(p_no raiz);
#endif