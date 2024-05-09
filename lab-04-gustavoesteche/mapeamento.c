#include <stdio.h>
#include <stdlib.h>


void aloc_matrix(int lc, int ***matrix){
    // aloca a matriz quadrada de tamanho lc

    (*matrix) = malloc(lc * sizeof(int *));
    for(int i=0;i<lc;i++){
        (*matrix)[i] = malloc(lc * sizeof(int));
    }
}

void scan_int_matrix(int **matrix, int lc){
    // scaneia a matriz de inteiros

    for(int i=0;i<lc;i++){
        for(int j=0;j<lc;j++){
            scanf("%d", &matrix[i][j]);
        }
    }
}

void print_matrix(int **matrix, int lc){
    // printa a matriz de inteiros

    for(int i=0;i<lc;i++){
        for(int j=0;j<lc;j++){
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int soma_matrix(int **matrix, int row_i, int row_f, int col_i, int col_f){
    /* soma um quadrante da matriz definido pelas linhas, colunas iniciais e
    linhas e colunas finais.
    */  

    int sum=0;
    for(int i=row_i;i<=row_f;i++){
        for(int j=col_i;j<=col_f;j++){
            sum += matrix[i][j];
        }
    }
    return sum;
}


void maior_soma_quadrante(int **matrix, int lc, int *row, int *col){
    // Escolhe a soma do maior quadrante da matriz

    int sum = -2147483648; // escolhe o mínimo inteiro possível 
    for(int i=0;i<=1;i++){
        for(int j=0;j<=1;j++){
            int x = soma_matrix(matrix, i, lc-2+i, j, lc-2+j);
            if(sum < x){
                sum = x;
                *row = i;
                *col = j;
            }
        }
    }
}


void free_matrix(int **matrix, int lc){
    // libera a memória da matriz  

    for(int i=0;i<lc;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void copy_matrix(int **matrix_original,int **matrix_copy, int lc){
    // copia os elementos da matrix original para a matriz cópia 

    for(int i=0;i<lc;i++){
        for(int j=0;j<lc;j++){
            matrix_copy[i][j] = matrix_original[i][j];
        }
    }
}

void change_element(int **matrix, int *alt_value){  
    /* altera um elemento específico da matriz com
    base no vetor alt_value.
    */  

    matrix[alt_value[0]][alt_value[1]] = alt_value[2];
}

void reduce_matrix(int ***matrix, int row_i, int col_i, int lc){ 
    /* reduz a matrix de tamanho lc para lc-1 com base
    na coluna e linha inicial
    */ 

    int **new_matrix;
    aloc_matrix(lc-1, &new_matrix);
    
    
    int l = 0, k = 0;
    
    for(int i=row_i;i<=lc-2+row_i;i++){
        for(int j=col_i;j<=lc-2+col_i;j++){
            new_matrix[l][k] = (*matrix)[i][j];
            k++;
        }
        l++;
        k = 0;
    }

    free_matrix((*matrix), lc);
    aloc_matrix(lc-1, matrix);
    copy_matrix(new_matrix, (*matrix), lc-1);
    free_matrix(new_matrix, lc-1);
}

int main(){
    int lc;
    scanf("%d", &lc);

    int **matrix_data;
    aloc_matrix(lc, &matrix_data);
    scan_int_matrix(matrix_data, lc);

    int **emergency_matrix;
    aloc_matrix(lc, &emergency_matrix);
    copy_matrix(matrix_data, emergency_matrix, lc);

    printf("Quadras:\n");
    print_matrix(matrix_data, lc);

    int epoch = lc;
    int alt = 1, alt_val[3];

    int row_,col_;
    int *row =&row_ , *col=&col_;

    // inicia o loop das alterações. 
    do{
        
        maior_soma_quadrante(emergency_matrix, epoch, row, col);
        reduce_matrix(&emergency_matrix, *row, *col, epoch);
        epoch--;
        printf("Conjuntos que precisam de atenção:\n");
        print_matrix(emergency_matrix, epoch);
        

        if(epoch <= 1){
            break;
        }

        scanf("%d", &alt);
        if(alt == 1){
            for(int i=0;i<3;i++){
                scanf("%d", &alt_val[i]);
            }
            change_element(emergency_matrix, alt_val);
        }

        if(alt == 0){
            break;
        }
        
    }while(epoch > 1);


    free_matrix(matrix_data, lc);
    free_matrix(emergency_matrix, epoch);
    return 0;
}