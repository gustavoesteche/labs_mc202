#include <stdio.h>
#include <stdlib.h>
#include "bat_vector.h"
#include "bat_info.h"

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


int read_input(char s[]){
    // lê o input passado pelo usuário e devolve um número 
    // que ativa a sequência da função específicada. 

    char s1[12] = "bat-alloc\0";
    char s2[12] = "bat-free\0";
    char s3[12] = "bat-print\0";
    char s4[12] = "bat-uso\0";
    
    if(compare_string(s1, s)){
        return 1;         
    }

    if(compare_string(s2, s)){
        return 2;         
    }

    if(compare_string(s3, s)){
        return 3;         
    }

    if(compare_string(s4, s)){
        return 4;         
    }

    return 0;
}


int main(){
    int num_iterations; 
    scanf("%d", &num_iterations);


    int *array, command, N;
    char s[12];
    p_bat bat_vector = bat_create();
    
    while(num_iterations > 0){
        scanf("%s", s);
        command = read_input(s);

        if(command == 1){
            scanf("%d", &N);
            array = malloc(N * sizeof(int));
            for(int i=0;i<N;i++){
                scanf("%d", &array[i]);
            }
            bat_alloc(bat_vector, N, array);
            free(array);
            
        } else if (command == 2){
            scanf("%d", &N);
            bat_free(bat_vector, N);
            
        }else if (command == 3){
            scanf("%d", &N);
            bat_print(bat_vector, N);
            
        }else if (command == 4){
            bat_uso(bat_vector);
            
        }
        
        num_iterations--;
    }
        
    // destruindo a memória utilizada.
    bat_free_total(bat_vector);
    
    return 0;
}