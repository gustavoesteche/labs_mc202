#pragma once

// Devido a utlizacao para pontos de rede, espera-se grafos esparsos

typedef struct node *p_node;

struct node{
    p_node next;
    int v;
};

#define SIZE 30;

typedef struct graph *p_graph;

struct graph{
    p_node *adj;
    int id[30];
    int pos_to_id[30];
    int n, size;
};

p_graph create_graph();
// criando o grafo e inicializando com tamanho SIZE.

void free_linkedlist(p_node list);

void free_graph(p_graph g);
// libera a memoria ocupada pelo grafo.

void insert_vertex(p_graph g, int ID);
// insere o vertice no grafo

p_node insert_list(p_node list, int value);
// insere na lista ligada

void insert_edge(p_graph g, int u, int v);
// insere uma aresta entre o vertice u e o vertice v, se ja existir ignora.

void remove_edge(p_graph g, int u, int v);
// remove a aresta entre o vertice u e o vertice v, se nao existir ignora.

int exist_path_dfs(p_graph g, int u, int v);
// procura se existe caminho entre o vertice u e o vertice v, usando dfs.

int* smallest_path_bfs(p_graph g, int u, int v, int *found);
// procura o menor caminho entre dois vertices, se exister retorna um ponteiro para um
// vetor de inteiros que representa o caminho, se nao retornal NULL, usando bfs.

int* find_components(p_graph g);
// encontra as componentes conexas do grafo e retorna um ponteiro para um vetor de inteiros
// em que cada indice do vetor eh o vertice do grafo e o valor sua componente.