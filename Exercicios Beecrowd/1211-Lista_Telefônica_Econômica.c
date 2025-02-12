#include <stdio.h>
#include <string.h>

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        char telefone[1001], prev[1001];
        int economia = 0;

        scanf("%s", prev);

        for (int i = 1; i < N; i++) {
            scanf("%s", telefone);

            int j = 0;
            while (telefone[j] == prev[j]) {
                j++;
            }

            economia += j;

            strcpy(prev, telefone);
        }

        printf("%d\n", economia);
    }
    return 0;
}
