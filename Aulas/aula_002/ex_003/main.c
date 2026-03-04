/*
    Escreva um programa que leia um arquivo texto contendo uma lista de compras em que cada linha
    possui o nome do produto, a quantidade e o valor unitário de cada item para, em seguida, informar
    o valor total da compra. Caso o arquivo texto tenha:

    Arroz 2 5.50
    Feijão 3 3.00
    Carne 1 15.75
    Leite 4 2.50 

    A saída (na tela) deverá ser:

    1) Arroz: 2 * 5.50 = 11.00 
    2) Feijão: 3 * 3.00 = 9.00
    3) Carne: 1 * 15.75 = 15.75
    4) Leite: 4 * 2.50 = 10.00

    O valor total da compra é R$ 45.75
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    system("cls");
    FILE *in = fopen("compras.csv", "r");

    if(in == NULL) {
        printf("Erro ao abrir o arquivo!");
        exit(1);
    }

    int quantidade;
    char nome[20];
    float valor, soma, total;

    //Saltando a primeira linha
    char buffer[100];
    fscanf(in, "%[^\n]\n", buffer);

    int cont = 0;
    while(fscanf(in, "%[^,],%d,%f\n", nome, &quantidade, &valor) == 3) {
        cont++;
        total = quantidade * valor;
        soma += total;
        printf("%d) %s: %d * %.2f = %.2f\n",cont, nome, quantidade, valor, total);
    }

    printf("\nO valor total da compra e: R$%.2f", soma);

    fclose(in);
    return 0;
}