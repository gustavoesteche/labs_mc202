#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_livros.h"

p_livro criar_lista(){
// cria a lista ligada
    return NULL;
}

p_livro adiciona(p_livro lista, char *nome_livro, int tamanho, int *mode){
/* Adiciona o livro nome_livro na lista de acordo com o modo específico,
mode = 0 início, mode = 1 final, mode = 2 recente. O primeiro chamado é o 
adiciona final por padrão. 
*/
    p_livro novo;
    novo = malloc(sizeof(struct lista_livros));
    novo->nome = malloc(tamanho * sizeof(char));
    strcpy(novo->nome, nome_livro);

    if(*mode == 0){
        *mode = 2;
        novo->prox = lista;
        lista->recente = novo;
        novo->recente = novo;
        return novo;

    }else if(*mode == 1){
        novo->prox = NULL;
        if(lista == NULL){
            novo->recente = novo;    
            return novo;
        }
        p_livro temp = lista;
        while(temp->prox != NULL){
            temp = temp->prox;
        }
        temp->prox = novo;
        lista->recente = novo;
        return lista;

    }else if(*mode == 2){
        novo->prox = lista->recente->prox;
        lista->recente->prox = novo;
        lista->recente = novo;
        novo->recente = novo;
        return lista;
    }

    return lista;
}


p_livro remove_livro(p_livro lista, char *nome_livro, int *mode) {
// Remove o livro da lista de nome, nome_livro    
    
    *mode = 2;
   
    if (lista == NULL) {
        return NULL;
    }
    // manejar o caso em que o nome a ser removido é o primeiro lista
    if (strcmp(lista->nome, nome_livro) == 0){
        //manejar o caso em que o primeiro adicionado é o mais recente
        if(strcmp(lista->nome, lista->recente->nome) == 0){
            p_livro temp = lista;
            lista = lista->prox; 
            free(temp->nome);
            free(temp);
            *mode = 0;

        }else{
            p_livro temp = lista;
            lista->prox->recente = lista->recente;
            lista = lista->prox;

            free(temp->nome);
            free(temp);
        }

    }else {
        // caso em que o elemento a ser removido não é o primeiro
        p_livro atual = lista;
        while (atual->prox != NULL && strcmp(atual->prox->nome, nome_livro) != 0) {
            atual = atual->prox;
        }

        if (atual->prox != NULL) {
            if(strcmp(atual->prox->nome, lista->recente->nome) == 0){
                lista->recente = atual;
                p_livro temp = atual->prox;
                atual->prox = temp->prox;

                free(temp->nome);
                free(temp);
            }else{
                p_livro temp = atual->prox;
                atual->prox = temp->prox;

                free(temp->nome);
                free(temp);
            }
        }
    }   


    return lista;
}


void imprimir_lista(p_livro lista){
// imprime a lista de livros atual
    if(lista == NULL){
        return;
    }

    if(lista->prox == NULL){
        printf("%s\n", lista->nome);
    }else if(lista != NULL){
        printf("%s, ", lista->nome);
        imprimir_lista(lista->prox);
    }
    
}

void destruir_lista(p_livro lista){
// libera toda a memória da lista ligada
    if(lista != NULL){
        destruir_lista(lista->prox);
        free(lista->nome);
        free(lista);
    }
}

