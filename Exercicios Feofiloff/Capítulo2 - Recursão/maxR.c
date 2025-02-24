// Programa recursivo que encontra o maior elemento de um trecho do vetor v a partir do postulado de que i < n

#include <stdio.h>

int maxR(int v[], int i, int n) {
    if (i == n-1) return v[i];
    else{
        int x;
        x = maxR(v, i + 1, n);
        if (x > v[i]) return x;
        else return v[i];
    }
}

int main(){
    int v[] = {6, 4, 1, 0};
    printf("%d", maxR(v, 3, 4));
}