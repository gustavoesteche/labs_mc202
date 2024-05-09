#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vec_char.h"


p_vchar criar_vetor(){
    p_vchar vec_char = malloc(sizeof(struct vec_char));
    vec_char->n = 0;
    vec_char->size = 10;
    vec_char->data = malloc(vec_char->size * sizeof(char *));
    for (int i=0;i<vec_char->size;i++){
        vec_char->data[i] = malloc(50 * sizeof(char));
    }
    return vec_char;
}

void adiciona_vetor(p_vchar vec_char, char *str_){
    strcpy(vec_char->data[vec_char->n++], str_);
}

void print_vetor(p_vchar vec_char){
    for(int i =0;i<vec_char->n;i++){
        printf("%s | ", vec_char->data[i]);
    }
    printf("\n");
}

void destruir_vetor(p_vchar vec_char){
    for (int i=0;i<vec_char->size;i++){
        free(vec_char->data[i]);
    }
    free(vec_char->data);
    free(vec_char);
}