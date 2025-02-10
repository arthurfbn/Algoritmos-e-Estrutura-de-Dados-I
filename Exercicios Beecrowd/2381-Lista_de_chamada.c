#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int MAX_CHAR_LENGTH = 30;

typedef struct cel {
    char *nome;
    struct cel *nova;
} cel;

void insere(const char *v, cel **es, cel **et) {
    cel *novaCel = (cel *)malloc(sizeof(cel));
    novaCel->nome = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    if (!novaCel) exit(1);

    strncpy(novaCel->nome, v, MAX_CHAR_LENGTH - 1);
    novaCel->nome[MAX_CHAR_LENGTH - 1] = '\0';
    novaCel->nova = NULL;

    if (*es == NULL)
        *es = *et = novaCel;
    else {
        (*et)->nova = novaCel;
        *et = novaCel;
    }
}

void ordenaLista(cel *lst) {
    if (!lst) return;

    cel *p, *q;
    char aux[MAX_CHAR_LENGTH];
    for (p = lst; p != NULL; p = p->nova) {
        for (q = p->nova; q != NULL; q = q->nova) {
            if (strcmp(p->nome, q->nome) > 0) {
                strncpy(aux, p->nome, MAX_CHAR_LENGTH);
                strncpy(p->nome, q->nome, MAX_CHAR_LENGTH);
                strncpy(q->nome, aux, MAX_CHAR_LENGTH);
            }
        }
    }
}

void printaNome(cel *lst, int index) {
    cel *p = lst;
    for (int i = 1; i < index; i++) {
        if (!p) exit(1);
        p = p->nova;
    }
    printf("%s\n", p->nome);
}

void liberaLista(cel *lst) {
    cel *atual = lst;
    while (atual) {
        cel *prox = atual->nova;
        free(atual);
        atual = prox;
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    cel *s = NULL, *t = NULL;
    char nome[MAX_CHAR_LENGTH];

    for (int i = 0; i < n; i++) {
        scanf("%s", nome);
        insere(nome, &s, &t);
    }

    ordenaLista(s);
    printaNome(s, k);
    liberaLista(s);

    return 0;
}
