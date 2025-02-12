#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int HASH_SIZE = 1000003;

typedef struct cel {
    char *joia;
    struct cel *nova;
} cel;

cel *hashTable[1000003];

unsigned int hash(char *str) {
    unsigned int hashValue = 5381;
    int c;
    while ((c = *str++)) {
        hashValue = ((hashValue << 5) + hashValue) + c;
    }
    return hashValue % HASH_SIZE;
}

int inserirJoia(char *joia) {
    unsigned int index = hash(joia);

    cel *atual = hashTable[index];
    while (atual != NULL) {
        if (strcmp(atual->joia, joia) == 0) return 0;
        atual = atual->nova;
    }

    cel *novaCel = (cel *)malloc(sizeof(cel));
    if (novaCel == NULL) exit(1);

    novaCel->joia = (char *)malloc(strlen(joia) + 1);
    if (novaCel->joia == NULL) {
        free(novaCel);
        exit(1);
    }

    strcpy(novaCel->joia, joia);
    novaCel->nova = hashTable[index];
    hashTable[index] = novaCel;

    return 1;
}

void liberarTabelaHash() {
    for (int i = 0; i < HASH_SIZE; i++) {
        cel *atual = hashTable[i];
        while (atual != NULL) {
            cel *temp = atual;
            atual = atual->nova;
            free(temp->joia);
            free(temp);
        }
        hashTable[i] = NULL;
    }
}

int main() {
    char buffer[102];
    int joiasDistintas = 0;

    for (int i = 0; i < HASH_SIZE; i++) {
        hashTable[i] = NULL;
    }

    while (scanf("%s", buffer) != EOF) {
        if (inserirJoia(buffer)) joiasDistintas++;
    }

    printf("%d\n", joiasDistintas);

    liberarTabelaHash();

    return 0;
}