#include <stdio.h>
#include <stdlib.h>
#include "jogo.c"
#include "tabuleiro.c"

int main(void)
{

    int N_ROWS, N_COLS, N_BOMBS;
    int **tabuleiro;

    printf("Minisweeper\n");

    printf("Insira o número de linhas: ");
    scanf("%d", &N_ROWS);

    printf("Insira o número de colunas: ");
    scanf("%d", &N_COLS);

    printf("Insira o número de bombas: ");
    scanf("%d", &N_BOMBS);

    // Criação do tabuleiro dinamicamente na mémoria usando malloc
    alocar_tabuleiro(&tabuleiro, N_ROWS, N_COLS);

    // Gerar o tabuleiro de acordo com as regras do jogo, incluindo a colocação de bombas e a contagem de bombas vizinhas
    tabuleiro = gerar_tabuleiro(tabuleiro, N_ROWS, N_COLS, N_BOMBS);

    // Exibir o tabuleiro gerado
    exibir_tabuleiro(tabuleiro, N_ROWS, N_COLS);

    // Limpar o tabuleiro da memória para evitar vazamentos de memória
    limpar_tabuleiro(tabuleiro, N_ROWS);
    
    return 0;
}