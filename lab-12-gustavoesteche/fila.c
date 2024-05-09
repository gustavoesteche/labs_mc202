#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "no.h"

p_fila criar_fila(){
// cria e retorna um ponteiro para uma struct fila    

    p_fila fila = malloc(sizeof(struct fila));
    fila->ini = NULL;
    fila->fim = NULL;
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

void inserir_fila(p_fila fila,int valor){
// insere no final da fila

    p_no novo = malloc(sizeof(struct no));
    novo->valor = valor;

    novo->prox = NULL;
    if(fila->fim == NULL)
        fila->ini = novo;
    else
        fila->fim->prox = novo;

    fila->fim = novo; 
    fila->total++;
}

int remove_fila(p_fila fila){
// remove no início da fila

    p_no primeiro = fila->ini;
    fila->ini = primeiro->prox;
    int x = primeiro->valor;

    if(fila->ini == NULL)
        fila->fim = NULL;

    free(primeiro);
    fila->total--;
    return x;
}