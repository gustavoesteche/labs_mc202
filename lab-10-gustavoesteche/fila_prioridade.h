#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H


typedef struct ola{
    char nome[30];
    char prato[30];
    int chave, id;
}Item;

typedef struct FP *p_fp;

struct FP{
    Item *v;
    int *id; // vetor relaciona ID - posicao no heap 
    int n, tamanho;
};

// cria e retorna a fila de prioridade.
p_fp criar_filaprio(int tam);


// insere na fila de prioridade.
void insere(p_fp fprio, Item item);

// extrai o item de prioridade maxima da fila de prioridade e retorna-o.
Item extrai_maximo(p_fp fprio);

// muda a prioridade de um item especifico a partir de seu id somando-se um valor dado.
void muda_prioridade(p_fp fprio, int ID, int valor);

// libera a memoria alocada para a fila de prioridade.
void destruir_filaprio(p_fp fprio);

#endif