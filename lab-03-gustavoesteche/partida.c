#include <stdio.h>
#include <stdlib.h>
#include "partida.h"

partida *criar_partida(){
// Aloca a memória da struct partida

    partida *p = malloc(sizeof(partida));
    if(p == NULL){
        exit(EXIT_FAILURE);
    }
    
    return p;
}

void ler_info_partida(partida *p, int ID){
// Scaneia as informações do usuário para partida 

    scanf("%d %d %d", &p->n_jogadores,&p->n_circuitos,&p->n_equipamentos);
    p->ID =ID;
    alloc_vetor_circuitos(p, p->n_circuitos);
    calculo_aluguel(p);
}

void imprimir_info_partida(partida *p){
// Imprime as informações da partida

    int circuito_dif = circuito_dificil(p);
    int *arr_jogadas = qntd_jogadas(p);

    printf("Partida %d\n", p->ID);
    printf("Num. de Jogadores: %d - Num. de Circuitos: %d - Num. de Equipamentos: %d\n",p->n_jogadores,p->n_circuitos,p->n_equipamentos);
    printf("Valor do Aluguel: R$ %.2f\n", p->valor_aluguel);
    for(int i=0;i<p->n_jogadores;i++){
        printf("Jogador %d: %d\n",i+1, arr_jogadas[i]);
    }
    printf("Circuito mais dificil: %d\n", circuito_dif);
    printf("##########\n");
    free(arr_jogadas);
}

void calculo_aluguel(partida *p){
// Calcular o valor do aluguel padronizado
    
    p->valor_aluguel = 10 * p->n_circuitos + 17.50 * p->n_equipamentos;
}



void alloc_vetor_circuitos(partida *p, int n_jogadores){
// Aloca a memória do vetor circuitos que armazena as informações dos circuitos

    p->circuitos = malloc(n_jogadores * sizeof(circuito));
    if(p->circuitos == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<n_jogadores;i++){
        p->circuitos[i].jogadas = malloc(p->n_jogadores * sizeof(int));
    }

    
}

void armazenar_circuito(partida *p,int i_circuito , circuito *c){
// Transfere os dados de um circuito c para uma posição 
// i_circuito do vetor circuitos

    (p->circuitos[i_circuito]).ID = c->ID;
    (p->circuitos[i_circuito]).n_participantes = c->n_participantes;
    for(int i=0;i<c->n_participantes;i++){
        (p->circuitos[i_circuito]).jogadas[i] = c->jogadas[i];
    }
}


int circuito_dificil(partida *p){
// Função que encontra e retorna o ID do circuito mais difícil

    int max = 0, temp = 0, circuito_dif;
    for(int i=0;i<p->n_circuitos;i++){
        for(int j=0;j<p->n_jogadores;j++){
            temp += p->circuitos[i].jogadas[j];
            if(temp > max){
                max = temp;
                circuito_dif = i;
            }
        }
        temp = 0;
    }

    return p->circuitos[circuito_dif].ID;
}

int *qntd_jogadas(partida *p){
// Monta o vetor que armazena os inteiros da quantidade de jogadas por jogador
    
    int *arr = calloc(p->n_jogadores, sizeof(int));
    if(arr == NULL){
        exit(EXIT_FAILURE);
    }

    for(int i=0;i<p->n_jogadores;i++){
        for(int j=0;j<p->n_circuitos;j++){
            arr[i] += p->circuitos[j].jogadas[i];
        }
    }

    return arr;
}



void liberar_mem_partida(partida *p){
// Libera a memória da partida

    for(int i=0;i<p->n_circuitos;i++){
        free(p->circuitos[i].jogadas);
    }
    free(p->circuitos);
    free(p);
}
