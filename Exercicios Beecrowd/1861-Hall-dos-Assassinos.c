#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char nome[11];
    int mortes;
    struct cel* proxima;
} cel;

typedef struct {
    cel** tabela;
    int tamanho;
} TabelaHash;

unsigned int funcaoHash(const char* str, int tamanho) {
    unsigned int hash = 5381;
    int c;
    while ((c = *str++))
        hash = ((hash << 5) + hash) + c;
    return hash % tamanho;
}

void inicializarTabela(TabelaHash* th, int tamanho) {
    th->tamanho = tamanho;
    th->tabela = (cel**)malloc(tamanho * sizeof(cel*));
    for (int i = 0; i < tamanho; i++) {
        th->tabela[i] = NULL;
    }
}

void inserirOuAtualizar(TabelaHash* th, const char* nome) {
    unsigned int idx = funcaoHash(nome, th->tamanho);
    cel* atual = th->tabela[idx];

    while (atual) {
        if (strcmp(atual->nome, nome) == 0) {
            atual->mortes++;
            return;
        }
        atual = atual->proxima;
    }

    cel* novaCelula = (cel*)malloc(sizeof(cel));
    strcpy(novaCelula->nome, nome);
    novaCelula->mortes = 1;
    novaCelula->proxima = th->tabela[idx];
    th->tabela[idx] = novaCelula;
}

int ehVitima(TabelaHash* vitimas, const char* nome) {
    unsigned int idx = funcaoHash(nome, vitimas->tamanho);
    cel* atual = vitimas->tabela[idx];
    while (atual) {
        if (strcmp(atual->nome, nome) == 0) return 1;
        atual = atual->proxima;
    }
    return 0;
}

void inserirVitima(TabelaHash* vitimas, const char* nome) {
    unsigned int idx = funcaoHash(nome, vitimas->tamanho);
    cel* atual = vitimas->tabela[idx];

    while (atual) {
        if (strcmp(atual->nome, nome) == 0) return;
        atual = atual->proxima;
    }

    cel* novaCelula = (cel*)malloc(sizeof(cel));
    strcpy(novaCelula->nome, nome);
    novaCelula->mortes = 0;
    novaCelula->proxima = vitimas->tabela[idx];
    vitimas->tabela[idx] = novaCelula;
}

int comparaAssassinos(const void* a, const void* b) {
    cel* assassinoA = *(cel**)a;
    cel* assassinoB = *(cel**)b;
    return strcmp(assassinoA->nome, assassinoB->nome);
}

void imprimirAssassinos(TabelaHash* assassinos, TabelaHash* vitimas) {
    cel* listaAssassinos[10000];
    int quantidade = 0;

    for (int i = 0; i < assassinos->tamanho; i++) {
        cel* atual = assassinos->tabela[i];
        while (atual) {
            if (!ehVitima(vitimas, atual->nome))
                listaAssassinos[quantidade++] = atual;
            atual = atual->proxima;
        }
    }

    qsort(listaAssassinos, quantidade, sizeof(cel*), comparaAssassinos);

    printf("HALL OF MURDERERS\n");
    for (int i = 0; i < quantidade; i++) {
        printf("%s %d\n", listaAssassinos[i]->nome, listaAssassinos[i]->mortes);
    }
}

void liberarTabela(TabelaHash* th) {
    for (int i = 0; i < th->tamanho; i++) {
        cel* atual = th->tabela[i];
        while (atual) {
            cel* temp = atual;
            atual = atual->proxima;
            free(temp);
        }
    }
    free(th->tabela);
}

int main() {
    TabelaHash assassinos, vitimas;
    const int tamanhoTabela = 10007; // Big prime number chosen to avoid collisions in the Hash structure

    inicializarTabela(&assassinos, tamanhoTabela);
    inicializarTabela(&vitimas, tamanhoTabela);

    char assassino[11], vitima[11];

    while (scanf("%10s %10s", assassino, vitima) == 2) {
        inserirOuAtualizar(&assassinos, assassino);
        inserirVitima(&vitimas, vitima);
    }

    imprimirAssassinos(&assassinos, &vitimas);

    liberarTabela(&assassinos);
    liberarTabela(&vitimas);

    return 0;
}