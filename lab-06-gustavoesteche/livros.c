#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_livros.h"

int string_size(char string[]){
// retorna o tamanho da string em size.

    int size = 0;
    while(string[size] != '\0'){
        size++;
    }       
    return size;
}

int compare_string(char palavra1[], char palavra2[]){
// compara as strings palavra1 e a palavra2.

    int tamanho;
    tamanho = string_size(palavra1);
    for(int i =0;i<tamanho;i++){
        if(palavra1[i] != palavra2[i]){
            return 0;
        }
    }
    return 1;
}


char *receber_anexo(int *tamanho) {
// Recebe o nome dos livros e retorna também alocando seu tamanho ao ponteiro.
    char c, s[56];
    int len = 0;
    scanf("%c", &c); // remover o espaço vazio entre o comando e o nome

    while(scanf("%c", &c) != EOF){
        if(c == '\n')
            break;
        s[len++] = c;
    }
    s[len] = '\0';
    *tamanho = len + 1;
    char *anexo = malloc((len + 1) * sizeof(char));
    strcpy(anexo, s);

    return anexo;
}


int main(){
    p_livro lista = criar_lista();
    int mode = 1, var = 0; 
    int *tamanho = &var;
    

    char input[55];
    char *anexo;

// lendo até o final do arquivo os comando iniciais
    while(scanf("%s",input) != EOF){
    
        if(compare_string(input, "adicionar")){
            anexo = receber_anexo(tamanho);
            lista = adiciona(lista, anexo, *tamanho, &mode);
            free(anexo);
            
        }else if(compare_string(input, "remover")){
            anexo = receber_anexo(tamanho);
            lista = remove_livro(lista, anexo, &mode);
            free(anexo);

        }else if(compare_string(input, "inicio")){
            mode = 0;
            
        }else if(compare_string(input, "final")){
            mode = 1;

        }else if(compare_string(input, "imprimir")){
            imprimir_lista(lista);
        }
    }

    
    destruir_lista(lista);

    return 0;
}