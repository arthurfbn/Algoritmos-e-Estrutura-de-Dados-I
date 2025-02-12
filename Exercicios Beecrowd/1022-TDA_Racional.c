#include <stdio.h>
#include <stdlib.h>

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void simplificar(int *num, int *den) {
    int divisor = mdc(abs(*num), abs(*den)); 
    *num /= divisor;
    *den /= divisor;

    if (*den < 0) {
        *num *= -1;
        *den *= -1;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int N1, D1, N2, D2;
        char op1, op2, op3;

        scanf("%d %c %d %c %d %c %d", &N1, &op1, &D1, &op2, &N2, &op3, &D2);

        int num_resultado, den_resultado;

        switch (op2) {
            case '+':
                num_resultado = N1 * D2 + N2 * D1;
                den_resultado = D1 * D2;
                break;
            case '-':
                num_resultado = N1 * D2 - N2 * D1;
                den_resultado = D1 * D2;
                break;
            case '*':
                num_resultado = N1 * N2;
                den_resultado = D1 * D2;
                break;
            case '/':
                num_resultado = N1 * D2;
                den_resultado = N2 * D1;
                break;
            default:
                printf("Operação inválida!\n");
                return 1;
        }

        printf("%d/%d = ", num_resultado, den_resultado);

        simplificar(&num_resultado, &den_resultado);

        printf("%d/%d\n", num_resultado, den_resultado);
    }

    return 0;
}