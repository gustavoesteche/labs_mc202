#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"
#include "pilha.h"
#include "no.h"

int operator(char c){
// retorna 1 caso o char c seja um operador, se não 0

    char op[10] = {'<','>','}','{','=','!','|','&'};

    for(int i=0;i<8;i++){
        if(c == op[i]){
            return 1;
        }
    }
    return 0;

}

p_no construir_arvore(char *expressao){
// constrói a árvore binária utilizando a string expressão, 
// que está em ordem pós-fixa, através de uma pilha.
    
    int tamanho = strlen(expressao);
    p_pilha pilha = criar_pilha(tamanho);

    for(int i = 0; i < tamanho; i++){
        if(!operator(expressao[i])){
            p_no no = criar_no(expressao[i]);
            empilhar(pilha, no);
        }else{  
            p_no direita = desempilhar(pilha);
            p_no esquerda = desempilhar(pilha);
            p_no operador = criar_no(expressao[i]);

            operador->dir = direita;
            operador->esq = esquerda;
            empilhar(pilha, operador);
        }
    }

    p_no raiz = desempilhar(pilha);
    free(pilha->itens);
    free(pilha);

    return raiz;
}


void destruir_arvore(p_no raiz){
// Libera a memóra ocupada pela árvore

    if(raiz != NULL){
        destruir_arvore(raiz->dir);
        destruir_arvore(raiz->esq);
        free(raiz);
    }
}

void print_arvore(p_no raiz){
    if(raiz != NULL){
        printf("%c ", raiz->dado);
        print_arvore(raiz->dir);
        print_arvore(raiz->esq);
        
    }
}

void inordem(p_no raiz){
    if (raiz != NULL) {
        if (raiz->esq != NULL || raiz->dir != NULL) {
            printf("(");
        }
        inordem(raiz->esq);
        if(operator(raiz->dado)){
            printf(" %c ", raiz->dado);
        }else{
            printf("%c", raiz->dado);
        }
        inordem(raiz->dir);
        if (raiz->esq != NULL || raiz->dir != NULL) {
            printf(")");
        }
    }
}

p_no construir_arvore_simplificada(char *expressao){
    int tamanho = strlen(expressao);
    p_pilha pilha = criar_pilha(tamanho);

    for(int i = 0; i < tamanho; i++){
        if(!operator(expressao[i])){
            p_no no = criar_no(expressao[i]);
            empilhar(pilha, no);
        }else{  
            p_no direita = desempilhar(pilha);
            p_no esquerda = desempilhar(pilha);
            p_no operador = criar_no(expressao[i]);
            
            operador->dir = direita;
            operador->esq = esquerda;
            
            operador = simplificar_arvore(operador);

            empilhar(pilha, operador);
        }
    }

    p_no raiz = desempilhar(pilha);
    free(pilha->itens);
    free(pilha);

    return raiz;
}

void simplifica_true(p_no raiz){
    destruir_arvore(raiz->dir);
    destruir_arvore(raiz->esq);
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->dado = 'T';
}

void simplifica_false(p_no raiz){
    destruir_arvore(raiz->dir);
    destruir_arvore(raiz->esq);
    raiz->dir = NULL;
    raiz->esq = NULL;
    raiz->dado = 'F';
}

int numero(p_no no){
    return (no->dado >= 48) && (no->dado <= 57);
}


p_no simplificar_arvore(p_no raiz){
    
    if(numero(raiz->dir) && numero(raiz->esq)){
        switch (raiz->dado){
        case '=':
            if(raiz->dir->dado == raiz->esq->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;
        
        case '!':
            if(raiz->dir->dado != raiz->esq->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;

        case '<':
            if(raiz->esq->dado < raiz->dir->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;

        case '>':
            if(raiz->esq->dado > raiz->dir->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;

        case '{':
            if(raiz->esq->dado <= raiz->dir->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;

        case '}':
            if(raiz->esq->dado >= raiz->dir->dado){
                simplifica_true(raiz);
            }else{
                simplifica_false(raiz);
            }
            break;
        }

    }else{
        
        switch (raiz->dado){
        case '|':
            if((raiz->dir->dado == 'T')||(raiz->esq->dado == 'T')){
                simplifica_true(raiz);
            }
            break;
        
        case '&':
            if((raiz->dir->dado == 'F')||(raiz->esq->dado == 'F')){
                simplifica_false(raiz);
            }
            break;
        
        case '{':
            if((raiz->dir->dado == '9') || ((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado)))){
                simplifica_true(raiz);
            }else if(raiz->esq->dado == '0'){
                simplifica_true(raiz);
            }
            break;
        
        case '}':
        
            if((raiz->dir->dado == '0') || ((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado)))){

                simplifica_true(raiz);
                
            }else if(raiz->esq->dado == '9'){

                simplifica_true(raiz);
                
            }

            break;

        case '>':
            if((raiz->dir->dado == '9') || ((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado)))){

                simplifica_false(raiz);
            }else if(raiz->esq->dado == '0'){

                simplifica_false(raiz);
            }
            break;
        
        case '<':
            if((raiz->dir->dado == '0') || ((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado)))){

                simplifica_false(raiz);
            }else if(raiz->esq->dado == '9'){

                simplifica_false(raiz);
            }
            break;

        case '=':
            if((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado))){

                simplifica_true(raiz);
            }
            break;
        
        case '!':
            if((raiz->dir->dado == raiz->esq->dado)&&(!operator(raiz->dir->dado))){

                simplifica_false(raiz);
            }
            break;
        }
    }
    return raiz;
}

p_no criar_no(char dado){
    p_no no = malloc(sizeof(struct no));
    no->dado = dado;
    no->esq = NULL;
    no->dir = NULL;

    return no;
}