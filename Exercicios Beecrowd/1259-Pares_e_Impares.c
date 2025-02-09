#include <stdio.h>

<<<<<<< HEAD
//The implentation of QuickSort's algorithm is based on the guide's book  of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff
=======
// The implentation of QuickSort's algorithm is based on the guide's book 
// of this disciplin 'Algoritmos em linguagem C' written by Paulo Feofiloff
>>>>>>> a0ec83f2f843e04e3b34570ce5c1cc3c318d83d5
int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; 
    j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;
    return j;
}

void Quicksort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        Quicksort(p, j - 1, v);
        Quicksort(j + 1, r, v);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    
    int v[n], pares[n], impares[n];
    int numPares = 0, numImpares = 0;

    for (i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (v[i] % 2 == 0) pares[numPares++] = v[i];
        else impares[numImpares++] = v[i]; 
    }

    Quicksort(0, numPares - 1, pares);
    Quicksort(0, numImpares - 1, impares);

    for (i = 0; i < numPares; i++) {
        printf("%d\n", pares[i]);
    }

    for (i = numImpares -1; i >= 0; i--) {
        printf("%d\n", impares[i]);
    }

    return 0;
}
