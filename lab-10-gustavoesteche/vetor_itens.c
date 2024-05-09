#include <stdio.h>
#include <stdlib.h>
#include "vetor_itens.h"

p_vitens criar_vitens(int tam){
    p_vitens vitens = malloc(sizeof(struct vetor_itens));
    vitens->data = malloc(tam * sizeof(Item));
    vitens->n = 0;
    vitens->tamanho = tam;

    return vitens;
}

void adiciona_item(p_vitens vitens, Item item){
    vitens->data[vitens->n] = item;
    vitens->n++;
}

void destruir_vitens(p_vitens vitens){
    free(vitens->data);
    free(vitens);
}