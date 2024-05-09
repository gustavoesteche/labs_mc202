#include <stdlib.h>
#include <stdio.h>
#include "graphs.h"
#include "no.h"
#include "fila.h"
#include "pilha.h"


p_graph create_graph(){
    p_graph g = malloc(sizeof(struct graph));
    g->n = 0;
    g->size = SIZE;
    g->adj = malloc(g->size * sizeof(struct node));
    for(int i = 0;i < g->size;i++){
        g->adj[i] = NULL;
    }
    return g;
}

void free_linkedlist(p_node list){
    if(list != NULL){
        free_linkedlist(list->next);
        free(list);
    }
}

void free_graph(p_graph g){
    for(int i = 0;i<g->size;i++){
        free_linkedlist(g->adj[i]);
    }
    free(g->adj);
    free(g);
}

void insert_vertex(p_graph g, int ID){
    g->id[ID] = g->n;
    g->pos_to_id[g->n] = ID;
    g->n++;
}

p_node insert_list(p_node list, int value){
    p_node new = malloc(sizeof(struct node));
    new->v = value;
    new->next = list;
    return new;
}

void insert_edge(p_graph g, int u, int v){
    int v1 = g->id[u], v2 = g->id[v];
    g->adj[v1] = insert_list(g->adj[v1], v);
    g->adj[v2] = insert_list(g->adj[v2], u);
}


void remove_1edge(p_graph g, int u, int v){
    p_node now = g->adj[g->id[u]];
    if(now == NULL)
        return;

    if(now->v == v){
        g->adj[g->id[u]] = now->next;
        free(now);
        return;    
    }

    p_node remove;
    for(;now->next != NULL;now=now->next){
        if(now->next->v == v){
            remove = now->next;
            now->next = remove->next;
            free(remove);
            break;
        }
    }
}
void remove_edge(p_graph g, int u, int v){
    remove_1edge(g, u ,v);
    remove_1edge(g, v, u);
}

int exist_path_dfs(p_graph g, int u, int v){
    int exist = 0;
    p_pilha pilha = criar_pilha(g->n);
    int *visitado = calloc(g->n, sizeof(int));


    empilhar(pilha, g->id[u]);
    p_node temp;
    int w, run = 1;
    int atual;
    while(pilha->total != 0 && run){
        w = desempilha(pilha);
        if(visitado[w])
            continue;
        visitado[w] = 1;
        for(temp = g->adj[w];temp != NULL;temp=temp->next){
            atual = g->id[temp->v];
            if(!visitado[atual]){
                empilhar(pilha, atual);
            }
            if(temp->v == v){
                run = 0;
                exist = 1;
                break;
            }
        }
    }
    free(visitado);
    destruir_pilha(pilha);

    return exist;
}

void reverse_path(p_graph g, int *pai, int u){
    p_pilha pilha = criar_pilha();
    int atual = pai[g->n];
    
    while(atual != g->id[u]){
        empilhar(pilha, atual);
        atual = pai[atual];
    }
    empilhar(pilha, atual);
    
    int valor, i= 0;
    while(pilha->total != 0){
        valor = desempilha(pilha);
        pai[i] = g->pos_to_id[valor]; 
        i++;
    }
    destruir_pilha(pilha);
}


int* smallest_path_bfs(p_graph g, int u, int v, int *found){
    int * pai = malloc((g->n+1) * sizeof(int));
    int *visitado = calloc(g->n, sizeof(int));
    p_fila fila = criar_fila();

    int s;
    for (s = 0; s < g->n; s++) {
        pai[s] = -1;
        visitado[s] = 0;
    }
    inserir_fila(fila, g->id[u]);
    pai[g->id[u]] = g->id[u];
    visitado[g->id[u]] = 1;

    p_node temp;
    int atual, run = 1;
    *found = 0;
    while (fila->total != 0 && run) {
        s = remove_fila(fila);

        for (temp = g->adj[s];temp != NULL;temp=temp->next){
            atual = g->id[temp->v];
            if (!visitado[atual]) {
                visitado[atual] = 1;
                pai[atual] = s;
                inserir_fila(fila, atual);
            }
            if(temp->v == v){
                run = 0;
                pai[g->n] = atual;
                *found = 1;
                break;
            }
        }
    }

    if(*found)
        reverse_path(g, pai, u);

    destruir_fila(fila);
    free(visitado);
    return pai;
}




void visit_rec(p_graph g, int *componentes , int comp , int v) {
    p_node t;
    componentes[v] = comp;
        for (t = g->adj[v]; t != NULL; t = t->next)
            if (componentes[g->id[t->v]] == -1)
                visit_rec(g, componentes , comp , g->id[t->v]);
}

int *find_components(p_graph g){
    int s, c = 0, *componentes = malloc(g->n * sizeof(int));
    for (s = 0; s < g->n; s++)
        componentes[s] = -1;
    for (s = 0; s < g->n; s++)
        if (componentes[s] == -1) {
            visit_rec(g, componentes , c, s);
            c++;
        }
    return componentes;
}

