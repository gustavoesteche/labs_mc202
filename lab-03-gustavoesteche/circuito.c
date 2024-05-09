#include <stdio.h>
#include <stdlib.h>
#include "circuito.h"
#include "partida.h"

circuito *criar_circuito(){
// Aloca a memória da struct circuito

    circuito *c = malloc(sizeof(circuito));
    if(c == NULL){
        exit(EXIT_FAILURE);
    }
    
    
    return c;
}


void ler_info_circuito(circuito *c, int n_participantes){
// Scaneia as informações do usuário para a struct circuito

    c->n_participantes = n_participantes;
    c->jogadas = alloc_circuito(c);
    scanf("%d", &c->ID);
    for(int i=0;i<c->n_participantes;i++){
        scanf("%d", &c->jogadas[i]);
    }
}

int *alloc_circuito(circuito *c){
// Aloca a memória para ser usada no armazenamento do número
// de jogadas por jogador

    int *newpointer = malloc(c->n_participantes * sizeof(int));
    if(newpointer == NULL){
         exit(EXIT_FAILURE);
    }
    return newpointer;
}

void liberar_mem_circuito(circuito *c){
// libera a memória da struct circuito

    free(c->jogadas);
    free(c);
}