#include "bat_info.h"

#ifndef BAT_VECTOR_H
#define BAT_VECTOR_H


typedef struct vector *p_bat;

struct vector{
    int *data;
    int total_size;
    info_bat info; //struct que guarda informações do bat_vector
};

p_bat bat_create();
// Cria e aloca o ponteiro a struct bat_vector

void bat_vector_increase(p_bat bat_vector);
// Dobra a memória do bat_vector quando necessário

void bat_alloc(p_bat bat_vector, int N, int *array);
// Aloca um vetor de inteiros na memória bat_vector

void bat_free(p_bat bat_vector, int index);
// Libera um vetor de inteiros que está alocado na memória bat_vector

void bat_vector_decrease(p_bat bat_vector);
// Checa se a memória alocada no vetor bat_vector pode ser cortada pela metade

void bat_vector_half(p_bat bat_vector);
// Corta a memória alocata no vetor bat_vector pela metade

void bat_free_total(p_bat bat_vector);
// libera a memória alocada no vetor bat_vector

void bat_print(p_bat bat_vector, int index);
// printa o vetor de inteiros contido no index especificado na memória

void bat_uso(p_bat bat_vector);
// printa o uso de memória do vetor bat_vector relativo a sua capacidade

#endif
