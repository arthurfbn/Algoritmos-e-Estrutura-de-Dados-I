#include <stdio.h>
 
int main() {
    int dias_entrada;
    scanf("%d", &dias_entrada);
    
    int anos = dias_entrada / 365;
    int meses = (dias_entrada % 365) / 30;
    int dias = (dias_entrada % 365) - (30*meses);
    
    printf("%d ano(s)\n", anos);
    printf("%d mes(es)\n", meses);
    printf("%d dia(s)\n", dias);
    return 0;
}
