#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[51];
} Jogador;

int comparaNomes(const void *a, const void *b) {
    return strcmp(((Jogador*)a)->nome, ((Jogador*)b)->nome);
}

int main() {
    int T;
    
    while (scanf("%d", &T) != EOF) {
        int X[T], Y[T], Z[T]; 
        char operador;
        
        for (int i = 0; i < T; i++) {
            scanf("%d %d=%d", &X[i], &Y[i], &Z[i]);
        }

        Jogador eliminados[T];
        int qtdEliminados = 0;

        for (int i = 0; i < T; i++) {
            char nome[51], resposta;
            int idx;
            scanf("%s %d %c", nome, &idx, &resposta);
            idx--; 

            int correto = 0;
            if ((resposta == '+' && X[idx] + Y[idx] == Z[idx]) ||
                (resposta == '-' && X[idx] - Y[idx] == Z[idx]) ||
                (resposta == '*' && X[idx] * Y[idx] == Z[idx]) ||
                (resposta == 'I' && X[idx] + Y[idx] != Z[idx] && 
                 X[idx] - Y[idx] != Z[idx] && X[idx] * Y[idx] != Z[idx])) {
                correto = 1;
            }

            if (!correto) strcpy(eliminados[qtdEliminados++].nome, nome);
        }

        if (qtdEliminados == 0) printf("You Shall All Pass!\n");
        else if (qtdEliminados == T) printf("None Shall Pass!\n");
        else {
            qsort(eliminados, qtdEliminados, sizeof(Jogador), comparaNomes);
            for (int i = 0; i < qtdEliminados; i++) {
                if (i > 0) printf(" ");
                printf("%s", eliminados[i].nome);
            }
            printf("\n");
        }
    }

    return 0;
}
