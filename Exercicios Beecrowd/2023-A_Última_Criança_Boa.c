#include <stdio.h>
#include <string.h>
#include <ctype.h>


int compararNomes(const char *nome1, const char *nome2) {
    while (*nome1 && *nome2) {
        char c1 = tolower(*nome1);
        char c2 = tolower(*nome2);
        
        if (c1 != c2) return c1 - c2;
        
        nome1++;
        nome2++;
    }
    return *nome1 - *nome2;
}

int main() {
    char nomes[1000][81];
    int totalNomes = 0;

    while (fgets(nomes[totalNomes], 81, stdin) != NULL) {
        
        size_t len = strlen(nomes[totalNomes]);
        if (len > 0 && nomes[totalNomes][len - 1] == '\n') 
            nomes[totalNomes][len - 1] = '\0';
        totalNomes++;
    }

    int indiceUltimo = 0;
    for (int i = 1; i < totalNomes; i++) {
        if (compararNomes(nomes[i], nomes[indiceUltimo]) > 0) 
            indiceUltimo = i;
    }
    printf("%s\n", nomes[indiceUltimo]);

    return 0;
}