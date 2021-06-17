/*
 * =====================================================================================
 *
 *       Filename:  AtividadeDeEstudo1EDII.c
 *
 *    Description:  Atividade de Estudo 1 da disciplina de Estrutura de Dados II
 *                  Apresentação de árvore binária estática de tamanho
 *                  pré-definido, indice par a direita e impar a esquerda
 *
 *        Version:  1.0
 *        Created:  25/05/2021 23:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Bruno Franco (https://github.com/brnfra), devlabbr@gmail.com
 *   Organization:   *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

/*     Constants  {{{ */
#define EXIT_SUCCESS 0
#define tamanho 100
#define D 2
#define E 1
#define R -1
/*     }}}     */

/*struct name*/ 
struct noh 
{
    char data;
    int from;
    int left;
    int right;

}tree[tamanho];
/*      Procedures*/
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

//  global_var
int opc = -1, temp = 0, pos = 0, indice = 0, altura = 0, elementos=0;
char pai, noh;
struct noh tree[tamanho];

void print_subtree(int noh ){
    int esq=0,dir=0;

     esq = 2*noh + 1;
     dir = 2*noh + 2;    
      if(noh == 0){
            printf("  (raiz)  \n");
            printf("    %c    \n",tree[noh].data); 
            printf("  /  \\   \n"); 
            printf("%c      %c\f",tree[esq].data,tree[dir].data); 
      }else{
          if(noh % 2 == 0){
          
            printf("    %c   \n",tree[((noh-2)/2)].data);
            printf("    |    \n");
            printf("    %c   \n",tree[noh].data); 
            printf("  /  \\  \n"); 
            printf("%c      %c\v",tree[esq].data,tree[dir].data); 
          }else{
            printf("    %c   \n",tree[((noh-1)/2)].data);
            printf("    |    \n");
            printf("    %c   \n",tree[noh].data); 
            printf("  /  \\  \n"); 
            printf("%c      %c\v",tree[esq].data,tree[dir].data); 

          }
      }

  }

//proc serve print_tree
void tab(int espaco){
      int j=0;
      for(j=espaco;j>0;j--){
            printf("%s"," ");
      }
}
//proc serve print_tree
void elementos_noh(int digitos, int esq, int dir){
    int j = 0;
    if(tree[esq].data != '\0' || tree[dir].data != '\0' ){
         
         // espaço entre elementos do mesmo pai 
         printf("|");
        for(j=digitos;j>0;j--){
             printf("%s","-");                        
        }

    }else{
         //debug
        printf("_");
        
        for(j=digitos;j>0;j--){
            printf("%s"," ");                        
        }
    }
}


void print_tree(){
    
    int i=0,j=0,aux=0,k=2,l=0,esq=0, dir=0;

    //ajuste para posicao da base da arvore
    int base = 0;
    int espaco = 0;

    if(indice%2!=0){
        indice++;
        base = (indice)* 4;
        espaco = (base/2);  
    }else{
        base = indice* 4;
        espaco = (base/2);
    }


    
   printf("\n%s\n","Mapa da Árvore e respectivos nós.");
      for(i;i<=indice;i++){
          //base da piramide é o maior indice
          //problema qnd maior indice não for da extrema direita

          //raiz imprime apenas uma vez
          if(i==0){

              tab(2*espaco/k-3);
              printf("%s\f","(root)");
              printf("\b\b\b%c\f",tree[0].data);
              printf("\b%s","|");

              printf("\n");

          }else{
            //inicio da linha, calculo dos espaços!
            tab(espaco/k);

           //evita impressao apos ultimo no impresso
            if(dir<=indice){

                //imprime indicacao de nohs
                for(aux=k; aux >0 ; aux=aux-2){

                    // imprime elemento a esquerda
                        elementos_noh((2*espaco)/k, esq, dir);
                        printf("|");
                        tab(2*espaco/k);

                }

                //pula apos a impressao das indicacoes
                printf("\n");

                //inicio da linha, novamente, apos a impressao
                tab(espaco/k);

                //imprime elementos por altura (problema qnd l é impar)
                for(aux=k; aux > 0  ; aux=aux-2){

                        esq = 2*l + 1;
                        dir = 2*l + 2;

                        // imprime elemento a esquerda
                        if(tree[esq].data == '\0')
                            printf("%-s"," ");
                        else
                            printf("%c",tree[esq].data);

                        // espaço entre elementos do mesmo pai
                        tab(2*espaco/k);

                        // imprime a direita
                        if(tree[dir].data == '\0')
                                printf("%-s"," ");
                        else
                            printf("%-c",tree[dir].data);

                        // espaço entre elementos de pais diferentes
                        tab(2*espaco/k);
                         //## contador L esq e dir dependem de l
                         l++;


                }

                //pula apos impressao dos elementos
                printf("\n");

                //inicio da linha, novamente, apos a impressao
                tab(espaco/k);

                //imprime indicação de noh apos impressao dos nos
                for(aux=k; aux > 0  ; aux=aux-2){



                    if(dir < indice && esq <= indice){
                    // imprime elemento a esquerda
                        if(tree[esq].data == '\0')
                            printf("%-s"," ");
                        else
                            printf("%s","|");

                          // espaço entre elementos do mesmo pai
                             tab(2*espaco/k);

                        // imprime a direita
                        if(tree[dir].data == '\0')
                                printf("%-s"," ");
                        else
                            printf("%-s","|");

                         // espaço entre elementos de pais diferentes
                         tab(2*espaco/k);
                    }


                }

                printf("\n");

            }

              printf("\n");
              k*=2;
              //encurta loop
            if( k > indice )
                    break;

          }


      }

   printf("\n%s\n","Árvore atual indexada.");
    if(indice < tamanho){
        //1- half
        for (int i = 0; i<=indice/2; i++){
             printf("%s%3d%-2s","|" ,i,"|");

            }
        printf("\n");
        for (int i = 0; i<=indice/2; i++){

            if(tree[i].data == '\0' ){
              printf("%s%3c%-2s","|" ,'-',"|");
            }else{
              printf("%s%3c%-2s","|" ,tree[i].data,"|");
            }

        }
        printf("\n\n");
        //2- half
        for (int i = indice/2+1; i<=indice; i++){
             printf("%s%3d%-2s","|" ,i,"|");

            }
        printf("\n");
        for (int i = indice/2+1; i<=indice; i++){

            if(tree[i].data == '\0' ){
              printf("%s%3c%-2s","|" ,'-',"|");
            }else{
              printf("%s%3c%-2s","|" ,tree[i].data,"|");
            }

        }


    }else{
        printf("\n%s\n","Arvore não pode ser impressa. Indice é maior que o tamanho da arvore.");
    }
    printf("\n");
  if(indice%2!=0)
        indice--;

}


