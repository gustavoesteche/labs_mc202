#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvore_binaria.h"
#include "no.h"


int main(){
    p_arvore arvore = malloc(sizeof(struct arvore));
    p_arvore arvore_simplificada = malloc(sizeof(struct arvore));

    int n;
    scanf("%d", &n);

    char expressao[200];


    for(int i = 0;i<n;i++){
        scanf("%s", expressao);
        
        arvore->raiz = construir_arvore(expressao);
        inordem(arvore->raiz);
        printf("\n");

        
        arvore_simplificada->raiz = construir_arvore_simplificada(expressao);
        inordem(arvore_simplificada->raiz);
        printf("\n\n");
        

        destruir_arvore(arvore->raiz);
        destruir_arvore(arvore_simplificada->raiz);
    }
    
    free(arvore);
    free(arvore_simplificada);
}