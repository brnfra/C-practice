/* 
    Author brnfra 
*/

#include <stdio.h>//printf
#include <stdlib.h>//malloc
#include <string.h>
#include <locale.h>

#define tamNome 200
#define tamNUM 16
#define tamRA 16

void clrscr()
{
    system("@cls||clear");
}
	

typedef struct cadastro {
	char nomeAluno[tamNome]; //nome do Aluno
	int RA; //registro do Aluno

}l_cadastro; //sinonimo para stRAct list

//ITERATIVA
int interativa(int inicial, int final);

//RECURSIVA
int recursiva(int contador, int inicial, int final);

void exercicio1();
void exercicio2();
void exercicio3();
void exercicio4();
void exercicio5();

int main(){
	setlocale(LC_ALL, "pt-BR.UTF-8");//acentuação windows 10
	int op;
	char num[tamNUM];

	do
	{	
		op = -1;
		 clrscr();
		printf("\n\t\tMENU");
		printf("\n\nDigite o numero de 1 a 5 para escolher o numero do exercício. ");
		printf("\nDigite o numero 0 para encerrar e sair. ");
		printf("\n\nEscolha o exercicio: ");
		fflush(stdin);
		if (fgets(num, sizeof(num), stdin)) {
			if (1 == scanf(num, "%d", &op)) {
				printf("\n");//recebe o numero da opção
			}
		}
		printf("\n");
		
		switch (op)
		{
		case 1:
			exercicio1();
			break;
		case 2:
			exercicio2();
			break;
		case 3:
			exercicio3();
			break;
		case 4:
			exercicio4();
			break;
		case 5:
			exercicio5();
			
			break;
		default:
			
			break;
		}

	} while (op != 0);

    system("pause");
    return 0;
}


void exercicio1() {
	int inteiro, *N;
	float real, *R;
	char nome, *P;
	
	N = &inteiro;
	R = &real;
	P = &nome;

	/*
	Exercício 1:

	Escreva um algoritmo em linguagem C com as seguintes instruções:
	1. Declare três variáveis (inteiro, real e char);
	2. Declare três ponteiros;
	3. Associe as variáveis aos ponteiros;
	4. Modifique os valores de cada variável indiretamente usando os ponteiros
 associados. Para armazenar os valores nas variáveis, armazene na variável
 char a primeira letra do seu nome, na variável inteira os dois últimos dígitos
 do seu RA e na variável real os 4 últimos dígitos do seu RA, sendo os 2
 últimos os valores com virgula;
	5. Imprima na tela os valores das variáveis antes e após a modificação.
*/
	//inicializando as variaveis
	inteiro = 111111;
	real = 99.99;

	nome = 'C';

	//imprimindo valores iniciais
	printf("\nImprimindo valores ANTES de modificá-los");
	printf("\n\nNumero inteiro = %d", inteiro); //imprime conteudo para onde aponta R
	printf("\nNumero real = %2.2f", real);
	printf("\nNome = %c", nome);
	printf("\n\n");

	*N = 62;
	*R = 53.62;
	*P = 'B';

	//imprimindo valores finais apos modificação
	printf("\nImprimindo valores DEPOIS de modificá-los");
	printf("\n\nNumero inteiro = %d", *N); //imprime conteudo para onde aponta R
	printf("\nNumero real = %2.2f", *R);
	printf("\nNome = %c", *P);
	printf("\n\n");
	system("pause");
}

void exercicio2() {
	/*
	Exercício 2:

	Escreva um algoritmo em LINGUAGEM C que armazene na memória o seu RA e o
valor 1234567, ambos digitados pelo usuário na tela.
	Em seguida, imprima na tela ambos RA usando ponteiros. O algoritmo também vai
ter que comparar os dois RA usando ponteiros e imprimir na tela qual é o maior.

*/

	int RA, numero, *R, *N;
	
	numero = 1234567;
	char num[tamRA];
	RA = 0;
	R = &RA;
	N = &numero;

	printf("O Numero do  RA1: ");
	fflush(stdin);
	if (fgets(num, sizeof(num), stdin)) {
		if (1 == scanf(num, "%d", &RA)) {
			//recebe RA
		}
	}
	printf("O Numero do  RA2: ");
	fflush(stdin);
	if (fgets(num, sizeof(num), stdin)) {
		if (1 == scanf(num, "%d", &numero)) {
			//recebe RA
		}
	}
	printf("\n\tImprimindo");
	printf("\n\nImprimindo RA1 = %d", *R);
	printf("\nImprimindo RA2 = %d", *N); //imprime conteudo para onde aponta R

	if (*R > *N)
	{
		printf("\n\nRA1 é maior");
	}
	else
	{
		printf("\n\nRA2 é maior");
	}

	printf("\n\n");
	system("pause");
}

void exercicio3() {
	// variaveis locais
	int nRA;
	char nome[tamNome];
	char num[tamRA];
	l_cadastro aluno;
	nRA = 0;
	/*
		Exercício 3:

		Faça um algoritmo em linguagem C com as seguintes funcionalidades:

		•  Receba um registro, com dois campos, como dados de entrada.
		•  O primeiro campo é um vetor que vai armazenar o nome do aluno.
		•  O segundo campo é uma variável do tipo inteiro que vai armazenar o RA do
		aluno.
		•  Imprime na tela os dados armazenados na estRAtura.


	*/
		printf("\n\tENTRADAS");
		printf("\n\nO Nome do Aluno: ");

		fflush(stdin);//limpa buffer
		if (fgets(nome, sizeof(nome), stdin)) {
			//armazena o nome da musica a ser  inserida
			nome[strlen(nome) - 1] = '\0';/*caractere anterior fecha a string e evita que fgets
				  pule uma linha*/
		}


		printf("O Numero do RA: ");
		fflush(stdin);
		if (fgets(num, sizeof(num), stdin)) {
			if (1 == scanf(num, "%d", &nRA)) {
				printf("\n");//recebe RA
			}
		}

		aluno.RA = nRA;//RA na stRAct recebe o RA
		strcpy(aluno.nomeAluno, nome); //nomeAluno na stRAct recebe o nome do aluno
	
		printf("\tDADOS DA STRACT ");
	printf("\n\nO Nome do Aluno: %-5s", aluno.nomeAluno);        //imprime dado da stRAct17
	printf("\nO Número do RA Aluno: %d\n\n", aluno.RA);           //imprime dado da stRAct22

	system("pause");
}

