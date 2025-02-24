#include <stdio.h>

int maximoR (int v[], int n) { 
    if (n == 1)
        return v[0];
    else {
        int x;
        x = maximoR (v, n - 1);

        if (x > v[n-1]) return x;
        else return v[n-1];
    }
}

int main() {
    int v[] = {1, 3, 9, 2, 0};
    printf("O maior elemento eh: %d", maximoR(v, 5));
}