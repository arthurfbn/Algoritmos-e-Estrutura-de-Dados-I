int soma (int n, int v[]) { 
    int i, x = 0;
    for (i = 0; /* x é a soma dos elementos de v[0.. i]*/i < n; i++) x += v[i];
    
    return x;
}