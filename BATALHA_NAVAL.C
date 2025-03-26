#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Definição dp tabuleiro
#define AGUA 0
#define NAVIO 3
#define HABIULITADEDE 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    memset(tabuleiro, AGUA, sizeof(int) * TAM_TABULEIRO * TAM_TABULEIRO);
}

// Função posicionar um navio (exemplo)
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{

    tabuleiro[4][4] = NAVIO;
    tabuleiro[4][5] = NAVIO;
    tabuleiro[5][4] = NAVIO;
    tabuleiro[5][5] = NAVIO;
}

// Função para definir a matriz de habilidade em formato de cone
void definirCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);

    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][2] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
}

// Função para definir a matriz de habilidade em formato de cruz
void definirCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);
    for (int i = 0; i < TAM_HABILIDADE; i++)
        matriz[2][i] = 1;
    for (int i = 0; i < TAM_HABILIDADE; i++)
        matriz[i][2] = 1;
}

// Função para definir a matriz de habilidade em formato de octeadro
void definirOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE])
{
    memset(matriz, 0, sizeof(int) * TAM_HABILIDADE * TAM_HABILIDADE);

    matriz[0][2] = 1;
    matriz[1][1] = matriz[1][3] = 1;
    matriz[2][0] = matriz[2][1] = matriz[2][2] = matriz[2][3] = matriz[2][4] = 1;
    matriz[1][1] = matriz[3][3] = 1;
    matriz[1][1] = 1;
}

// Função para aplicar a matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_HABILIDADE][TAM_TABULEIRO], int matriz[TAM_HABILIDADE][TAM_HABILIDADE], int origemx, int origemY)
{
    for (int i = 0; i < TAM_HABILIDADE; i++)
    {
        for (int j = 0; j < TAM_HABILIDADE; j++)
        {
            int x = origemx + i - TAM_HABILIDADE / 2;
            int y = origemY + j - TAM_HABILIDADE / 2;
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && matriz[i][j] == 1)
            {
                tabuleiro[x][y] = HABIULITADEDE;
            }
        }
    }
}

// Função para exebir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO])
{
    for (int i = 0; i < TAM_TABULEIRO; i++)
    {
        for (int j = 0; j < TAM_TABULEIRO; j++)
        {
            printf("%d\n", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{

    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    int matriz[TAM_HABILIDADE][TAM_HABILIDADE];

    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);

    // Teste com a habilidade Cone
    definirCone(matriz);
    aplicarHabilidade(tabuleiro, matriz, 3, 3);
    printf("Tabuleiro com habilidade Cone:\n");
    exibirTabuleiro(tabuleiro);

    // Resetando o tabuleiro
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);

    // Teste com a habilidade Cruz
    definirCruz(matriz);
    aplicarHabilidade(tabuleiro, matriz, 5, 5);
    printf("Tabuleiro com habilidade Cruz:\n");
    exibirTabuleiro(tabuleiro);

    // Resetando o tabuleiro
    inicializarTabuleiro(tabuleiro);
    posicionarNavio(tabuleiro);

    // Teste com a habilidade Octaedro
    definirOctaedro(matriz);
    aplicarHabilidade(tabuleiro, matriz, 6, 6);
    printf("Tabuleiro com habilidade Octaedro:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
