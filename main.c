#include <stdio.h>
#include <stdlib.h>
#include "jogo.c"

int main(void) {

    int N_ROWS, N_COLS, N_BOMBS;
    int** tabuleiro;

    printf("Minisweeper\n");
    printf("Insira o número de linhas: ");
    if (scanf("%d", &N_ROWS) != 1) {
        fprintf(stderr, "Número de linhas inválido.\n");
        return 1;
    }
    printf("Insira o número de colunas: ");
    if (scanf("%d", &N_COLS) != 1) {
        fprintf(stderr, "Número de colunas inválido.\n");
        return 1;
    }
    printf("Insira o número de bombas: ");
    if (scanf("%d", &N_BOMBS) != 1) {
        fprintf(stderr, "Número de bombas inválido.\n");
        return 1;
    }

    if (N_ROWS <= 0 || N_COLS <= 0 || N_BOMBS < 0 ||
        N_BOMBS > N_ROWS * N_COLS) {
        fprintf(stderr, "Dimensões ou número de bombas inválidos.\n");
        return 1;
    }

    tabuleiro = malloc((size_t)N_ROWS * sizeof *tabuleiro);
    if (tabuleiro == NULL) {
        perror("Não foi possível alocar o tabuleiro");
        return 1;
    }
    for (int i = 0; i < N_ROWS; i++) {
        tabuleiro[i] = malloc((size_t)N_COLS * sizeof *tabuleiro[i]);
        if (tabuleiro[i] == NULL) {
            perror("Não foi possível alocar uma linha do tabuleiro");
            for (int j = 0; j < i; j++) {
                free(tabuleiro[j]);
            }
            free(tabuleiro);
            return 1;
        }
    }

    tabuleiro = gerar_tabuleiro(tabuleiro, N_ROWS, N_COLS, N_BOMBS);

    for(int i = 0; i < N_ROWS; i++) {
        for(int j = 0; j < N_COLS; j++) {
            if(tabuleiro[i][j] == -1) {
                printf("* ");
            } else {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }

    for (int i = 0; i < N_ROWS; i++) {
        free(tabuleiro[i]);
    }
    free(tabuleiro);
    return 0;
}