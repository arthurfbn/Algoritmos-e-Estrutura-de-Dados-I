#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct cel {
    int conteudo;
    struct cel *seg;
} cel;

void Insere(int y, cel *p) {
    cel *nova;
    nova = malloc(sizeof(cel));
    if (!nova) exit(1);
    
    nova->conteudo = y;
    nova->seg = p->seg;
    p->seg = nova;
}

int Calcula(int b, int a, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/': return b / a;
        default: return 0;
    }
}

int ResolveNRJ(char* expr) {
    cel *pilha = malloc(sizeof(cel));
    if (!pilha) exit(1);
    
    pilha->seg = NULL;

    char *token = strtok(expr, " ");

    while (token != NULL) {
        if (isdigit(token[0])) {
            Insere(atoi(token), pilha);
        } else if (strchr("+-*/", token[0]) && strlen(token) == 1) {
            if (pilha->seg != NULL && pilha->seg->seg != NULL) {
                int a = pilha->seg->conteudo;
                int b = pilha->seg->seg->conteudo;
                pilha->seg = pilha->seg->seg->seg;

                if (token[0] == '/' && a == 0) {
                    free(pilha);
                    return -2;
                }

                int resultado = Calcula(b, a, token[0]);
                Insere(resultado, pilha);
            } else {
                free(pilha);
                return -1;
            }
        } else {
            free(pilha);
            return -1;
        }
        token = strtok(NULL, " ");
    }

    if (pilha->seg != NULL && pilha->seg->seg == NULL) {
        int resultado = pilha->seg->conteudo;
        free(pilha);
        return resultado;
    } else {
        free(pilha);
        return -1;
    }
}

int main() {
    char expr[2000001];
    while (fgets(expr, sizeof(expr), stdin)) {
        expr[strcspn(expr, "\n")] = '\0';
        int resultado = ResolveNRJ(expr);

        if (resultado == -1) {
            printf("Invalid expression.\n");
        } else if (resultado == -2) {
            printf("Division by zero.\n");
        } else {
            printf("The answer is %d.\n", resultado);
        }
    }

    return 0;
}