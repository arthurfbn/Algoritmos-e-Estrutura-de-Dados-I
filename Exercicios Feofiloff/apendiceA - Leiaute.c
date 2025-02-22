/* Este é um exemplo de um bom leiaute de programa, seguindo os padrões de identação e espaçamento, assim como o desapego de 
   chaves desnecessárias. Qualquer outra variação deste código em C, que fuja dos padrões citados acima, é menos elegante 
   que o código abaixo.
*/

#include <stdio.h>
int Funcao(int n, int v[]) {
    int i, j;
    i = 0;
    while (i < n) {
        if (v[i] != 0) 
            i = i + 1;
        else {
            for (j = i + 1; j < n; j++) 
                v[j-1] = v[j];
            n--;
        }
    }

    return n;
}



int main() { 
    int v[] = {0,3,7,0,8};
    printf("Teste funcao: %d", Funcao(5,v));
}