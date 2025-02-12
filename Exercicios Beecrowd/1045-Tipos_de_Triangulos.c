#include <stdio.h>

void ordena(double v[]) {
    double temp;
    if (v[0] < v[1]) {
        temp = v[0];
        v[0] = v[1];
        v[1] = temp;
    }
    if (v[1] < v[2]) {
        temp = v[1];
        v[1] = v[2];
        v[2] = temp;
    }
    if (v[0] < v[1]) {
        temp = v[0];
        v[0] = v[1];
        v[1] = temp;
    }
}

int main() {
    double a[3];

    scanf("%lf %lf %lf", &a[0], &a[1], &a[2]);

    ordena(a);

    if (a[0] >= a[1] + a[2])
        printf("NAO FORMA TRIANGULO\n");
    else {
        double aQuadrado = a[0] * a[0];
        double bQuadrado = a[1] * a[1];
        double cQuadrado = a[2] * a[2];

        if (aQuadrado == bQuadrado + cQuadrado)
            printf("TRIANGULO RETANGULO\n");
        else if (aQuadrado > bQuadrado + cQuadrado)
            printf("TRIANGULO OBTUSANGULO\n");
        else 
            printf("TRIANGULO ACUTANGULO\n");
        

        if (a[0] == a[1] && a[1] == a[2]) 
            printf("TRIANGULO EQUILATERO\n");
        else if (a[0] == a[1] || a[1] == a[2] || a[0] == a[2])
            printf("TRIANGULO ISOSCELES\n");
    }

    return 0;
}