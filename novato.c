#include <stdio.h>

int main()
{
    int tabuleiro[10][10] = {0}; // Inicializa o tabuleiro com 0 (água)

    // Posicionando navios (1 representa um navio)
    tabuleiro[2][3] = 1; // navio na posição D3
    tabuleiro[2][4] = 1; // navio na posição E3
    tabuleiro[2][5] = 1; // navio na posição F3

    tabuleiro[5][8] = 1; // Exemplo: um navio na posição J6
    tabuleiro[6][8] = 1; // Exemplo: um navio na posição J7
    tabuleiro[7][8] = 1; // Exemplo: um navio na posição J8

    char tabela[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int tabela2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Cabeçalho com letras das colunas
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", tabela[i]);
    }
    printf("\n");

    // Impressão do tabuleiro
    for (int i = 0; i < 10; i++)
    {
        printf("%2d ", tabela2[i]); // Número da linha

        for (int j = 0; j < 10; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                printf(" N "); // Navio
            }
            else
            {
                printf(" ~ "); // Água
            }
        }

        printf("\n");
    }

    return 0;
}
