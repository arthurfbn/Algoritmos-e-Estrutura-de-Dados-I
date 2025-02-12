#include <stdio.h>
#include <string.h>

int main() {
    char d, num[105];
    
    while (1) {
        scanf(" %c %s", &d, num);
        
        if (d == '0' && strcmp(num, "0") == 0) break;
        
        char resultado[105];
        int j = 0, inicio = 1;
        
        for (int i = 0; num[i] != '\0'; i++) {
            if (num[i] != d) {
                if (num[i] != '0' || !inicio) {
                    resultado[j++] = num[i];
                    inicio = 0;
                }
            }
        }

        resultado[j] = '\0';
        
        if (j == 0) printf("0\n");
        else printf("%s\n", resultado);
    }

    return 0;
}
