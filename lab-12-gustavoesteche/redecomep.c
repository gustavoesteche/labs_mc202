#include <stdio.h>
#include <stdlib.h>
#include "graphs.h"



int main(){
    int operacao;
    int id1, id2;
   
    int run = 1;
    int *components;
    int *path;
    int found; 

    p_graph g = create_graph();

    while(run){
        scanf("%d", &operacao);
        
        switch (operacao){
        case 1:
            scanf("%d", &id1);
            insert_vertex(g, id1);
            break;
        case 2:
            scanf("%d", &id1);
            scanf("%d", &id2);
            insert_edge(g, id1, id2);
            break;
        case 3:
            scanf("%d", &id1);
            scanf("%d", &id2);
            remove_edge(g, id1, id2);
            break;
        case 4:
            scanf("%d", &id1);
            scanf("%d", &id2);
            if(exist_path_dfs(g,id1, id2)){
                printf("Existe conexão entre os nós.\n");
            }else{
                printf("Não existe conexão entre os nós\n");
            }
            break;
        case 5:
            scanf("%d", &id1);
            scanf("%d", &id2);
            path = smallest_path_bfs(g, id1, id2, &found);
            
            if(found == 0){
                printf("Não existe conexão entre os nós.\n");
            }else{
                for(int i = 0;i<g->n;i++){
                    if(path[i] != id2){
                        printf("%d -> ", path[i]);
                    }else{
                        printf("%d\n", path[i]);
                        break;
                    }
                }
            }

            free(path);
            break;
        case 6:
            components = find_components(g);
            int c;
            for(int i = 0;i< g->n;i++){
                c = components[i];
                printf("Ponto %d (Pontos diretamente ou indiretamente conectados): ",g->pos_to_id[i]);
                for(int j=0;j<g->n;j++){
                    if(components[j] == c){
                        printf("%d ", g->pos_to_id[j]);
                    }
                }
                printf("\n");
            }
            free(components);
            break;
        default:
            run = 0; 
            break;
        }
    }

    free_graph(g);
}