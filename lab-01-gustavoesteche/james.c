#include <stdio.h>


void maior_sequencia(int vetor_vendas[], int n, int data[2]){
    // função que busca as sequências mais ocorridas e qual era o seu valor

    int maior_seq = 0;
    int maior_valor = 0;
    int atual_seq = 1;
    int ultimo_visto = vetor_vendas[0]; 

    for(int i=1;i<n;i++){
        if(ultimo_visto == vetor_vendas[i]){
            atual_seq++;
        }else{
            if(atual_seq > maior_seq){
                maior_seq = atual_seq;
                maior_valor = ultimo_visto;
            }
            ultimo_visto = vetor_vendas[i];
            atual_seq = 1;
        }
    }
    
    if(atual_seq > maior_seq){ 
        maior_seq = atual_seq;
        maior_valor = ultimo_visto;
    }

    data[0] = maior_seq;
    data[1] = maior_valor;   
}

int main(){
    int n; 
    scanf("%d", &n);

    // Armazena a os dados dos valores das vendas
    int vetor_vendas[1000];
    for(int i=0;i<n;i++){
        scanf("%d", &vetor_vendas[i]);
    }

    // Calcula a ocorrência dos valores de 5, 7, 10 
    int vetor_quantidade[3] = {0,0,0};
    for(int i=0;i<n;i++){
        if(vetor_vendas[i] == 5){
            vetor_quantidade[0]++;
        }else if(vetor_vendas[i] == 7){
            vetor_quantidade[1]++;
        }else{
            vetor_quantidade[2]++;
        }
    } 

    /*o primeiro termo do data é a maior sequência, o segundo é
    o valor da sequência.
    */  
    int data[2] = {0,0};

    maior_sequencia(vetor_vendas, n, data);

    // Gerando a saída desejada
    printf("James vendeu %d saladas de 5 reais, %d de 7 reais e %d de 10 reais\n", vetor_quantidade[0], 
                                                        vetor_quantidade[1], vetor_quantidade[2]);
    printf("James vendeu %d saladas de %d reais consecutivamente", data[0], data[1]);

    return 0;
}