#include <stdio.h>
#include <stdlib.h>
#include "partida.h"
#include "circuito.h"


int main(){

    int num_partidas;
    scanf("%d", &num_partidas);
    
    for(int i = 1;i<=num_partidas;i++){
        partida *p = criar_partida();
        
        ler_info_partida(p, i);

        for(int j=0;j<p->n_circuitos;j++){
            circuito *c = criar_circuito();
            ler_info_circuito(c, p->n_jogadores);
        
            armazenar_circuito(p, j, c);
            liberar_mem_circuito(c);
        }
        
        imprimir_info_partida(p);
        liberar_mem_partida(p);
    }
    
    
    return 0;
    
    
    
}