#include <stdio.h>
typedef struct
{
	char nome[100];
	int idade;
} pessoa;

int main()
{
	pessoa joao;
	pessoa *p = &joao;
	strcpy(joao.nome, "joao da silva");
	joao.idade = 20;
	printf("%s, %d\n", (*p).nome, (*p).idade);
	(*p).idade = 18;
	printf("%s, %d\n", joao.nome, joao.idade);
	
	return 0;
}