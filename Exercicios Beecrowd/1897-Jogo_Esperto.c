#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct cel {
    int valor;
    int passos;
} cel;

cel fila[MAX];
int inicio = 0, fim = 0;

void enfileirar(int valor, int passos) {
    fila[fim].valor = valor;
    fila[fim].passos = passos;
    fim++;
}

cel desenfileirar() {
    return fila[inicio++];
}

int fila_vazia() {
    return inicio == fim;
}

int bfs(int N, int M) {
    int visitado[MAX] = {0}; 

    if (N == M) return 0;

    enfileirar(N, 0);
    visitado[N] = 1;

    while (!fila_vazia()) {
        cel atual = desenfileirar();

        int proximo;

        proximo = atual.valor * 2;
        if (proximo <= MAX && proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }

        proximo = atual.valor * 3;
        if (proximo <= MAX && proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }

        proximo = atual.valor / 2;
        if (proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }

        proximo = atual.valor / 3;
        if (proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }

        proximo = atual.valor + 7;
        if (proximo <= MAX && proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }

        proximo = atual.valor - 7;
        if (proximo >= 0 && !visitado[proximo]) {
            if (proximo == M) 
                return atual.passos + 1;
            visitado[proximo] = 1;
            enfileirar(proximo, atual.passos + 1);
        }
    }

    return -1; 
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int resultado = bfs(N, M);

    printf("%d\n", resultado);

    return 0;
}