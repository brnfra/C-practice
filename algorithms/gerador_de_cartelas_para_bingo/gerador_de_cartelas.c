/*
 * =====================================================================================
 *
 *       Filename:  AtividadeDeEstudo1.c
 *
 *    Description:  Atividade de Estudo 3 Algorítmos e Lógica de Programação II
 *
 *        Version:  1.0
 *        Created:  24/05/2021
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bruno Franco (brnfra), devlabbr@gmail.com
 *   Organization:  
 * =====================================================================================
 */
/*
 * =====================================================================================
 *
 * Para ajudar a construção de uma praça, uma comunidade resolveu criar um bingo 
 * beneficente. Você como membro ativo da comunidade e profissional de tecnologia se 
 * propos a criar um programa em C no qual gere de forma aleatória as cartelas do 
 * bingo.
 * 
 * - Crie uma opção para digitar a quantidade de cartelas a serem criadas
 * - Cada cartela do bingo deve ser armazenada em um vetor de tamanho 10.
 * - Os números da cartela devem ser de 0 a 99
 * - A cartela não pode ter números repetidos, deve ser feita uma conferencia
 *       
 * =====================================================================================
 */
/* PREPROCESSOR DEFINITIONS {{{*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
/* }}} */
/*     Constants   {{{    */

#define EXIT_SUCCESS 0

#define TCARTELA 10
#define INTERVAL 99
#define SAIR 3

/*}}}*/
/*      Procedures {{{*/
/*            Limpa tela{{{  */
void clrscr()
{
    system("@cls||clear");
}
/*}}}*/
/* Limpa carriage return{{{ */
void clear()
{
    while ( getchar() != '\n' );
}
/* }}} */


int checarCartelas(int cartela[]);
void printCartelas(int nCartelas);
void opcoes();

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    int nCartelas = 0, opcao=0, i=0,j=0;
   
    // pause var
    char hangOn[1];
    
    do {
        clrscr();
        opcoes();
     
        /*aux var buff created, get opcao var from stdin*/
           fflush(stdin);
        scanf( "%d" , &opcao);/*validate and check*/
        clear();
     

        switch (opcao)
        {
           /*Case 1- Votar{{{*/
            case 1:
                clrscr();
                //opcao1 Gerar Cartelas;
                 printf("\n%s","OK. Quantas cartelas deseja criar?(Valor inteiro) ");
                 scanf( "%d" , &nCartelas);/*validate and check*/
                 clear();
                 fflush(stdin);
                 printf("\n%s%d%s\n","Escolheu gerar ",nCartelas,".");
                 printCartelas(nCartelas); 
                 opcao = 0;
                 printf("\n\n%s","Pressione Enter para continuar!");
                 scanf("%1[^\n]s", hangOn);
                 clear();
                 fflush(stdin);
                 break;
           /*Case 3 {{{*/
            case 3:
                //opcao3 SAIR;
                /*Encerramento   */
                //msg + pause
                printf("\n%s","Opção SAIR. Obrigado por votar.");
                scanf("%1[^\n]s", hangOn);
                return EXIT_SUCCESS;

                break;

        }
        /*}}}*/

    } while ((opcao != 1) && (opcao != 3));

    return EXIT_SUCCESS;
}


/*      Opções{{{*/
void opcoes() {
    printf("\n%s\n", "Bem vindo ao programa gerador de cartelas para o Bingo Beneficente da comunidade;");
    printf("\n\t%s", "1 - Gerar cartelas");
    printf("\n\t%s", "3 - Para SAIR digite");
    printf("\n\n%s","Escolha: ");
}
/*}}}*/

/* Função para verificar se as cartelas sao válidas {{{*/
int checarCartelas(int cartela[]){
    int i, j;
    for ( i = 0; i < TCARTELA; i++){
        for (j = 1; j < TCARTELA; j++){
            if((i != j) && (cartela[i]==cartela[j]))
                return -1;
        }
        
    }
   
    //return -1 caso cartela haja numero repet
    return 0;
}
/*}}}*/

/*
Procedimento para imprimir cartelas {{{
*/
void printCartelas(int nCartelas){
     int i=0, j=0, check=100;
     int cartela[TCARTELA] ;

    
    //comando utilizado para criação de números aleatório  
    srand( time(NULL) );
    for(j; j < nCartelas; j++){
         //iniciando a cartela
        for (i = 0; i <= TCARTELA; i++) {
            cartela[i] = i;
        }
        //gerando cartela
        for(i=0 ; i < TCARTELA ; i++){
                //imprime um número aleatório de 1 a 99
            cartela[i]=rand() % 99;
            //enquanto o numero gerado for igual a algum gera  
            //novamente até encontrar um diferente
            
            while(checarCartelas(cartela) != 0)
                cartela[i]=rand() % 99;
        
        } 
        printf("\n");
        //imprime
        printf("%s%-2d%s","Cartela[",j+1,"] - ");
        for (i = 0; i < TCARTELA; i++){
            printf(" %-2d ", cartela[i]);
        }

    }
    
    
}
/*
 }}}
 */
