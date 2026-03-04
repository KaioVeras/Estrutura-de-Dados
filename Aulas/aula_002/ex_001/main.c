#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("cls");
    FILE *in = fopen("nomes.txt", "r");

    if(in == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int numero;
    char nome[100];

    while(fscanf(in, "%d %[^\n]\n", &numero, nome) == 2) {
        printf("%d\t%s\n", numero, nome);
    }

    fclose(in);

    return 0;
}