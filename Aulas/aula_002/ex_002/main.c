#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("cls");
    FILE *in = fopen("dados.csv", "r");

    if(in == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int id;
    char nome[100];
    int idade;

    //Saltando a primeira linha
    char buffer[100];
    fscanf(in, "%[^\n]\n", buffer);

    int cont = 0;
    while(fscanf(in, "%d,%[^,],%d\n", &id, nome, &idade) == 3) {
        printf("%d\t%s\t%d\n", id, nome, idade);
        cont++;
    }

    printf("\nPessoas cadastradas: %d", cont);

    fclose(in);
    return 0;
}