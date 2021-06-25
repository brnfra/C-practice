#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

void BubbleSort(int vet[]);

int main(){

    int vet[TAMANHOVETOR] = {0};
    int buscado, achou; //busca
    srand(time(NULL));// gera a semente aleatoria

//INSERÇÃO DE DADOS
    for(int i = 0; i < TAMANHOVETOR ; i++)
        vet[i] =rand () % 100; //gera valores aleatorios

    printf("VETOR NAO ORDENADO: \n");
    for(int i = 0; i < TAMANHOVETOR; i++)
        printf("%d\n", vet[i]);

    printf("Selecione o valor para buscar: \n");
    scanf_s("%d", &buscado);//BUSCA

    BubbleSort(vet);
   
    printf("VETOR ORDENADO: \n");
    for(int i = 0; i < TAMANHOVETOR; i++)
        printf("%d\n", vet[i]);

        
    
    return 0;
}

void BubbleSort(int vet[]){

int aux;
    for(int n = 1; n < TAMANHOVETOR ; n++){
        for( int i = 0; i < TAMANHOVETOR ; i++){

            if(vet[i] > vet[i+1]){// DECRESCENTE "<"

                aux =vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            } //CRESCENTE

        }

    }

}
