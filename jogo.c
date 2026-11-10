#include <stdio.h>
#include <stdlib.h>
#include "tabuleiro.h"

void verificar_bombas(int **tabuleiro, int N_ROWS, int N_COLS, int N_BOMBS) {

    // Colocando bombas aleatoriamente no tabuleiro
    int bombs_placed = 0;
    while (bombs_placed < N_BOMBS) {
        int row = rand() % N_ROWS;
        int col = rand() % N_COLS;

        // Verifica se já existe uma bomba nessa posição
        if (tabuleiro[row][col] == 0) {
            tabuleiro[row][col] = -1; // -1 representa uma bomba
            bombs_placed++;
        }
    }

}


int** gerar_tabuleiro(int **tabuleiro, int N_ROWS, int N_COLS, int N_BOMBS) {

    // Inicializando o tabuleiro com zeros
    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    verificar_bombas(tabuleiro, N_ROWS, N_COLS, N_BOMBS);

    // Calcular o número de bombas vizinhas para cada célula
    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            if (tabuleiro[i][j] == -1) {
                continue; // Pular a célula com bomba, não precisamos contar vizinhos
            } else {
                //printf("Valor da célula (%d, %d): %d\n", i, j, tabuleiro[i][j]);
                // Armazenar o valor da célula atual
            }

            int bomb_count = 0;
            for (int x = -1; x <= 1; x++) {
                for (int y = -1; y <= 1; y++) {
                    if (x == 0 && y == 0) continue; // Pular a célula em si
                    int new_row = i + x;
                    int new_col = j + y;

                    // Verificar limites e contar bombas
                    if (new_row >= 0 && new_row < N_ROWS && new_col >= 0 && new_col < N_COLS) {
                        if (tabuleiro[new_row][new_col] == -1) {
                            bomb_count++;
                        }
                    }
                }
            }

            tabuleiro[i][j] = bomb_count;
        }
    }

    return tabuleiro;
}