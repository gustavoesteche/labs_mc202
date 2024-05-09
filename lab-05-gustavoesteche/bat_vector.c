#include <stdio.h>
#include <stdlib.h>
#include "bat_vector.h"
#include "bat_info.h"


p_bat bat_create(){

    p_bat bat_vector= malloc(sizeof(struct vector));
    
    bat_vector->data = malloc(8 * sizeof(int));
    
    bat_vector->total_size = 8;
    bat_vector->info = info_create();

    return bat_vector;
}

void bat_vector_increase(p_bat bat_vector){
    
    int *new_data = malloc(2 * bat_vector->total_size * sizeof(int));

    for(int i = 0;i < bat_vector->total_size ;i++){
        new_data[i] = bat_vector->data[i];
    }

    free(bat_vector->data);

    bat_vector->data = new_data;
    bat_vector->total_size *= 2;

}

void bat_alloc(p_bat bat_vector,  int N, int *array){
    
    int size = N + 1;
    int index = find_empty(bat_vector->info, size);

    if(index + N > bat_vector->total_size){
        bat_vector_increase(bat_vector);
    }

    int j = 0;
    bat_vector->data[index] = N;
    
    for(int i = index ;i < index + N;i++){
        bat_vector->data[i+1] = array[j];
        j++;
    }

    info_add(bat_vector->info, index, size);
    printf("%d\n", index);

}

void bat_free(p_bat bat_vector, int index){

    info_remove(bat_vector->info, index, bat_vector->data[index]+1);

    if(bat_vector->info->n <= bat_vector->total_size /4)
        bat_vector_decrease(bat_vector);
}

void bat_vector_decrease(p_bat bat_vector){

    if(bat_vector->total_size > 8){
        int reduce = 1;
        for(int i = bat_vector->total_size / 4;i < bat_vector->total_size;i++){
            if(bat_vector->info->data[i] == 1){
                reduce = 0;
                break;
            }
        }
        if(reduce){
            bat_vector_half(bat_vector);
            info_half(bat_vector->info);
        }
    }
}

void bat_vector_half(p_bat bat_vector){

    int *new_data = malloc(bat_vector->total_size / 2 * sizeof(int));

    for(int i=0;i<bat_vector->total_size / 4;i++){
        new_data[i] = bat_vector->data[i];
    }

    free(bat_vector->data);

    bat_vector->data = new_data;
    bat_vector->total_size /= 2;
}


void bat_free_total(p_bat bat_vector){

    info_free(bat_vector->info);
    free(bat_vector->data);
    free(bat_vector);
}

void bat_print(p_bat bat_vector, int index){

    for(int i = 1; i <= bat_vector->data[index]; i++){
        printf("%d ", bat_vector->data[index + i]);
    }
    printf("\n");
}

void bat_uso(p_bat bat_vector){

    printf("%d de %d\n", bat_vector->info->n, bat_vector->total_size);
}