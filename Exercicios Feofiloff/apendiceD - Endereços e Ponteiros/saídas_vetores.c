#include <stdio.h>

void func (int *px, int *py) {
    px = py; // px passa a apontar para o mesmo endereço de py (y)
    //x se mantém inalterado, px apenas parou de apontar para ele
    *py = (*py) * (*px); // como px e py estão apontando para o mesmo lugar, os valores salvos em py serão atribuídos ao px e vice versa
    *px = *px + 2;
}

int main() {
    int x, y;
    scanf( "%d", &x);
    scanf("%d", &y);
    func(&x, &y);

    printf("x = %d, y = %d", x, y);

    return 0;
}

    