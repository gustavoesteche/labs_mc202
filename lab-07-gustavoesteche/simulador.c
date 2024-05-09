#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trabalhador.h"
#include "fila.h"
#include "pilha.h"


trab criar_trabalhador(){
    trab worker;
    worker.ocpd = 0;
    worker.t_falta = 0;
    worker.recebeu = 0;
    worker.liberou = 0;
    return worker;
}

 
void receber_input(int *tempo){
// recebe o input e devolve para os ponteiros o ponteiro tempo de embalagem e tempo de classificação
    
    char s[10];
    int tipo;
    scanf("%s", s);
    scanf("%d", &tipo);

    if(strcmp(s, "grande") == 0){
        tempo[0] = 3;
        switch (tipo){
        case 1:
            tempo[1] = 2;
            break;
        case 2:
            tempo[1] = 3;
            break;
        }
    }else if(strcmp(s, "media") == 0){
        tempo[0] = 2;
        switch (tipo){
        case 1:
            tempo[1]= 2;
            break;
        case 2:
            tempo[1] = 3;
            break;
        }
    }else if(strcmp(s, "pequena") == 0){
        tempo[0] = 1;
        switch (tipo){
        case 1:
            tempo[1] = 1;
            break;
        case 2:
            tempo[1] = 2;
            break;
        }
    }

}


int main(){

    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    p_fila esteira = criar_fila(a);
    p_pilha pilha = criar_pilha(b);


    trab embalador = criar_trabalhador();
    trab classificador = criar_trabalhador();

    int x;
    classificador.t_prox = &x;
    

    int linhas;
    scanf("%d", &linhas);
    
    int atraso = 0;  
    int *tempo = malloc(2 * sizeof(int));

    
    int run = 1;
    int minuto = 1;
    
    
    printf("##### Simulação\n"); 
    while(run){

        // embalador vai trabalhar em uma peça
        if(embalador.ocpd){
            embalador.t_falta--;
            if(embalador.t_falta <= 0){
                embalador.ocpd = 0;
                embalador.liberou = 1;
            }
        }

        // embalador tenta pegar uma peça nova caso esteja desocupado e tenha peças na pilha
        if(embalador.ocpd == 0){
            if(pilha->total > 0){
                embalador.t_falta = desempilha(pilha);
                embalador.ocpd = 1;
            }
        }        
        
        

        // classificador vai trabalhar na peça, tentar liberar peça e colocar em cima da pilha
        if(classificador.ocpd){
            classificador.t_falta--;
            if((classificador.t_falta <= 0) && (pilha->total < pilha->max)){
                empilhar(pilha, *classificador.t_prox);
                classificador.liberou = 1;
                embalador.recebeu = 1;
                classificador.ocpd = 0;
            }
        }

        // classificador vai tentar pegar uma nova peça
        if((classificador.ocpd == 0) && (esteira->total > 0)){
            classificador.t_falta = remove_fila(esteira, classificador.t_prox);
            classificador.ocpd = 1;
        }
        

        // adicionar uma peça na esteira classificadora
        if(linhas > 0){
            if(esteira->total < esteira->max){
                receber_input(tempo);
                inserir_fila(esteira, tempo);
                classificador.recebeu = 1;
                linhas--;
            }else{
                atraso++;
            }
        }

        // checar fim da simulação
        if((linhas == 0) && (esteira->total + pilha->total== 0) && (classificador.ocpd == 0) && (embalador.ocpd == 0)){
            run = 0;
        }

        
        printf("Min. %d: Classificação (+%d,-%d) | Embalagem (+%d,-%d).\n",minuto, classificador.recebeu, classificador.liberou, embalador.recebeu, embalador.liberou);
        
        // reinicia as variáveis dos trabalhadores de cada minuto
        embalador.recebeu = 0;
        embalador.liberou = 0;
        classificador.recebeu = 0;
        classificador.liberou = 0;

        
        minuto++;
    }
    printf("Tempo atraso: %d.\n", atraso);


    
    free(tempo);
    destruir_fila(esteira);
    destruir_pilha(pilha);
    return 0;
}