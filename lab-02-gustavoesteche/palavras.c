#include <stdio.h>
#include <stdlib.h>

#define MAX 1000
#define P 301

void reverse_word(char string[], int tamanho, char str_inversa[]){
    // função que inverte a palavra, string, para string_inversa.

    str_inversa[tamanho] = '\0';
    for(int i=0;i<tamanho;i++){
        str_inversa[i] = string[tamanho- 1 - i];
    }
}

int string_size(char string[]){
    // retorna o tamanho da string em size.

    int size = 0;
    while(string[size] != '\0'){
        size++;
    }       
    return size;
}

void imprimir(char palavra[],int condicao){
    /*imprime o texto no formato pedido, levando em conta se a palavra 
    está ou não no caça-palavra pela condicao.
    */ 

    int tamanho;
    tamanho = string_size(palavra);
    printf("A palavra ");
    for(int i=0;i<tamanho;i++){
        printf("%c",palavra[i]);
    }
    if(condicao){
        printf(" está no texto!\n");
    }else{
        printf(" não está no texto!\n");
    }
    
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


int horizontal_search(char caca_palavra[MAX][MAX], char palavra[], 
                                        int tamanho, int rows, int columns){
    /* Compara todas as combinações possíveis de palavras horizontais
    e seus inversos com a palavra buscada e retorna 0 ou 1.
    */

    if(columns < tamanho){
        return 0;
    } else {
        char palavreta[21];
        char palavreta_invertida[21];

        for(int k=0;k<rows;k++){
            for(int i=0;i<=(columns - tamanho);i++){
                for(int j=i;j<tamanho + i;j++){
                    palavreta[j - i] = caca_palavra[k][j];
                }
                reverse_word(palavreta,tamanho,palavreta_invertida);

                if(compare_string(palavra, palavreta)){
                    return 1;   
                }
                if(compare_string(palavra,palavreta_invertida)){
                    return 1;
                }
            }
        }
        return 0;
        
    }
}

int vertical_search(char caca_palavra[MAX][MAX],char palavra[], 
                                    int tamanho, int rows, int columns){
    /* Compara todas as combinações possíveis de palavras verticais
    e seus inversos com a palavra buscada e retorna 0 ou 1.
    */
    
    if(rows < tamanho){
        return 0;
    }else{
        char palavreta[21];
        char palavreta_invertida[21];

        for(int k =0;k<columns;k++){
            for(int i=0;i<=(rows-tamanho);i++){
                for(int j=i;j<tamanho + i;j++){
                    palavreta[j-i] = caca_palavra[j][k];
                }
                reverse_word(palavreta,tamanho,palavreta_invertida);

                if(compare_string(palavra, palavreta)){
                    return 1;   
                }
                if(compare_string(palavra,palavreta_invertida)){
                    return 1;
                }
            }
        }
        return 0;
    }
}


int main() {
    int rows, columns;
    char word_search[MAX][MAX];
    scanf("%d", &rows);
    scanf("%d", &columns);
    int p;
    scanf("%d", &p);

    // Lê as informações do caça-palavra .   
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            scanf(" %c", &word_search[i][j]);
        }
    }

    
    char searched_words[P][21];
    char word[21];
    int tamanho; 

    // Lê as informações das palavras as serem buscadas. 
    for(int i=0;i<p;i++){
        scanf("%s", word);
        tamanho = string_size(word);
        for(int j=0;j<tamanho;j++){
            searched_words[i][j] = word[j];
        }
        searched_words[i][tamanho] = '\0';
    }

    
    for(int i=0;i<p;i++){
        int a = horizontal_search(word_search,searched_words[i],
                                    string_size(searched_words[i]),rows, columns);
        int b = vertical_search(word_search,searched_words[i],
                                    string_size(searched_words[i]),rows, columns);
        imprimir(searched_words[i], a|b);
    }

    return 0;
}