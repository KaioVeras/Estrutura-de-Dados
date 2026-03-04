#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("cls");
    FILE *in = fopen("STM.csv", "r");

    if(in == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    long long id;

    //Saltando a primeira linha
    char buffer[10000];
    fscanf(in, "%[^\n]\n", buffer);

    int cont = 0;
    while(fscanf(in, "%[^\n]\n", buffer) == 1) {
        cont++;
    }

    printf("\nPessoas cadastradas: %d", cont);

    fclose(in);
    return 0;
}