#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "no.h"


p_pilha criar_pilha(int max){
// cria e retorna o ponteiro pilha para a struct pilha

    p_pilha pilha = malloc(sizeof(struct pilha));
    pilha->topo = NULL;
    pilha->max = max; 
    pilha->total = 0;

    return pilha;
}

void destruir_pilha(p_pilha pilha){
// libera a memória utilizada pela pilha

    p_no atual = pilha->topo;
    p_no temp;
    while (atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(pilha);
}

void empilhar(p_pilha pilha, int tempo){
// coloca um elemento no topo da pilha 

    p_no novo = malloc(sizeof(struct no));
    
    novo->tempo_emb = tempo; 
    novo->prox = pilha->topo;
    pilha->topo = novo;
    pilha->total++;
}

int desempilha(p_pilha pilha){
// remove um elemento do topo da pilha

    p_no topo = pilha->topo;
    pilha->topo = topo->prox;
    int x = topo->tempo_emb;  
    free(topo);
    pilha->total--;
    return x;
}