#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arv_rn.h"


int ehVermelho(p_no x){
    // determina se o no tem cor vermelha

    if(x == NULL)
        return 0;
    return x->cor == VERMELHO;
}

int ehPreto(p_no x){
    // determina se o no tem cor preta

    if(x == NULL)
        return 1;
    return x->cor == PRETO;
}

p_no rotaciona_esquerda(p_no raiz){
    // rotaciona a arvore a partir do no raiz a esquerda

        p_no x = raiz->dir;
        raiz->dir = x->esq;
        x->esq = raiz;
        x->cor = raiz->cor;
        raiz->cor = VERMELHO;
        return x;

}

p_no rotaciona_direita(p_no raiz){
    // rotaciona a arvore a partir do no raiz para a direita

        p_no x = raiz->esq;
        raiz->esq = x->dir;
        x->dir = raiz;
        x->cor = raiz->cor;
        raiz->cor = VERMELHO;
        return x;
}

void sobe_vermelho(p_no raiz){
    // troca os filhos da raiz para a cor preta, e a raiz para vermelho

    raiz->cor =  VERMELHO;
    raiz->dir->cor = PRETO;
    raiz->esq->cor = PRETO;
}

p_no inserir_rec(p_no raiz , char *chave, char *tipo){
    

    if (raiz == NULL) {
    // caso a arvore esteja vazia
        p_no novo;
        novo = (p_no)malloc(sizeof(struct no));
        novo->chave = malloc((strlen(chave) + 1) * sizeof(char));
        novo->tipo = malloc((strlen(tipo) + 1) * sizeof(char));
        novo ->esq = NULL;
        novo ->dir = NULL;
        strcpy(novo->chave, chave);
        strcpy(novo->tipo, tipo);
        novo ->cor = VERMELHO;
        return novo;
    }
    // direcionar em qual subarvore vai ser adicionado, abb. 
    if (strcmp(chave, raiz->chave) < 0)
        raiz->esq = inserir_rec(raiz ->esq , chave, tipo);
    else
        raiz->dir = inserir_rec(raiz ->dir , chave, tipo);
    
    // corrigir a estrutura da arvore apos adicionar 
    if (ehVermelho(raiz ->dir) && ehPreto(raiz ->esq))
            raiz = rotaciona_esquerda(raiz);
    if (ehVermelho(raiz ->esq) && ehVermelho(raiz ->esq ->esq))
        raiz = rotaciona_direita(raiz);
    if (ehVermelho(raiz ->esq) && ehVermelho(raiz ->dir))
        sobe_vermelho(raiz);
    return raiz;
}

p_no inserir(p_no raiz, char *chave, char *tipo){

    
    raiz = inserir_rec(raiz, chave,tipo);
    raiz->cor = PRETO;
    return raiz;
}

void printar_arvore(p_no raiz){
    if(raiz != NULL){
        
        printar_arvore(raiz->esq);
        printf("%s %s\n",  raiz->chave, raiz->tipo);
        printar_arvore(raiz->dir);
        
        
    }
}


p_no buscar_chave(p_no raiz, char *chave){
    if(raiz == NULL){
        return NULL;
    }
    if(strcmp(chave, raiz->chave) == 0){
        return raiz;
    }else if(strcmp(chave, raiz->chave) < 0){
        return buscar_chave(raiz->esq, chave);
    }else{
        return buscar_chave(raiz->dir, chave);
    }
    return NULL;
}   

void destruir_arvore(p_no raiz){
    // libera a memoria alocada na arvore recursivamente
    
    if(raiz != NULL){
        destruir_arvore(raiz->dir);
        destruir_arvore(raiz->esq);
        free(raiz->tipo);
        free(raiz->chave);
        free(raiz);
    }
}