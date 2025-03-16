#include <stdio.h>

int main()
{
    int tabuleiro[10][10] = {0};

    // Criando o "X" com duas diagonais
    for (int i = 7; i <= 9; i++)
    {
        tabuleiro[i][i] = 1; // Diagonal principal
    }
    for (int i = 1; i <= 3; i++)
    {
        tabuleiro[i][9 - i] = 1; // Diagonal secundária
    }
    for (int i = 5; i <= 7; i++)
    {
        tabuleiro[5][i] = 1;
    }
    for (int i = 4; i <= 6; i++)
    {
        tabuleiro[i][0] = 1;
    }
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Cabeçalho das colunas
    printf("   ");
    for (int i = 0; i < 10; i++)
    {
        printf(" %c ", colunas[i]);
    }
    printf("\n");

    for (int i = 0; i < 10; i++)
    {
        printf("%2d |", i + 1); // Número da linha

        for (int j = 0; j < 10; j++)
        {
            if (tabuleiro[i][j] == 1)
            {
                printf(" N ");
            }
            else
            {
                printf(" ~ ");
            }
        }
        printf("|\n");
    }

    return 0;
}
