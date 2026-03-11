#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int N); // Protótipo da função ehPrimo

int main() {
    system("cls");
    int Numero;

    INICIO: 
        printf("Digite um numero: ");
        scanf("%d", &Numero);

        if(ehPrimo(Numero) == 1) {
            printf("%d eh primo.\n", Numero);
        } else {
            printf("%d nao e primo.\n", Numero);
        }

        fflush(stdin);
        printf("\nPressione para continuar...");
        getchar();

        system("cls");

    goto INICIO;

    return 0;
}


// Implementar função ehPrimo

// Versão 1 (testa todos os números)
// int ehPrimo(int N) {
//     if(N <= 1) return 0;
//     int cont = 0;

//     for(int i = 2; i < N; i++) {
//         cont++;
//         if(N % i == 0) {
//             if(cont == 1) {
//                printf("%d if | ", cont); 
//             } else {
//                 printf("%d ifs | ", cont);
//             }
//             return 0;
//         }
//     }

// Versão 2 (i nunca vai ser maior que a metade de N)
int ehPrimo(int N) {
    if(N <= 1) return 0;
    int cont = 0;

    for(int i = 2; i * i <= N; i++) {
        cont++;
        if(N % i == 0) {
            if(cont == 1) {
               printf("%d if | ", cont); 
            } else {
                printf("%d ifs | ", cont);
            }
            return 0;
        }
    }

    printf("%d ifs | ", cont);
    return 1; // Esse retorno só ocorrerá se todos os if (acima) falharem, o número é primo.
}