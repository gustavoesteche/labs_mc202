#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include "no.h"

p_pilha criar_pilha(int tamanho){
    p_pilha pilha = malloc(sizeof(struct pilha));
    pilha->itens = malloc(tamanho * sizeof(struct no));
    pilha->topo = 0;

    return pilha;
}

void empilhar(p_pilha pilha, p_no no){
    pilha->itens[(pilha->topo)++] = no;
}

p_no desempilhar(p_pilha pilha){
    if(pilha->topo > 0){
        pilha->topo--;
        return pilha->itens[pilha->topo];
    }
    return NULL;
}
