#include <stdio.h>
#include <string.h>

double duracao_nota(char nota) {
    switch (nota) {
        case 'W': return 1.0;
        case 'H': return 0.5;
        case 'Q': return 0.25;
        case 'E': return 0.125;
        case 'S': return 0.0625;
        case 'T': return 0.03125;
        case 'X': return 0.015625;
        default: return 0.0;
    }
}

int main() {
    char composicao[201];
    while (1) {
        scanf("%s", composicao);
        if (composicao[0] == '*') break;

        int corretos = 0;
        int tamanho = strlen(composicao);
        int i = 1;

        while (i < tamanho) {
            double duracao_compasso = 0.0;
            while (i < tamanho && composicao[i] != '/') {
                duracao_compasso += duracao_nota(composicao[i]);
                i++;
            }
            if (duracao_compasso == 1.0) corretos++;
            
            i++;
        }

        printf("%d\n", corretos);
    }

    return 0;
}