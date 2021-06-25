
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHOVETOR 10

int particao(int vet[], int p , int u);
void quickSort(int vet[], int p, int u);


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
    scanf("%d", &buscado);//BUSCA

      
    QuickSort(vet, 0, TAMANHOVETOR -1);

    printf("VETOR ORDENADO: \n");
    for(int i = 0; i < TAMANHOVETOR; i++)
        printf("%d\n", vet[i]);

        
    system("pause");
    return 0;
}


//recursiva
void quickSort(int vet[], int p, int u){

    int m; //PIVO
     if( p < u){
         m = particao(vet,p,u);
         QuickSort(vet, p , m);//esquerdo
         QuickSort(vet, m+1 , u);//direito

     }

}

int particao(int vet[], int p , int u){
// calcula PIVO
int pivo, pivo_pos, i, j;
pivo_pos = (p+u)/2;
pivo = vet[pivo_pos];

i = p-1;// sempre um valor a menos
j= u+1; //sempre um valor a mais

    while(i<j){
        //enquanto as varrediuras esquerdas e direitas nao se encontrarem
        do{//TESTA LADO DIREITO
            j--;
        }while(vet[j] > pivo);

        do{//TESTA LADO ESQUERDO
            i++;
        }while(vet[i] > pivo);

        if(i < j)
        troca(vet, i , j);

    }

    return j;
}

