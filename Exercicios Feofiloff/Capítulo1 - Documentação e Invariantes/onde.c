int onde (int x, int v[], int n) { 
    int j = 0; 
    while (/*x ainda não foi encontrado no vetor v[0..j-1]*/ j < n && v[j] != x) j += 1;

    return j;
} 