void exercicio4() {
	/*
	Exercício 4:

	Replique o exercício 3. Porém, agora, declare um ponteiro para a estRAtura de dados
heterogênea. No momento da leitura dos dados e da impressão na tela, use o ponteiro
para buscar o conteúdo dos campos. Imprima na tela também o seu RA na tela.

*/
	//Definindo o registro
	  //cada elemento da lista
	  //typedef faz com que naao se precise digitar novamente o nome da stRAct 
	  //t_cadastro identifica o ponteiro 

	l_cadastro *aluno; //declara a variavel do tipo pnteiro para armazenar o endereço da estRAct
	int nRA;
	char nome[tamNome];
	char num[tamRA];
	nRA = 0;

	aluno = (l_cadastro *)malloc(sizeof(l_cadastro));/*##Aloca memoria para inicio sizeof ## é uma
	função que retorna o tamanho de um tipo( e nao da variavel) malloc*/
	if (aluno == NULL) {
		printf("\n\n");
		printf("NAO FOI POSSIVEL REALIZAR A OPERAÇÃO !");
		printf("\n\a");
		system("pause");
		

	}
	else
	{

		printf("\n\n");
		printf("O Nome do Aluno: ");

		fflush(stdin);
		if (fgets(nome, sizeof(nome), stdin)) {
			//armazena o nome da musica a ser  inserida
			nome[strlen(nome) - 1] = '\0';/*caractere anterior fecha a string e evita que fgets
				  pule uma linha*/
		}


		printf("O Numero do RA: ");
		fflush(stdin);
		if (fgets(num, sizeof(num), stdin)) {
			if (1 == scanf(num, "%d", &nRA)) {
				printf("\n");//recebe RA
			}
		}

		aluno->RA = nRA;//RA na stRAct recebe o RA
		/*
		strcpy_s( char *strDestination, size_t numberOfElements,const char *strSource );
		*/
		strcpy(aluno->nomeAluno, nome); //nomeAluno na stRAct recebe o nome do aluno
	}

	printf("\nO Nome do Aluno: %-5s", aluno->nomeAluno);        //imprime dado da stRAct17
	printf("\nO Número do RA Aluno: %d\n\n", aluno->RA);           //imprime dado da stRAct22

	system("pause");

}

void exercicio5() {
	/*

Exercício 5:

Faça um algoritmo em linguagem C que contenha dois números inteiros digitados na
tela pelo usuário:

	a) O primeiro número marca um início;
	b) O segundo número marca um fim;

	O algoritmo vai contar quantos números existem entre o início (primeira entrada) e
o fim (segunda entrada). A impressão na tela do usuário deve ser realizada de duas formas:

	a)  Iterativa;
	b)  Recursiva;

	Ao colocar no seu relatório uma imagem do seu código funcionando, coloque ele
rodando utilizando como valor de inicio os 2 últimos valores do seu RA e valor final
o número 99.

*/

//variaveis do enunciado
	int ini, fim, resultado;
	//inicializando as variaveis
	ini = 0;
	fim = 0;
	resultado = 0;

	printf("\n\nDeseja-se saber quantos números existem entre o início (primeira entrada ou inicio) e o fim(segunda entrada ou fim) ");
	//laço para filtrar entrada fim > ini para evitar loop
	do {
		printf("\n\nDigite o número INICIAL: ");
		scanf("%d", &ini);//recebe ini


		printf("\nDigite o número FINAL: ");
		scanf("%d", &fim);//recebe fim

		printf("\n\n");
		if ((fim < ini) || (ini < 0) || (fim <= 0)) {
			printf("\n\nNúmero final menor que o inicial, digite INICIAL < FINAL e POSIIVOS. ");//critica avisando que valores estao errados
			printf("\n\n");
			system("pause");
		}
	} while ((fim < ini) || (ini < 0) || (fim <= 0));//fim do laço

	printf("\n\tRESULTADO");
	//ITERATIVA
	resultado = interativa(ini, fim);
	printf("\n\nA quantidade números existem entre o início (primeira entrada) e o fim(segunda entrada) ITERATIVAMENTE é: %d", resultado);
	resultado = 0;
	//RECURSIVA
	resultado = recursiva(resultado, ini, fim);
	printf("\n\nA quantidade números existem entre o início (primeira entrada) e o fim(segunda entrada) RECURSIVAMENTE é: %d", resultado);

	printf("\n\n");

	system("pause");
	
}


int interativa(int inicial, int final) {
	int conta;// variavel contadora
	conta = 0;

	for (int i = inicial; i < final; i++)conta++;  //laço para contar quantos numeros existem entre os dois inteiros

	return conta;//retorna o resultado

}

int recursiva(int resultado, int inicial, int final) {
	int conta, criterio;// variavel contadora e criterio de parada da função recursiva
	conta = resultado;

	criterio = inicial;
	if ((criterio == final) || (criterio > final)) {//criterio maior ou igual a final para e retorna conta
		return conta;
	}
	else {
		conta++;
		criterio++;
		recursiva(conta, criterio, final);
	}

}


