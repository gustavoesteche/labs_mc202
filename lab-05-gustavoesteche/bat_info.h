
#ifndef BAT_INFO_H
#define BAT_INFO_H


typedef struct info_mem *info_bat;

struct info_mem{
    int *data;
    int total_size; //guardado duas vezes por redundância
    int n; // quantidade de elementos
};


info_bat info_create();
// cria e aloca o ponteiro para a struct info_bat, que guarda informação
// se um índice de bat_vector está ocupado, com 0,não ocupado, ou 1, ocupado.

void info_mem_increase(info_bat info);
// aumenta a quantidade de memória alocada para info_bat

void info_add(info_bat info, int index, int size);
// adiciona 1 nos índices ocupados pelo novo vetor adicionado na memória

void info_remove(info_bat info, int index, int size);
// adiciona 0 nos índices ocupados pelo vetor que foi removido da memória

void info_free(info_bat info);
// libera a memória ocupada pelo info_bat

int find_empty(info_bat info, int size);
// encontra e retorna um índice para que um vetor de tamanho size ocupe
// na memória

void info_half(info_bat info);
// diminui pela metada o tamanho da memória ocupada quando necessário

#endif