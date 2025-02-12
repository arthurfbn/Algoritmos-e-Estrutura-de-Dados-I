#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAX_CHAR_LENGTH = 1001;

typedef struct cel {
    char *valor;
    struct cel *nova;
} cel;

void insere(char *texto, cel **es, cel **et) {
    cel *novaCel;
    novaCel = (cel*)malloc(sizeof(cel));
    novaCel->valor = (char*)malloc(MAX_CHAR_LENGTH * sizeof(char));
    strcpy(novaCel->valor, texto);
    novaCel->nova = NULL;
    if (*et == NULL) *et = *es = novaCel;
    else {
        (*et)->nova = novaCel;
        *et = novaCel;
    }
}

void printaResultados(cel *prim) {
    cel *p;
    for (p = prim; p != NULL; p = p->nova)
        printf("%s\n", p->valor);
}

void encaixa_ou_nao(char *A, char *B, char *resultado) {
    int lenA = strlen(A);
    int lenB = strlen(B);

    if (lenB <= lenA && strcmp(A + (lenA - lenB), B) == 0)
        strcpy(resultado, "encaixa");
    else
        strcpy(resultado, "nao encaixa");
}

int main() {
    cel *s, *t;
    s = t = NULL;

    int n;
    char num1[MAX_CHAR_LENGTH], num2[MAX_CHAR_LENGTH], resultado[MAX_CHAR_LENGTH];

    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        scanf("%s %s", num1, num2);

        encaixa_ou_nao(num1, num2, resultado);

        insere(resultado, &s, &t);
    }

    printaResultados(s);
    return 0;
}