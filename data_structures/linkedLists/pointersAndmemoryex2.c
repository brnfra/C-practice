/* Author brnfra
*/

#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <string.h>
#include <locale.h>


/* Deve-se armazenar o nome de cada aluno, o email e a matrícula. 
Para o armazenamento utilize uma estrutura heterogênea de dados  */

#define tamNome 200
#define tamEmail 200
#define tamRU 16

/*declara struct dentro dessa struct num e list e o ponteiro do 
 tipo struct list para o proximo elemento*/
typedef struct list { 
                     char nomeAluno[tamNome]; //nome do Aluno
                     char email[tamEmail];  //email do Aluno
                     int RU; //RU do Aluno
                     struct list *dir; //aponta para o proximo a direita
                     struct list *esq; //aponta para o anterior a esquerda
                     }t_list; //sinonimo para struct list

//typedef define novo tipo de variável 
                     

void ClearScreen();// função limpa tela é usada no compilador gcc 
void  menu();
void menuProcura(void);
void * insert(t_list * head , char * name, char * email, int RU);
int  search(t_list * head ,int match, int RU);
void * resultado(t_list * aux ,int match, int op);

void main() {
    system("cls");//limpa tela win
    setlocale(LC_ALL, "pt-BR.UTF-8");//acentuação windows 10
            //Definindo o registro
            //cada elemento da lista
        //typedef faz com que naao se precise digitar novamente o nome da struct 
                           //t_list identifica o ponteiro 
   
    t_list *aux;         //ponteiro auxiliar
   
    t_list *head    =NULL;//lista vazia, logo, ponteiro com valor NULL
    //declara variaveis 
    int op, nRU, achou;
    char nome[tamNome], email[tamEmail];
    char num[tamRU];//converter num em nRU

    

//inserção na planilha  que vai receber os dados dos 10 alunos


head = insert( head, "Ronaldo Cruzeiro", "ronaldo@cruzeiro.com.br",2543556  );


head = insert( head, "Rivaldo Santa Cruz", "rivaldo@santacruzfc.com.br", 2547556  );


head = insert( head, "Romario Flamengo", "romario@flamengo.com.br",2540256  );


head = insert( head, "Zico Flamengo", "zico@flamengo.com.br", 2549556  );


head = insert( head, "Bruno  Franco", "bruno@mail.com", 9999999  );


head = insert( head, "Socrates Botafogo", "socrates@botafogo.com.br", 2544656  );


head = insert( head, "Carlos Bala Sport", "cbala@sportrecife.com.br", 2519456  );


head = insert( head, "Cafu Sao Paulo", "cafu@saopaulofc.com.br", 2508456  );


head = insert( head, "Bebeto Vitoria", "bebeto@vitoriafc.com.br", 2537456  );


head = insert( head, "Roberto Carlos USJ", "robertocarlos@usjfc.com.br", 2545286  );





    do{//laço de funcionamento do programa do-while
            achou = 0;

          // menu de opções
            menu(  );
            //limpa tela
            fflush(stdin);//limpa buffer para receber o proximo string
            if (fgets(num, sizeof(num), stdin)) {
              if (1 == sscanf(num, "%d", &op)) {
                    if( op < 1 || op > 3) //filtro
                        printf("\n\n!!!Opção Inválida!!!\n\n\a");
                     }//recebe op
            }
           
           
            if( op == 1 ){
                     system("cls");
                     printf("\n\nDigite os dados a serem inseridos na planilha.\n");
                     printf("O Nome do Aluno: ");
            
                      fflush(stdin);
                     if (fgets(nome, sizeof(nome), stdin)){
                     //armazena o nome da musica a ser  inserida
                      nome[strlen(nome)-1]='\0';//caractere anterior fecha a string e evita que fgets pule uma linha
                     
                  }
            
                     printf("Digite o E-mail do aluno: ");

                    fflush(stdin);
                    if (fgets(email, sizeof(email), stdin)){ //armazena o nome da bnda a ser  inserida
                        email[strlen(email)-1]='\0';}//caractere anterior fecha a string e evita que fgets pule uma linha

                      printf("O número da matrícula (RU): ");
                      fflush(stdin);
                     if (fgets(num, sizeof(num), stdin)) {
                        if (1 == sscanf(num, "%d", &nRU)) {
                         printf("\n");
            
                        head = insert( head, nome, email, nRU );//devido a funcao de imprimir precisa retornar o end de ini
             
                        }
             }//armazena o nRU a ser  inserido
              printf("\nAluno inserido na lista.\n\n");
			        system("pause");
                
            }//end if 1

           
            if(op == 2 ){
                
                 // menuProcura item DA LISTA
              
                //limpa tela
                system("cls");

                    if (head == NULL){
                            //zero para imprimir lista esta vazia
                           resultado(head, achou, 0);

                            

                        }else{

                         
                         menuProcura();
                         

                             if (fgets(num, sizeof(num), stdin)) {
                                    if (1 == sscanf(num, "%d", &nRU)) {//recebe op
                                             printf("\n");
                                             
                                            
                                             }
                                     }//converte string em int
                                //leitura de string do teclado
                                //int  search(t_list * head ,int match, int RU);
                                
                        achou = search(head , achou , nRU);   
                        
                        if(achou == 0)resultado(NULL, achou, 1);
                        //1 para imprimir resultado nao encontrado
                        
                        }
            }//end if 4
            
           

            
          
     }while(op != 3);
     printf("\n\nPrograma Encerrado.\n\n");
}
  

  void  menu(){
    //  system("cls");
    //ClearScreen();
    
             system("cls");
             printf("\n MENU DE OPÇÕES\n");
             printf("\n\n1 - Inserir na lista");
             printf("\n2 - Pesquisar");
             printf("\n3 - Sair");
             printf("\n\nDigite sua opção: ");
            

    
}

