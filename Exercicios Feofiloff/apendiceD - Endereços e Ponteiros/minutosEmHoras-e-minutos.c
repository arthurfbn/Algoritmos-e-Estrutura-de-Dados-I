#include <stdio.h>

void hm(int t, int *h, int *m) {
    *h = t / 60;
    *m = t % 60;
}

int main()
{
    int h, m, t = 128;
    hm(t, &h, &m);
    printf("%dh e %dm", h, m);
    return 0;
}
