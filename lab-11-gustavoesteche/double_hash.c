#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_hash.h"

#define MAX 2503
#define MAX2 1279

p_hash criar_hash(){
    // cria e retorna um ponteiro para um vetor de hash 

    p_hash hash_t = malloc(sizeof(struct hash));
    for(int i = 0; i < MAX;i++){
        hash_t->vetor[i] = NULL;
    }
    return hash_t;    
}

void destruir_hash(p_hash hash_t){
    // libera a memória ocupada pelos nos do vetor e pelo ponteiro do vetor

    for(int i = 0; i < MAX ; i++){
        if(hash_t->vetor[i] != NULL){
            free(hash_t->vetor[i]);
            hash_t->vetor[i] = NULL;
        }
    }
    free(hash_t);
}

int hash_1(char * chave){
    // calcula o primeiro hash

    int i, key = 0 ;
    for(i = 0; i < strlen(chave); i++){
        key = (256 * key + chave[i]) % MAX;
    }
    return key;
}

int hash_2(char * chave){
    // calcula o segundo hash para ir pulando quando o primeiro hash esta ocupado

    int i, key = 0;
    for(i = 0; i < strlen(chave); i++){
        key = (256 * key + chave[i]) % MAX2 ;
    }
    return key;
}

void inserir(p_hash hash_t, char *chave, int dado){
    // insere no vetor de hash

    int key1 = hash_1(chave), key2 = hash_2(chave);
    int k = key1;
    
    for(int i = 0; i < MAX ; i++){
        if(hash_t->vetor[k] == NULL){
            // if there is an empty space place it there
            hash_t->vetor[k] = malloc(sizeof(struct no));
            hash_t->vetor[k]->dado = dado;
            strcpy(hash_t->vetor[k]->chave, chave);
            break;
        }else if(!strcmp(hash_t->vetor[k]->chave, " ")){
            hash_t->vetor[k]->dado = dado;
            strcpy(hash_t->vetor[k]->chave, chave);
            break;
        }
        k = (k + key2) % MAX;
        
    }
}

int remover(p_hash hash_t, char *chave){
    // remove no vetor de hash, 

    int key1 = hash_1(chave), key2 = hash_2(chave);
    int k = key1;
    int doces = 0;
    for(int i = 0; i < MAX ; i++){
        if(hash_t->vetor[k] == NULL){
            // element does not exist 
            break;
        }else if(strcmp(hash_t->vetor[k]->chave,chave) == 0){
            // remove the element of the vector
            doces = hash_t->vetor[k]->dado;
            hash_t->vetor[k]->dado = 0;
            strcpy(hash_t->vetor[k]->chave, " ");
            return doces;
        }
        k = (k + key2) % MAX;
    }
    return doces;
}

p_no buscar(p_hash hash_t, char *chave){
    // busca no vetor de hash

    int key1 = hash_1(chave), key2 = hash_2(chave);
    int k = key1;
    
    for(int i = 0; i < MAX ; i++){
        if(hash_t->vetor[k] == NULL){
            // element does not exist 
            return NULL;
        }else if(strcmp(hash_t->vetor[k]->chave,chave) == 0){
            // return the element of the vector
            return hash_t->vetor[k];
        }
        k = (k + key2) % MAX;
    }
    return NULL;
}

int remover_doces(p_hash hash_t, char *chave, char *nota){
    // remove os doces de uma familia e retorna os doces que a familia pode dar

    p_no temp = buscar(hash_t, chave);
    int qntd_doces = 0;

    if(temp == NULL){
        return 0;
    }

    if(temp->dado == 0){
        return 0;
    }

    if(!strcmp("Boa", nota)){
        qntd_doces = 3;
    }else if(!strcmp("Media", nota)){
        qntd_doces = 2;
    }else if(!strcmp("Ruim", nota)){
        qntd_doces = 1;
    }

    if(temp->dado <= qntd_doces){
        printf("A familia %s ficou sem doces.\n", temp->chave);
        qntd_doces = temp->dado;
        temp->dado = 0;
    }else{
        temp->dado -= qntd_doces;
    }
    return qntd_doces;
    
}