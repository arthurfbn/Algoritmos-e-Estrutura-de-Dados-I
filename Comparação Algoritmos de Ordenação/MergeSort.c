#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t
#include <string.h>

int const TAM = 20000; //constante para tamanho do vetor
int const VARIATION = 20000;
int const MAX_SIZE = 400000;


void intercala (int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc ((r-p) * sizeof (int));
    i = p; j = q; k = 0;
        while (i < q && j < r) {
            if (v[i] <= v[j]) w[k++] = v[i++];
            else w[k++] = v[j++];
        }
        while (i < q) w[k++] = v[i++];
        while (j < r) w[k++] = v[j++];
        for (i = p; i < r; i++) v[i] = w[i-p];
    free (w);
}

void mergesort (int p, int r, int v[]) {
    if (p < r - 1) {
        int q = (p + r)/2;
        mergesort (p, q, v);
        mergesort (q, r, v);
        intercala (p, q, r, v);
    }
}

int main(){
    printf("\t\t=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-MergeSort=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    
    FILE *arq; // cria variável ponteiro para o arquivo
    //abrindo o arquivo com tipo de abertura "a" para escrever ao final do arquivo
    arq = fopen("BaseComparacao.csv", "a");
    //testando se o arquivo foi realmente criado
    if(arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
        return 1;
    }

    double avgTime;
    char buffer[100];
    //semente de aleatoriedade
    srand((unsigned)time(NULL)); // RAND_MAX = 32767
    for (int c = TAM; c <= MAX_SIZE; c = c + VARIATION){
        avgTime = 0.0;
        for (int i = 0; i < 3; i++){
            clock_t t; //variável para armazenar tempo
            int vetor[c];
            
            //geração aleatório dos valores do vetor
            for(int a = 0; a < c; a++)
                vetor[a] = rand() % c;
            
            //Verificando tempo de execução
            t = clock(); //armazena tempo
            mergesort(0, c, vetor);
            t = clock() - t; //tempo final - tempo 

            avgTime += ((double)t)/((CLOCKS_PER_SEC/1000)); //conversão para double
        }
        //calcula a média de 3 execuções para a mesma dimensão do vetor
        avgTime /= 3;
        sprintf(buffer, "%s, %d, %.2lf\n", "MergeSort", c, avgTime);
        printf("Buffer: %s\n", buffer);
        fputs(buffer, arq); 
    }
    fclose(arq);
    printf("Dados gravados com sucesso!\n");
    return 0;
}
