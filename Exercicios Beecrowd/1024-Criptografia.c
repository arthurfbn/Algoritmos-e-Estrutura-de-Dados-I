#include <stdio.h>
#include <string.h>

void criptografar(char str[]) {
    int i, n = strlen(str);

    for (i = 0; i < n; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
            str[i] += 3;
    }

    for (i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }

    for (i = n / 2; i < n; i++) {
        str[i] -= 1;
    }
}

int main() {
    int t;
    char str[1001];

    scanf("%d", &t);
    getchar();

    while (t--) {
        fgets(str, 1001, stdin);
        str[strcspn(str, "\n")] = '\0';

        criptografar(str);
        printf("%s\n", str);
    }

    return 0;
}
