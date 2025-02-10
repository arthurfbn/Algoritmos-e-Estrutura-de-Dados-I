#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char label[21];
    int prioridade;
    struct cel *esquerda, *direita;
} cel;

cel* criaCel(const char* label, int prioridade) {
    cel* novaCel = (cel*)malloc(sizeof(cel));
    if (novaCel == NULL) {
        fprintf(stderr, "Erro ao alocar memória\n");
        exit(1);
    }
    strcpy(novaCel->label, label);
    novaCel->prioridade = prioridade;
    novaCel->esquerda = novaCel->direita = NULL;
    return novaCel;
}

cel* viraDireita(cel* raiz) {
    cel* novaRaiz = raiz->esquerda;
    raiz->esquerda = novaRaiz->direita;
    novaRaiz->direita = raiz;
    return novaRaiz;
}

cel* viraEsquerda(cel* raiz) {
    cel* novaRaiz = raiz->direita;
    raiz->direita = novaRaiz->esquerda;
    novaRaiz->esquerda = raiz;
    return novaRaiz;
}

cel* insere(cel* raiz, const char* label, int prioridade) {
    if (raiz == NULL) return criaCel(label, prioridade);

    if (strcmp(label, raiz->label) < 0) {
        raiz->esquerda = insere(raiz->esquerda, label, prioridade);
        if (raiz->esquerda->prioridade > raiz->prioridade)
            raiz = viraDireita(raiz);
    } else {
        raiz->direita = insere(raiz->direita, label, prioridade);
        if (raiz->direita->prioridade > raiz->prioridade)
            raiz = viraEsquerda(raiz);
    }

    return raiz;
}

void printTreap(cel* raiz) {
    if (raiz == NULL) return;
    printf("(");
    printTreap(raiz->esquerda);
    printf("%s/%d", raiz->label, raiz->prioridade);
    printTreap(raiz->direita);
    printf(")");
}

void freeTreap(cel* raiz) {
    if (raiz == NULL) return;
    freeTreap(raiz->esquerda);
    freeTreap(raiz->direita);
    free(raiz);
}

int main() {
    int n;
    char label[21];
    int prioridade;

    while (scanf("%d", &n) && n != 0) {
        cel* raiz = NULL;

        for (int i = 0; i < n; i++) {
            scanf("%20[^/]/%d", label, &prioridade);
            raiz = insere(raiz, label, prioridade);
        }

        printTreap(raiz);
        printf("\n");
        freeTreap(raiz);
    }

    return 0;
}