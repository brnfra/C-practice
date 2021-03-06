#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <locale.h>
//#include <conio.h>
//#include <iostream>

typedef struct list { //declara struct dentro dessa struct num e list e o ponteiro do tipo struct list para o proximo elemento
                     int num;
                     struct list *prox; 
                     }t_list; //sinonimo para struct list

void ClearScreen();
void menu(void);
void * inicInsert(t_list * inicio , int itens);
void * midInsert(t_list * inicio , int itens);
void * lastInsert(t_list * inicio , int itens);
void  printList(t_list * inicio, t_list * proximo );
void * apagaItem(t_list * inicio , int itens);
void * esvaziaLista(t_list * head , int itens);

void main() {
    setlocale(LC_ALL, "");
            //Definindo o registro
            //cada elemento da lista
        //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio = NULL ; //lista vazia, logo, ponteiro com valor NULL
    t_list *fim  ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux;         //ponteiro auxiliar
    t_list *anterior;    //ponteiro auxiliar
    t_list *proximo;     //ponteiro para o proximo
    t_list *head = NULL;
    //declara variaveis 
    int op, item, achou;

    do{
            

          // menu de opções
          menu();
            //limpa tela
            
            scanf_s("%d", &op);//escolhe a opção

            if( op < 1 || op > 7){ //filtro
                printf("\n\n!!!Opção Inválida!!!\n\n\a");}

           
            if( op == 1 ){
            printf("\n\nDigite o valor a ser inserido no inicio da lista.\n");
            printf("O valor escolhido: ");
            scanf_s("%d", &item);//armazena o item a ser  inserido
            printf("\n");
            
            head = inicInsert(  head , item);//devido a funcao de imprimir precisa retornar o end de ini
             
                
            }//end if 1



            if(op == 2 ){
           //printf("\n2 - Inserir no fim da lista");
             printf("\n\nDigite o valor a ser inserido no fim da lista.\n");
            printf("O valor escolhido: ");
            scanf_s("%d", &item);//armazena o item a ser  inserido
            printf("\n");
              
            head = lastInsert( head ,  item);

            }/*end if 2*/

             if(op == 3 ){

            //printf("\n3 - Inserir no meio da lista");
            printf("\n\nDigite o valor a ser inserido no meio da lista.\n");
            printf("O valor escolhido: ");
            scanf_s("%d", &item);//armazena o item a ser  inserido
            printf("\n");
            midInsert( head ,  item);

            }//end if 3

            
            if(op == 4 ){

                //deletar item
                 printf("\n\nDigite o elemento a ser apagado =>:");
                 scanf_s("%d",&item); 
                 printf("\n");
                 head = apagaItem(head , item);

            }//end if 4
            
            if(op == 5 ){
                //Esvaziar a lista
                  
               head = esvaziaLista( head , item);

            }//end if 5

            if(op == 6 ){

                if(head == NULL){
                 printf("\n\nA Lista está Vazia\n\n");
                
                 }  
                 else{
                     printList( head , head->prox); 
                 }
                
            }//end if 6
          
     }while(op != 7);
     printf("\n\nPrograma Encerrado.\n\n");
}
  

  void menu(void){
    
    printf("\n MENU DE OPCOES \n");
    printf("\n1 - Inserir no início da lista");
    printf("\n2 - Inserir no fim da lista");
    printf("\n3 - Inserir no meio da lista");
    printf("\n4 - Remover da lista");
    printf("\n5 - Esvaziar a lista");
    printf("\n6 - Mostrar toda a lista");
    printf("\n7 - Sair");
    printf("\nDigite sua opcao: ");
}

void * inicInsert(t_list * head , int itens){
       //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    //t_list *aux;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
    int item;
    item = itens;
    
    //declara variaveis 
     
    if(inicio == NULL){
                     	//lista vazia e o elemento sera o primeiro e o ultimo
				inicio = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
				if(inicio == NULL){
                    printf("ERRO AO ALOCAR MEMORIA\n");
                }else{

				before = NULL;
                inicio -> num = item;	    // ponteiro para num na estrutura list o primeiro e o ultimo
				end = inicio ;
                end->prox = NULL;
                 //inicio = head ;
                }//fim if teste malloc
                printf("Numero inserido foi o primeiro da lista\n\n");
				return inicio;
				
                }else{
                    //se alista contem elementos e o novo elemento sera inserido no inic
                        //aloca nova memoria para o proximo campo TRABALHANDO COM OS ENDEREÇOS
                    
                before = inicio;
                                 // NOVO HEAD
                head = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						                                 //aponta para preencher a estrutura 
			               if(head == NULL){
                               printf("ERRO AO ALOCAR  MEMORIA NOVAMENTE\n");
                                  }else{
			                	
                                next = before;
				                 head -> num = item;	
			                     head -> prox = before;}//fim de if teste malloc
                                inicio = head; 
                                inicio->prox = before;  
                                }//fim ifelse de teste de nulidade do head
                printf("Numero inserido no inicio da lista\n\n");
                return inicio;
                //printf("Teste O valor escolhido inicio: %d", inicio -> num);
}//end funcao

