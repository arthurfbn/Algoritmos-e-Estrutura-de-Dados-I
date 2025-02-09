#include <stdio.h>
#include <string.h>

//This algotithm simulates the use of stacks in C
int main() {
    const int MAX = 1000;
    char expression[MAX];
    int i, countParentheses;

    while (scanf("%s", expression) != EOF) {
        countParentheses = 0;

        for (i = 0; expression[i] != '\0'; i++) {
            if (expression[i] == '(') {
                countParentheses++;
            } else if (expression[i] == ')') {
                countParentheses--;
                if (countParentheses < 0) break;
            }
        }

        if (countParentheses == 0) printf("correct\n");
        else printf("incorrect\n");
    }
    
    return 0;
<<<<<<< HEAD
}
=======
}
>>>>>>> a0ec83f2f843e04e3b34570ce5c1cc3c318d83d5
