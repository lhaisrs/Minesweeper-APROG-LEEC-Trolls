#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "tabuleiro.h"

//INT_MAX é um valor em <limits.h> e representa o maior valor que um int pode ter. 
//Ele é usado para verificar se a multiplicação de N_ROWS e N_COLS não excede o limite máximo de um int, evitando assim overflow  

t_casa *alocar_tabuleiro(int N_ROWS, int N_COLS) {
    if (N_ROWS <= 0 || N_COLS <= 0 || N_ROWS > INT_MAX / N_COLS) {
        return NULL;
    }

    size_t total = (size_t) N_ROWS * (size_t) N_COLS; // Alocando size_t para evitar overflow em sistemas de 64 bits

    if (total > INT_MAX || total > SIZE_MAX / sizeof(t_casa)) {
        return NULL;
    }

    // Caso seja possivel alocar, usamos calloc para inicializar a memória alocada com zeros, garantindo que todos os campos da struct t_casa sejam inicializados corretamente
    return calloc(total, sizeof(t_casa));
}

void limpar_tabuleiro(t_casa *tabuleiro)
{
    free(tabuleiro);
}

void exibir_tabuleiro(const t_casa *tabuleiro, int N_ROWS, int N_COLS)
{
    for (int i = 0; i < N_ROWS; i++) {
        for (int j = 0; j < N_COLS; j++) {
            int indice = i * N_COLS + j;
            int valor = tabuleiro[indice].valor;

            if (valor == -1) {
                printf("X ");
            }
            else if (valor == 0) {
                printf("  ");
            }
            else {
                printf("%d ", valor);
            }
        }
        printf("\n");
    }
}
