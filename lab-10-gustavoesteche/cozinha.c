#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila_prioridade.h"
#include "vetor_itens.h"



void recebe_linha(char *nome, int *quantidade){
// recebe o input do nome e sobrenome e prioridade

    int i = 0, k = 0;
    while(i < 2){
        scanf("%c", &nome[k]);
        if(nome[k] == ' '){
            i++;
        }
        k++;
    }
    nome[k] = '\0';
    scanf("%d", quantidade);
}




int main(){
    int P, S;
    scanf("%d", &P);
    scanf("%d", &S);

    p_fp fprio = criar_filaprio(S);
    p_vitens vitens = criar_vitens(S);

    char nome[30];
    int quantidade;
    
    Item item;
    // forma um vetor que guarda cada Item com a sua posicao sendo o ID
    for(int i = 0;i<S;i++){
        
        recebe_linha(nome, &quantidade);
        item.chave = quantidade;
        strcpy(item.nome, nome);
        item.id = i;
        adiciona_item(vitens, item);
        
    }


    
    int rodada = 1;
    int N, ID, valor;
    int run = 1;
    char comando[10];
    char prato[30];
    int k = 0;

    // Realiza o processo das querys e retira P ou menos pratos da fila
    // de prioridade 
    while(run){
        scanf("%d", &N);

        if(N == 0){
            break;
        }
        
        for(int i = 0;i<N;i++){
            scanf("%s", comando);
            
            if(strcmp(comando, "novo") == 0){
                
                scanf("%d ", &ID);
                k = 0;
                
                while(1){
                    // pequeno trecho para ler o nome do prato.
                    scanf("%c", &prato[k]);
                    if(prato[k] == '\n'){
                        prato[k] = '\0';
                        break;
                    }
                    k++;
                }
            
                strcpy(vitens->data[ID].prato, prato);
                insere(fprio, vitens->data[ID]);

            }else{
                scanf("%d", &ID);
                scanf("%d", &valor);
             
                muda_prioridade(fprio, ID, valor);
            }
        }

        printf("---- rodada %d ----\n", rodada);
        Item maximo;
        for(int j=0;j<P;j++){
            if(fprio->n <= 0)
                break;
            maximo = extrai_maximo(fprio);
            printf("%s%s %d\n",maximo.nome, maximo.prato, maximo.chave);
        }

        rodada++;
    }

    // retira, caso sobre, o resto dos pratos da fila de prioridade
    while(fprio->n > 0){
        printf("---- rodada %d ----\n", rodada);
        Item maximo;
        for(int j=0;j<P;j++){
            if(fprio->n <= 0)
                break;
            maximo = extrai_maximo(fprio);
            printf("%s%s %d\n",maximo.nome, maximo.prato, maximo.chave);
        }

        rodada++;
    }


    
    destruir_filaprio(fprio);
    destruir_vitens(vitens);
}