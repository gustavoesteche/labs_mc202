#include "circuito.h"

#ifndef PARTIDA_H
#define PARTIDA_H

typedef struct ola{
    float valor_aluguel;
    int ID; 
    int n_jogadores, n_circuitos,n_equipamentos;
    circuito *circuitos;
}partida;

partida *criar_partida();

void ler_info_partida(partida *p, int ID);

void imprimir_info_partida(partida *p);

void calculo_aluguel(partida *p);

void alloc_vetor_circuitos(partida *p, int n);

void armazenar_circuito(partida *p,int i_circuito , circuito *c);

int circuito_dificil(partida *p);

int *qntd_jogadas(partida *p);

void liberar_mem_partida(partida *p);

#endif