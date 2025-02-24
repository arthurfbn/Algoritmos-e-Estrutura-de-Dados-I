#include <stdio.h>

int x(int n) {
    if (n == 1 || n == 2) return n;
    else return x(n-1) + n * x(n-2);
}

int main() {
    printf("%d", xx(4));
}