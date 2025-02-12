#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int a, b, c, maior;

    scanf("%d %d %d", &a, &b, &c);

    maior = (a + b + abs(a - b)) / 2;
    
    if(c > maior)
        maior = c;
    
    printf("%d eh o maior\n", maior);

}