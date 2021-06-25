#include <stdio.h>

int soma(int * a, int * b){
    *a=5;
    *b=6;
    return *a+*b;
}

int main(void){
int a=2;
int b=4;
int * pa=&a;
int * pb=&b;

printf("Digite o valor de a: ");

printf("\n");


printf("Digite o valor de b: ");

printf("\n");
printf("A = %d e B = %d, antes da funcao\n",a,b);
printf("A soma de a + b :(direta) %d\n",a+b);
printf("A soma de *pa + *pb :(direta) %d\n",*pa+*pb);
printf("A soma de *pa + *pb :(função) %d\n",soma(pa,pb));
printf("A = %d e B = %d, apos a funcao\n",a,b);



return 0;

}
		
