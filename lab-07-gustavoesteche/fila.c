#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "no.h"

p_fila criar_fila(int max){
// cria e retorna um ponteiro para uma struct fila    

    p_fila fila = malloc(sizeof(struct fila));
    fila->ini = NULL;
    fila->fim = NULL;
    fila->max = max;
    fila->total =0;

    return fila;
}

void destruir_fila(p_fila fila){
// libera a memória contida na fila
    
    p_no atual = fila->ini;
    p_no temp;
    while(atual != NULL){
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(fila);
}

void inserir_fila(p_fila fila, int *tempo){
// insere no final da fila

    p_no novo = malloc(sizeof(struct no));
    novo->tempo_cla = tempo[0];
    novo->tempo_emb = tempo[1];

    novo->prox = NULL;
    if(fila->fim == NULL)
        fila->ini = novo;
    else
        fila->fim->prox = novo;

    fila->fim = novo; 
    fila->total++;
}

int remove_fila(p_fila fila, int *t_emb){
// remove no início da fila

    p_no primeiro = fila->ini;
    fila->ini = primeiro->prox;
    int x = primeiro->tempo_cla;

    if(fila->ini == NULL)
        fila->fim = NULL;

    *t_emb = primeiro->tempo_emb;
    free(primeiro);
    fila->total--;
    return x;
}