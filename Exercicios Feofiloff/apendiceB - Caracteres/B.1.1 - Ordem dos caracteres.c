/* Esse programa serve para dizer qual dos dois caracteres trazidos vem antes na tabela ASCII*/

#include<stdio.h>

int main()
{
    unsigned char c1, c2, menorC;
    int i = 0;
    scanf("%c %c", &c1, &c2);
    
    menorC = c1 < c2 ? c1 : c2;
    
    printf("'%c' de posicao %d vem %s\n", menorC, menorC,  c1 < c2 ? "antes" : "depois");

}
