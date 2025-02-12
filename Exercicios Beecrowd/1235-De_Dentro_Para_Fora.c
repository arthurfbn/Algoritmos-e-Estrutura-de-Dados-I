#include <stdio.h>
#include <string.h>

void inverterParte(char str[], int ini, int fim) {
    while (ini < fim) {
        char temp = str[ini];
        str[ini] = str[fim];
        str[fim] = temp;
        ini++;
        fim--;
    }
}

int main() {
    int t;
    char str[101];

    scanf("%d", &t);
    getchar();

    while (t--) {
        fgets(str, sizeof(str), stdin);

        if (str[0] == '\n' || str[0] == '\0') {
            t++;
            continue;
        }

        str[strcspn(str, "\n")] = '\0';

        int n = strlen(str);
        int meio = n / 2;

        inverterParte(str, 0, meio - 1);
        inverterParte(str, meio, n - 1);

        printf("%s\n", str);
    }

    return 0;
}
