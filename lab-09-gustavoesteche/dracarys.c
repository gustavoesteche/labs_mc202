#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arv_rn.h"
#include "vec_char.h"

#include <time.h>


int declaracao(char * input){
    return !(strcmp(input, "char") && strcmp(input, "double") && strcmp(input, "int"));
}



void ler_linha(char *input,p_vchar vec_char, int *run){
    int i = 0;
    int j = 0;
    int parada = 1;
    char chunk[50];
    int tab_mode = 1;

    while(scanf("%c", &input[i]) != EOF){
        if(tab_mode){
            if(input[i] != ' '){
                tab_mode = 0;
            }
        }

        if(tab_mode == 0){
            if(input[i] == ' '){
                chunk[j] = '\0';
                j = -1;
                adiciona_vetor(vec_char, chunk);
            }else{
                chunk[j] = input[i];
            }

            if(input[i] == '\n'){
                if(chunk[j-1] == ';'){
                    chunk[j-1] = '\0';
                }else{
                    chunk[j] = '\0';
                }
                adiciona_vetor(vec_char, chunk);
                input[i] = '\0';
                parada = 0;
                break;
            }
            i++;
            j++;
        }
    }

    if(parada){
        input[i] = '\0';
        *run = 0;
    }
}

void checar_definido(p_no raiz, p_vchar vec_char, int linha, int *erro_linha){

    if(*erro_linha == 0){
        if(buscar_chave(raiz, vec_char->data[0]) == NULL){
            *erro_linha = 1;
            printf("Linha %d: o símbolo %s não foi definido.\n", linha, vec_char->data[0]);
        }else if(buscar_chave(raiz, vec_char->data[2]) == NULL){
            *erro_linha = 1;
            printf("Linha %d: o símbolo %s não foi definido.\n", linha, vec_char->data[2]);
        }else if(buscar_chave(raiz, vec_char->data[4]) == NULL){
            *erro_linha = 1;
            printf("Linha %d: o símbolo %s não foi definido.\n", linha, vec_char->data[4]);
        }
        
    }
}

void checar_tipo(p_no raiz, p_vchar vec_char, int linha, int *erro_linha){
    if(*erro_linha==0){
        p_no primeiro = buscar_chave(raiz, vec_char->data[2]);
        p_no segundo = buscar_chave(raiz, vec_char->data[4]);

        if(strcmp(primeiro->tipo, segundo->tipo) != 0){
            *erro_linha = 1;
            printf("Linha %d: tipos incompatíveis: %s (%s) %s %s (%s).\n",linha,primeiro->chave,primeiro->tipo,vec_char->data[3],segundo->chave,segundo->tipo);
        }

        
    }
}

void checar_resultado(p_no raiz, p_vchar vec_char, int linha, int *erro_linha){
    if(*erro_linha == 0){
        p_no resultado = buscar_chave(raiz, vec_char->data[0]);
        p_no primeiro = buscar_chave(raiz, vec_char->data[2]);

        if(strcmp(resultado->tipo, primeiro->tipo) != 0){
            *erro_linha = 1;
            printf("Linha %d: tipos incompatíveis: o símbolo %s espera %s, obteve %s.\n", linha,resultado->chave, resultado->tipo, primeiro->tipo);
        }
    }
}

int main(){

    p_no raiz = NULL;
    
    int linha = 1;
    int erro_linha = 0;
    int erro_total = 0;
    
    int run = 1;
    char input[100];
    p_vchar vec_char  = criar_vetor();
    
    while(run){
        vec_char->n = 0;
        
        ler_linha(input,vec_char, &run);
        
        
        
        if(declaracao(vec_char->data[0]) && (strcmp(vec_char->data[1],"main") != 0 && strcmp(vec_char->data[1],"main()") != 0)){
            
            raiz = inserir(raiz,vec_char->data[1],vec_char->data[0]);
            
        }
        
        if(strcmp(vec_char->data[1],"=") == 0 && vec_char->n >= 4){
            //first error 
            checar_definido(raiz, vec_char, linha, &erro_linha);
            checar_tipo(raiz, vec_char,linha,&erro_linha);
            checar_resultado(raiz, vec_char, linha, &erro_linha);
            if(erro_linha == 1){
                erro_total = 1;
            }
        }
        
        
        linha++;
        erro_linha = 0;
    }
    
    if(erro_total == 0){
        printf("Não há erros de tipo.\n");
    }

    
    
    printar_arvore(raiz);
    destruir_arvore(raiz);
    destruir_vetor(vec_char);
    
    
}