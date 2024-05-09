#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "double_hash.h"


int main(){
    p_hash hash_t = criar_hash();

    // cria todas as variaveis utilizadas nos codigos
    char comando[15];
    char nome_familia[15], nota_fantasia[10];
    char nome_crianca[15];
    char sobrenome_crianca[15];
    int n_doces, n_casas, doces_crianca;
    p_no temporario;
    int run = 1;

    // loop dos comandos
    while(run){
        scanf("%s ", comando);
        if(!strcmp(comando,"ENTRAR")){
            scanf("%s",nome_familia);
            scanf("%d", &n_doces);
            inserir(hash_t, nome_familia, n_doces);

        }else if(!strcmp(comando,"SAIR")){
            scanf("%s", nome_familia);
            n_doces = remover(hash_t, nome_familia);
            printf("A familia %s saiu com %d doce(s) sobrando.\n", nome_familia, n_doces);

        }else if(!strcmp(comando, "COMPRAR")){
            scanf("%s", nome_familia);
            scanf("%d", &n_doces);
            temporario = buscar(hash_t, nome_familia);
            temporario->dado += n_doces;
            printf("A familia %s agora possui %d doces.\n", temporario->chave, temporario->dado);

        }else if(!strcmp(comando, "TRICKORTREAT")){
            scanf("%s", nome_crianca);
            scanf("%s", sobrenome_crianca);
            scanf("%d", &n_casas);
            doces_crianca = 0;
            
            for(int i=0;i < n_casas;i++){
                scanf("%s", nome_familia);
                scanf("%s", nota_fantasia);
                n_doces = remover_doces(hash_t, nome_familia, nota_fantasia);
                doces_crianca += n_doces;
            }

            if(doces_crianca > 0){
                printf("%s %s recebeu %d doce(s) das familias.\n", nome_crianca, sobrenome_crianca, doces_crianca);
            }else{
                printf("%s %s recebeu 10 doces da prefeitura.\n", nome_crianca, sobrenome_crianca);
            }

        }else if(!strcmp(comando, "FINALIZAR")){
            run = 0;
        }
    }
    
    destruir_hash(hash_t);
}