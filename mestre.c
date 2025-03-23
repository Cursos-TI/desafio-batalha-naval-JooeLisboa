#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO 5 // Tamanho das matrizes de habilidade

// Função para imprimir o tabuleiro
void imprimirTabuleiro(int tabuleiro[LINHAS][COLUNAS])
{
    char col[COLUNAS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    printf("\n   ");
    for (int i = 0; i < COLUNAS; i++)
    {
        printf(" %c ", col[i]);
    }
    printf("\n");

    for (int i = 0; i < LINHAS; i++)
    {
        printf("%2d |", i + 1);
        for (int j = 0; j < COLUNAS; j++)
        {
            if (tabuleiro[i][j] == 0)
                printf(" ~ "); // Água
            else if (tabuleiro[i][j] == 1)
                printf(" 1 "); // Cruz
            else if (tabuleiro[i][j] == 4)
                printf(" C "); // Cone
            else if (tabuleiro[i][j] == 8)
                printf(" 8 "); // Octaedro
            else if (tabuleiro[i][j] == 9)
                printf(" N "); // Navio
        }
        printf("|\n");
    }
}

// Função para gerar a matriz Cone
void gerarCone(int matriz[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = 0;
        }
    }

    // Criando um cone menor
    for (int i = 0; i < 3; i++) // Apenas 3 linhas de altura
    {
        for (int j = (TAMANHO / 2) - i; j <= (TAMANHO / 2) + i; j++)
        {
            matriz[i][j] = 4; // 'C' representa o cone
        }
    }
}

// Função para gerar a matriz do Navio
void gerarNavio(int matriz[TAMANHO][TAMANHO])
{
    // Inicializa a matriz com 0
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = 0; // Preenche a matriz com 0 (água)
        }
    }

    // Criando o navio
    for (int i = (TAMANHO / 2) - 1; i <= (TAMANHO / 2) + 1; i++) // 3 linhas consecutivas
    {
        matriz[i][TAMANHO / 2] = 9; // Marca o navio com 'N' (representado por 9)
    }
}

// Função para gerar a matriz Cruz
void gerarCruz(int matriz[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            matriz[i][j] = (i == TAMANHO / 2 || j == TAMANHO / 2) ? 1 : 0;
        }
    }
}

// Função para gerar a matriz Octaedro
void gerarOctaedro(int matriz[TAMANHO][TAMANHO])
{
    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            if (i + j >= TAMANHO / 2 && j - i <= TAMANHO / 2 && i - j <= TAMANHO / 2 && i + j <= (TAMANHO - 1) + (TAMANHO / 2))
                matriz[i][j] = 8;
            else
                matriz[i][j] = 0;
        }
    }
}

// Aplica a matriz da habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[LINHAS][COLUNAS], int habilidade[TAMANHO][TAMANHO], int origemX, int origemY)
{
    int inicioX = origemX - TAMANHO / 2;
    int inicioY = origemY - TAMANHO / 2;

    for (int i = 0; i < TAMANHO; i++)
    {
        for (int j = 0; j < TAMANHO; j++)
        {
            int x = inicioX + i;
            int y = inicioY + j;

            if (x >= 0 && x < LINHAS && y >= 0 && y < COLUNAS)
            {
                if (habilidade[i][j] != 0)
                {
                    tabuleiro[x][y] = habilidade[i][j];
                }
            }
        }
    }
}

int main()
{
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Criar matrizes das habilidades
    int cone[TAMANHO][TAMANHO], cruz[TAMANHO][TAMANHO], octaedro[TAMANHO][TAMANHO], navio[TAMANHO][TAMANHO];

    // Gerar habilidades
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);
    gerarNavio(navio);

    // Aplicando habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 6, 6);
    aplicarHabilidade(tabuleiro, octaedro, 7, 2);
    aplicarHabilidade(tabuleiro, navio, 1, 9);

    // Imprimir tabuleiro final
    imprimirTabuleiro(tabuleiro);

    return 0;
}
