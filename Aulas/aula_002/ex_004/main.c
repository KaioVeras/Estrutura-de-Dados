#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    // system("cls"); Windows
    system("clear"); // Linux e MacOS
    FILE *in = fopen("compras.csv", "r");

    if (in == NULL)
    {
        printf("ERRO (in): Não foi possivel abrir o arquivo!");
        exit(1);
    }

    FILE *out = fopen("carrinho.html", "w");

    if (out == NULL)
    {
        printf("ERRO (out): Não foi possivel abrir o arquivo!");
        exit(1);
    }

    /* Cabeçalho HTML + CSS simples */
    fprintf(out,
            "<!DOCTYPE html>\n<html lang=\"pt-BR\">\n<head>\n"
            "<meta charset=\"UTF-8\">\n<title>Lista de Compras</title>\n"
            "<style>"
            "body{font-family:Arial,Helvetica,sans-serif;margin:24px}"
            "table{border-collapse:collapse;width:720px;max-width:100%%}"
            "th,td{border:1px solid #ccc;padding:8px;text-align:left}"
            "th{background:#f2f2f2}"
            "tfoot td{font-weight:bold}"
            "tbody tr:nth-child(even){background:#fafafa}"
            "</style>\n</head>\n<body>\n"
            "<h2>Relatório de Compras</h2>\n"
            "<table>\n"
            "<thead><tr>"
            "<th>#</th><th>Produto</th><th>Quantidade</th>"
            "<th>Preço unitário (R$)</th><th>Total do item (R$)</th>"
            "</tr></thead>\n<tbody>\n");

    int Cont = 0, Quantidade;
    float Soma, Total;
    char Produto[30];
    float Preco;

    // Saltando a primeira linha
    char Buffer[1000];
    fscanf(in, "%[^\n]\n", Buffer);

    while (fscanf(in, "%[^,],%d,%f\n", Produto, &Quantidade, &Preco) == 3)
    {
        Soma = 0;
        Soma = Quantidade * Preco;
        Total += Soma;
        Cont++;

        fprintf(out,
                "<tr><td>%d</td><td>%s</td><td>%d</td>"
                "<td>%.2f</td><td>%.2f</td></tr>\n",
                Cont, Produto, Quantidade, Preco, Soma);
    }

    fprintf(out,
            "</tbody>\n<tfoot>"
            "<tr><td colspan=\"4\">Valor total da compra</td>"
            "<td>R$ %.2f</td></tr>"
            "</tfoot>\n</table>\n</body>\n</html>\n",
            Total);

    printf("Relatório gerado com sucesso!\n");

    fclose(in);
    fclose(out);
    return 0;
}
