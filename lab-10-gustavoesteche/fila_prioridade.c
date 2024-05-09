#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade.h"


void troca(Item *a, Item *b){
    Item t = *a;
    *a = *b; 
    *b = t;
}

p_fp criar_filaprio(int tam){
    p_fp f_prio = malloc(sizeof(struct FP));
    f_prio->v = malloc(tam * sizeof(Item));
    f_prio->id = malloc(tam * sizeof(int));
    f_prio->tamanho = tam;
    f_prio->n = 0;

    return f_prio;
}


#define PAI(i) ((i-1)/2)

void sobe_no_heap(p_fp fprio, int k){
    if(k>0 && fprio->v[PAI(k)].chave < fprio->v[k].chave){
        int pai = PAI(k);
        fprio->id[fprio->v[k].id] = pai;
        fprio->id[fprio->v[pai].id] = k;
        troca(&fprio->v[k], &fprio->v[pai]);
        sobe_no_heap(fprio, pai);
    }
}

#define F_ESQ(i) (2*i+1)
#define F_DIR(i) (2*i+2)

void desce_no_heap(p_fp fprio , int k){
    if(F_ESQ(k) < fprio->n){
        int maior_filho = F_ESQ(k);
        if (F_DIR(k) < fprio ->n && fprio->v[F_ESQ(k)].chave < fprio->v[F_DIR(k)].chave)
            maior_filho = F_DIR(k);
        if (fprio ->v[k].chave < fprio->v[maior_filho].chave){
            fprio->id[fprio->v[k].id] = maior_filho;
            fprio->id[fprio->v[maior_filho].id] = k;
            troca (&fprio ->v[k], &fprio->v[maior_filho]);
            desce_no_heap(fprio , maior_filho);
        }
    }
}


void insere(p_fp fprio, Item item){
    fprio->v[fprio->n] = item;
    fprio->id[item.id] = fprio->n;
    fprio->n++;
    sobe_no_heap(fprio, fprio->n - 1);
}

Item extrai_maximo(p_fp fprio){
    Item item = fprio->v[0];
    fprio->id[fprio->v[0].id] = fprio->n - 1;
    fprio->id[fprio->v[fprio->n - 1].id] = 0;
    troca(&fprio->v[0], &fprio->v[fprio->n - 1]);
    fprio->n--;
    desce_no_heap(fprio, 0);
    return item;
}

void muda_prioridade(p_fp fprio, int ID, int valor){
    int k = fprio->id[ID];
    fprio->v[k].chave += valor;
    if( valor > 0){
        sobe_no_heap(fprio, k);
    }else if(valor < 0){
        desce_no_heap(fprio, k);
    }
}

void destruir_filaprio(p_fp fprio){
    free(fprio->v);
    free(fprio->id);
    free(fprio);
}