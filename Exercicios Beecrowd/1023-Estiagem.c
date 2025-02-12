#include <stdio.h>
#include <stdlib.h>

typedef struct imovel{
    int pessoas;
    int consumo;
} imovel;

int Separa(int p, int r, imovel v[]) {
    imovel c = v[r];
    int j = p;
    for (int k = p; k < r; k++) {
        int consumoK = v[k].consumo / v[k].pessoas;
        int consumoC = c.consumo / c.pessoas;
        if (consumoK <= consumoC) {
            imovel t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void Quicksort(int p, int r, imovel v[]) {
    if (p < r) {
        int j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
    }
}

int main() {
    int N, cidade = 1;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        imovel *imoveis = (imovel *)malloc(N * sizeof(imovel));
        if (imoveis == NULL) return 1;
        
        int totalPessoas = 0, totalConsumo = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &imoveis[i].pessoas, &imoveis[i].consumo);
            totalPessoas += imoveis[i].pessoas;
            totalConsumo += imoveis[i].consumo;
        }

        Quicksort(0, N - 1, imoveis);

        printf("Cidade# %d:\n", cidade++);
        for (int i = 0; i < N; i++) {
            int consumoPorPessoa = imoveis[i].consumo / imoveis[i].pessoas;
            if (i > 0) printf(" ");
            printf("%d-%d", imoveis[i].pessoas, consumoPorPessoa);
        }
        printf("\n");

        double consumoMedio = (double)totalConsumo / totalPessoas;
        printf("Consumo medio: %.2lf m3.\n\n", consumoMedio);

        free(imoveis);
    }

    return 0;
}