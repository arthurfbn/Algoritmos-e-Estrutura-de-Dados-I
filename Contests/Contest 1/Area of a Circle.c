#include <stdio.h>
 
int main() {
    double r;
    scanf("%lf", &r);
    
    double area = 3.14159 * r *r;
    
    printf("A=%.4lf\n", area);
 
    return 0;
}