void menuProcura(void){
                
                
                printf("\nQual RU do Aluno para pesquisa");
                printf("\nRU :");
               

}



void * insert(t_list * head , char * name, char * email, int RU){
       //typedef faz com que naao se precise digitar novamente o tipo de 
                           //t_list identifica o ponteiro 
    t_list *inicio ; //se lista vazia, entra ponteiro com valor NULL
   
    t_list *aux;         //ponteiro auxiliar, recebe algum valor anterior
    t_list *lef;    //ponteiro auxiliar esquerda
    t_list *rig;     //ponteiro para o direita

    aux = head;  //recebe o head
    
    int op, nRU, achou;
    
    char nome[tamNome], correio[tamEmail];
    memset(nome, '\0', sizeof(nome));
    memset(correio, '\0', sizeof(correio));
    strcpy(nome,name);
    strcpy(correio,email);
   
    nRU = RU;
    
    //declara variaveis 
     
    if(aux == NULL){
                     	//lista vazia e o elemento sera o primeiro e o ultimo
				aux = (t_list *)malloc(sizeof(t_list));//##Aloca memoria para inicio sizeof ## é uma função que retorna o tamanho de um tipo( e nao da variavel) malloc
													   // retorna NULL caso NAO CONSIGA mALOCAR
						  //aponta para preencher a estrutura 
			        	if(aux == NULL){
                            printf("ERRO AO ALOCAR MEMORIA\n");
                            system("pause");
                            return NULL;
                            
                          }else{
                             //sem erro ao alocar memoria
			            	aux->esq = NULL;
                            aux->dir = NULL;
			            	                            
			            	strcpy(aux -> nomeAluno,nome);
                            strcpy(aux -> email,email);
                            aux -> RU = nRU;	    // ponteiro para RU na estrutura list o primeiro e o ultimo
                            
			            	 
                              
                        }//fim if teste malloc
                        
                        return aux;
				
                }else{
                    //se alista contem elementos e o novo elemento sera inserido no inic
                        //aloca nova memoria para o proximo campo TRABALHANDO COM OS ENDEREÇOS
                            //faz-se uso da recursividade
                         
                                     if((nRU) < (aux -> RU)){
                                              
                                            aux -> esq =insert(aux -> esq,  nome ,  correio,  nRU);
  

                                      }else{
                                          
                                            aux -> dir =insert(aux -> dir,  nome ,  correio,  nRU);
                                           
                                      }

                                    
                                
                            }//fim ifelse de teste de nulidade do head
                                
              
                return aux;
              
             
        }//end funcao





int  search(t_list * head ,int match, int RU){


    /*typedef faz com que naao se precise digitar novamente o tipo de 
                           t_list identifica o ponteiro */
    t_list *inicio ; //lista vazia, logo, ponteiro com valor NULL
  
    t_list *aux ;         //ponteiro auxiliar
    t_list *lef;    //ponteiro auxiliar
    t_list *rig;     //ponteiro para o proximo

    aux = head;      //recebe o head
        //declara variaveis locais
    int  nRU, achou;
    

    //inicializa  as variaveis locais
    nRU = RU;
    achou = match;

    
                   
                    if(aux!=NULL && achou == 0){

                       

                        if(aux -> RU == nRU){
                                achou++;
                                resultado( aux , achou , 2);
                                //valor 2 para imprimir valor encontrado pela funcao resultado 
                               
                               
                        }else if(nRU < aux -> RU){
                            if(aux->esq == NULL)return achou;
                            achou = search(aux -> esq, achou , nRU);
                        }else{
                            if(aux->dir == NULL)return achou;
                            achou = search(aux -> dir, achou , nRU);
                        }
                    
                    }

               

                  return achou;

                            
    
}

void * resultado(t_list * aux ,int match, int op){
     
     t_list * auxiliar;
     int operacao, achou;
     operacao = op;
     achou = match;
     auxiliar = aux;
     
     switch (operacao){
         
     
         case 0:
         //lista vazia
            printf("\n|########################################      RESULTADO      ########################################|\n\n");
            printf("\n %-43s%-45s%s","NOME","E-mail","Matrícula(RU)\n");
            printf(" Não há ítem na lista\n");
            printf("\n\n");
            printf("\n|########################################      RESULTADO      ########################################|\n");
            system("pause");
            
         break;
         
         case 1:
         //objeto nao encontrado
            printf("\n|########################################      RESULTADO      ########################################|\n\n");
            printf("\n %-43s%-45s%s","NOME","E-mail","Matrícula(RU)\n");
            printf("\n Matrícula(RU) não foi encontrada !!!\n");
            printf("\n\n");
            printf("\n|########################################      RESULTADO      ########################################|\n"); 
            system("pause");
            
         break;
         
         case 2:
         //imprime resultado encontrado
            printf("\n|########################################      RESULTADO      ########################################|\n\n");
            printf(" %-43s%-45s%s","NOME","E-mail","Matrícula(RU)\n");
            printf("\n %-43s%-45s%d\n",auxiliar->nomeAluno, auxiliar->email, auxiliar -> RU);
            printf("\n|########################################      RESULTADO      ########################################|\n");
            printf("\n\nEncontrada %d ocorrência.\n", achou);
            system("pause");
             
         break;
         
         
         }
     
    
}

void ClearScreen(){
    int n;
    for (n = 0; n < 5; n++)
      printf( "\n\n\n\n" );
    }

   
