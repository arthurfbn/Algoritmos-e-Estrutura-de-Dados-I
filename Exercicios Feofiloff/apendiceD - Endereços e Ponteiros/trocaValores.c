// O uso de ponteiros e os seus endereços é crucial nesse código para que os valores das variáveis possam ser alterados, sem
// a necessidade da aplicação de uma função retornando o novo valor de ambos. O recurso dos ponteiros faz com que através do
// procedimento, cada variável possa apontar para o valor armazenado na outra, através do auxílio da variável temp, de forma
// a trocarem seus valores ao fim da execução do código

#include <stdio.h>

void trocaErrado (int i, int j) { //inútil
    int temp; 
    temp = i; i = j; j = temp;
}

void trocaCerto (int *p, int *q) {
    int temp; 
    temp = *p; *p = *q; *q = temp;
}

int main()
{
    //trocaErrado(32, 4);
    int p, q;
    p = 32; q = 4;
    trocaCerto(&p, &q);
    printf("p = %d e q = %d", p, q);
    return 0;
}
