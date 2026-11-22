#include <stdio.h>

#include "jogo.h"
#include "tabuleiro.h"

int main(void)
{
    int N_ROWS, N_COLS, N_BOMBS;

    printf("Minisweeper\n");

    printf("Insira o número de linhas: ");
    scanf("%d", &N_ROWS);

    printf("Insira o número de colunas: ");
    scanf("%d", &N_COLS);

    printf("Insira o número de bombas: ");
    scanf("%d", &N_BOMBS);

    // Criação do tabuleiro dinamicamente usando a struct t_casa e a função alocar_tabuleiro
    t_casa *tabuleiro = alocar_tabuleiro(N_ROWS, N_COLS);

    // Gerar o tabuleiro com as bombas e identificar os vizinhos usando a função gerar_tabuleiro
    gerar_tabuleiro(tabuleiro, N_ROWS, N_COLS, N_BOMBS);

    // Exibir o tabuleiro gerado com as bombas e os vizinhos identificados
    exibir_tabuleiro(tabuleiro, N_ROWS, N_COLS);

    // Limpar o tabuleiro da memória para evitar vazamentos de memória
    limpar_tabuleiro(tabuleiro);

    return 0;
}
