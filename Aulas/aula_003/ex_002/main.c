#include <stdio.h>
#include <stdlib.h>

// Definição dos DADOS do TAD Fração

typedef struct {
    int Numerador;
    int Denominador;
} Fracao;

// Definição das OPERAÇÕES (função) do TAD Fração
Fracao criarFracao(int N, int D);
void exibirFracao(Fracao F);
Fracao inverterFracao(Fracao F);

// Implementação da função main
int main() {    
    system("cls");
    
    Fracao F1 = criarFracao(3, 7);
    Fracao F2 = criarFracao(12, 20);
    Fracao F3 = criarFracao(6, 1);
    
    exibirFracao(F1);
    exibirFracao(inverterFracao(F2));
    exibirFracao(F3);
    return 0;
}

Fracao criarFracao(int N, int D) {
    if(D == 0) {
        printf("ERRO: Nao e possivel criar fracao com denominador 0\n");
        exit(1);
    }

    Fracao F;
    F.Numerador = N;
    F.Denominador = D;

    return F;
}

// Função para exibir fração
void exibirFracao(Fracao F) {
    printf("%d/%d \n", F.Numerador, F.Denominador);
}

// Função para inverter a fração criada
Fracao inverterFracao(Fracao F) {
    Fracao Fi;
    Fi.Numerador = F.Denominador;
    Fi.Denominador = F.Numerador;

    return Fi;
}


