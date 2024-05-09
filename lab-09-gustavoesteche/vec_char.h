#ifndef VPCHAR_H
#define VPCHAR_H

typedef struct vec_char *p_vchar;

struct vec_char{
    int n;
    int size;
    char **data;
};

p_vchar criar_vetor();

void adiciona_vetor(p_vchar vec_char, char *str_);

void print_vetor(p_vchar vetor_char);

void destruir_vetor(p_vchar vec_char);

#endif