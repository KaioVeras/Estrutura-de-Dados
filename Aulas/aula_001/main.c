#include <stdio.h>
#include <stdlib.h> // Utilizar o system
#include <string.h> // Utilizar strings

// int main() {
//     system("cls");
    
//     // FILE * Arq = fopen("ListaTelefonica.cvs", "r");

//     FILE * fp = fopen("bloco.txt", "w");
//     fp = fopen("bloco.txt", "a");

//     if(fp == NULL) {
//         printf("ERRO: O arquivo nao existe!!!");
//         exit(1); // Vai encerrar o código fonte aqui
//     }

//     int numero = 312;
//     char frase[] = "Neste semestre, os TP serão em grupos de 4 alunos"; 

//     fprintf(fp, "%d\n%s", numero, frase); // Vai escrever no arquivo bloco.txt
//     // fprintf(fp, "\n"); // Quebra de linha
//     // fprintf(fp, "%s", frase); // Vai escrever a frase no bloco.txt

//     fclose(fp); // fecha o arquivo

//     return 0;
// }


// Tabuada

// #define numTab 13

// int main() {
//     FILE * tab = fopen("tabuada.txt", "w");
//     tab = fopen("tabuada.txt", "a");

//     if(tab == NULL) {
//         printf("ERRO: O arquivo nao existe!!!");
//         exit(1);
//     }

//     for(int i = 1; i <= 10; i++) {
//         fprintf(tab, "%d * %d = %d\n",numTab, i, numTab * i);
//     }

//     fclose(tab);
// }


// Lendo o arquivo

int main() {
    FILE * fp = fopen("bloco.txt", "r");

    if(fp == NULL) {
        printf("ERRO: O arquivo nao existe!!!");
        exit(1);
    }

    int numero;
    char nome[50];

    for(int i = 0; i < 3; i++) {
        fscanf(fp, "%d %[^\n]s", &numero, nome); // Utilizar &. String não precisa // [^\n] - Ele vai ler caracteres enquanto não for o final da linha, vai incluir espaços entre os nomes
        printf("%d) %d %s \n",i+1, numero, nome);
    }

    fclose(fp);
}

/*
    Comando para compilar código C
        gcc main.c -o main.exe
        -o = serve para dar um nome para o resultado. O nome padrão é "a.exe"

    Comando para executar o código
        ./main.exe

    Comandos Terminal Windows
        cls - limpar
        dir - mostrar diretórios
        del - Deletar
        mkdir && md - Criar pastas. Para criar uma pasta com subpasta utilize \\
        rmdir && rm - Deletar pastas.
        cd - Navegar entre pastas
        cd .. - Voltar uma pasta

    Comando para manipular Arquivos
        FILE * - Criar um ponteiro do tipo arquivo
*/

// printf("%d", Arq); // Mostra o endereço de memória
// printf("%X", Arq); // Mostra o endereço de memória de forma hexadecimal