void  * midInsert(t_list * head , int itens){

        /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
        //declara variaveis locais
    int op, numero, achou, meio, n, item;
    item = itens;
    meio = 0;
    n = 0;
        //Reserva o endereço de espaço de memoria para o novo elemento da lista
					   new = (t_list*) malloc(sizeof(t_list));
					   

						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim, ultimo e central
							head = (t_list*) malloc(sizeof(t_list));
                            if(head == NULL){
                             printf("ERRO AO ALOCAR MEMORIA\n");
                                }else{
							head->num = item;
							next = head;
							next->prox = NULL;
                            }//checa a allocaçao
							printf("Numero inserido foi o primeiro da lista\n\n");
                            return head;

						}else{
							   //a lista ja contem elementos e sera inserido no meio da lista
							    new->num= item;

                            //   percorre todos os ponteiros ate achar o ultimo
							     next = head;
							   while(next->prox != NULL){
							     next = next->prox ;
								n++;//conta itens
							   }//end while
							   
							    // quando achar  o ultimo a variavel n recebe o valor do numero de ítens
							   meio = (int)(n / 2);

							   //   percorre todos os ponteiros ate achar o meio
							    next = head;
							    for(int i = 0; i < meio ; i++){
							  	 next = next->prox ;
								//printf("dentro %d\n", meio);
							    }
							  before = next;
							  //aux(novo) aponta para o ponteiro que o antigo apontava
							  new->prox = next->prox;
							  
							  //proximo recebe o ponteiro para onde apontava
							  //						proximo = proximo -> prox;
							  //recebe o endereço do novo
							  before->prox = new;
							  
						}
					
					
			printf("Numero inserido no meio da lista\n\n");
            return head;


}

void * lastInsert(t_list * head , int itens){

            /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */

    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
    int item;
    item = itens;

                   //se inicio for NULL aloque novo espaço
						if(inicio == NULL){
							//lista estava vazia e o elemento sera o prim e o ultimo
							head = (t_list*) malloc(sizeof(t_list));
                            if(head == NULL){
                                printf("ERRO AO ALOCAR MEMORIA\n");
                                }else{
							    head->num= item;
							    next = head;
							    next->prox = NULL;
                                }//fim if filtro
                                printf("Numero inserido foi o primeiro da lista\n\n");
                                return head;
							
						}else{
							   //a lista ja contem elementos e sera inserido no fim da lista
                               new = (t_list*) malloc(sizeof(t_list));
							    new->num = item;

							   next = head;

							   while(next->prox != NULL){
							    //   percorre todos os ponteiros ate achar o ultimo
							    next = next->prox ;
								
						
							   }//end while
							   
							   // quando achar  o ultimo a variavel auxiliar recebe esse ponteiro
							   next->prox = new;
							   new->prox = NULL;
                               
						}//end if and else
						printf("Numero inserido no fim da lista\n\n");
                        return head;
			}/*end lastInsert*/


void * apagaItem(t_list * head , int itens){


    /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim contera o ultimo elemento da lista
    t_list *aux = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
        //declara variaveis locais
    int op, numero, achou, meio, n;
    numero = itens;
    meio = 0;
    n = 0;
                 next = head;
				 while(next->prox != NULL){
				next = next->prox ;
				
				}//end while
                end = next->prox;//obtenho o ultimo ponteiro

               if(inicio == NULL){
                    printf("\n\nA lista está vazia!\n\n");
                    //lista vazia 
                   
                }else{
                    // a lista contem elementos e o elemento a ser removido deve ser digitado
                 
                 //todas as ocorrencias da lisa, iguais ao numero digitado serao removidas
                 aux = inicio;
                 before = NULL;
                 achou = 0;
                 while (aux != NULL){
                     if(aux->num == numero){
                         //numero digitado encontrado
                         achou = achou +1;
                         if(aux == inicio){
                             //numero a ser apagado é o primeiro
                             inicio = aux->prox;
                             free(aux);
                             aux=inicio;
                         }else if(aux == end){
                           // o numeor a ser removido é o ultimo da lista     
                            before->prox =NULL;
                            end =  before;
                            free(aux);
                            aux =NULL;
                         }else{
                             //o numero a ser apagado esta no meio da lista
                            before->prox = aux->prox;
                            free(aux);
                            aux =before->prox;
                         }

                       

                     }else{
                         before = aux;
                         aux =aux->prox;
                     }
                 }
                if(achou==0){
                    printf("\nNumero nao encontrado\n");
                    }else if(achou == 1){
                        printf("\nelemento apagado 1 vez\n");
                    }else{
                        printf("\n elemento apagado %d vezes\n", achou);
                    }
                }
                return head;
}

void * esvaziaLista(t_list * head , int itens){

     /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *aux = NULL;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    inicio = head;
     if(inicio == NULL){
                    printf("\n\nA Lista já está Vazia\n\n");
                    //lista vazia 
                }else{
                    //a lista será esvaziada
                    aux = inicio;
                    while(aux!= NULL){
                        inicio = inicio ->prox;
                        free(aux);
                        aux =inicio;
                    }
                    printf("\n\nLista Esvaziada\n\n");
                }
        return inicio;
}

void  printList(t_list * inicio, t_list * proximo ){

    t_list *head = NULL; //lista vazia, logo, ponteiro com valor NULL
    t_list *end = NULL ; //ponteiro fim conntera o ultimo elemento da lista
    t_list *new;         //ponteiro auxiliar
    t_list *before;    //ponteiro auxiliar
    t_list *next;     //ponteiro para o proximo
    
    ClearScreen();//limpa texto do terminal

        next = inicio;
        printf("\n\n###########     LISTA     ##########\n\n");
        while(next != NULL){
        printf("| %d | -> ", next->num);
        next = next->prox;
           
        }//end while
        printf("NULL\n\n");
        
}
void ClearScreen(){
    int n;
    for (n = 0; n < 5; n++)
      printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

 