// procurando o noh - retorna o indice do elemento
int tree_search( char dado){
    for (int i = 0; i<tamanho ; i++){
            if (tree[i].data == dado){
                return i;
            }
        }
    
    return -100;
    
}
//indice do pai, conteudo do noh e posicao
void tree_insert( int from, char dado , int pos){
    int ind = 0;

        switch (pos) {
            case E:
                //impar
                ind = 2*from + 1;

                //dados
                tree[ind].data = dado;
                tree[ind].from = from;
                //folha
                tree[ind].left = -1;
                tree[ind].right = -1;
                if(indice < ind){
                    indice=ind;
                }
                elementos++;
                
                break;

            case D:
                ///par
                ind = 2*from + 2;
                tree[ind].data = dado;
                tree[ind].from = from;
                //folha
                tree[ind].left = -1;
                tree[ind].right = -1;
                if(indice < ind){
                    indice=ind;
                }
                elementos++;
               
                break;
            
            case R:
                ///par
                ind = from;
                tree[ind].data = dado;
                tree[ind].from = R;
                //folha
                tree[ind].left = -1;
                tree[ind].right = -1;
                indice++;
                elementos++;
                break;


        }				/* -----  end switch  ----- */
}

/*      Opções{{{*/
void menu_mostrar(int indice){
    clrscr();
    
    printf("\n%s\n", "Bem vindo ao programa de implementação de arvore binária ");
    printf("\n\t%s", "1 - Para INSERIR um  nó na árvore");
    printf("\n\t%s", "2 - Para PESQUISAR nó na árvore");
    printf("\n\t%s", "3 - Para SAIR digite");

}

/*}}}*/


int main(int argc, char *argv[]) {
    setlocale(LC_ALL,"pt_BR.UTF-8");

    // var locais
    int dir = 0, esq = 0;
    //pause var     
    char hangOn[1];

    do{
    menu_mostrar(indice);

    printf("\n%s\n\n","Arvore atual:");
    print_tree();
    //test_print(3);
    printf("\n\n%s","Escolha-");
    scanf("%d", &opc);
    fflush(stdin);
    clear();

    switch (opc){
        case 1:
            if(elementos > 0){
                printf("\nDigite a posição do nó na arvore (Esq=%d/Dir=%d): ", E,D);
                scanf("%d",&pos);
                fflush(stdin);
                clear();

            }else{
                pos=R;
            }
            if(pos == E || pos == D){
                printf("\nDigite o valor do PAI: ");
                scanf("%c",&pai);
                fflush(stdin);
                clear();
            //retorna o indice do pai
                temp = tree_search(pai);
                if(temp == -100){
                    printf("\nNão encontrado\n"); 
                    scanf("%1[^\n]s", hangOn);
                    fflush(stdin);
                    clear();


                    break;
                }
            }else{
                //raiz
                
                indice = 0;
                temp = indice;
            }
            
            printf("\nDigite o conteudo do NO: ");
            scanf("%c",&noh);
            fflush(stdin);
            clear();

            //insere eleento na arvore
            tree_insert(temp,noh,pos);
            break;
        case 2:
            printf("\nDigite o valor do NO procurado: ");
            scanf("%c",&noh);
            fflush(stdin);
            clear();
            temp = tree_search(noh);
                if(temp == -100){
                    printf("\nNão encontrado\n"); 
                    scanf("%1[^\n]s", hangOn);
                    fflush(stdin);
                    clear();
                    break;
                }
  
            esq = temp*2 + 1;
            dir = temp*2 + 2;    
                    
            printf("No pai %c\nFilho a Esquerda: %c\nFilho a Direita: %c\n\n", tree[temp].data, tree[esq].data, tree[dir].data);
            print_subtree(temp); 
            //pause
            printf("\n\n%s","Pressione Enter para voltar ao menu.");
            scanf("%1[^\n]s", hangOn);

        break;
        }
    }while (opc!=3);

    //pause
    printf("\n\n%s","Obrigado por usar o programa.");

            return EXIT_SUCCESS;
    }

