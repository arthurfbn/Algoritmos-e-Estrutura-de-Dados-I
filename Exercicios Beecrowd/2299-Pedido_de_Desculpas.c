#include <stdio.h>
#include <stdlib.h>


typedef struct frase{
    int tamanho;
    int desculpes;
} frase;

int main() {
    int C, F, test_case = 1;

    while (1) {
        scanf("%d %d", &C, &F);
        
        if (C == 0 && F == 0) break;

        frase frases[F];
        for (int i = 0; i < F; i++) {
            scanf("%d %d", &frases[i].tamanho, &frases[i].desculpes);
        }

        int dp[1001] = {0};

        for (int i = 0; i < F; i++) {
            for (int j = C; j >= frases[i].tamanho; j--) {
                int valorAtual = dp[j - frases[i].tamanho] + frases[i].desculpes;
                if (dp[j] < valorAtual) dp[j] = valorAtual;
            }
        }

        printf("Teste %d\n", test_case++);
        printf("%d\n\n", dp[C]);
    }

    return 0;
}
