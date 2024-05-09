typedef struct lista_livros *p_livro;

struct lista_livros{
    char *nome;
    p_livro prox;
    p_livro recente;
};

p_livro criar_lista();
// inicializa a lista ligada como NULL

p_livro adiciona(p_livro lista, char *nome_livro, int tamanho, int *mode);
/*Adiciona o livro nome_livro na lista de acordo com o modo específico,
mode = 0 início, mode = 1 final, mode = 2 recente. O primeiro chamado é o 
adiciona final por padrão. 
*/

p_livro remove_livro(p_livro lista, char *nome_livro, int *mode);
// Remove um livro da lista ligada.

void imprimir_lista(p_livro lista);
// imprime a lista na ordem

void destruir_lista(p_livro lista);
// libera a memória alocada pela lista ligada