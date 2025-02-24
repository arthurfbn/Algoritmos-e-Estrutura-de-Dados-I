// Script feito para mostrar todos os símbolos de 32 até 255

#include <stdio.h>

int main()
{
    int i;
    for (i = 32; i < 255; i++)
        printf("%c\n", '\0' + i - 1);

    return 0;
}




