#ifndef JOGO_H
#define JOGO_H

#include "tabuleiro.h"

// Assinaturas das funções para identificar vizinhos e gerar o tabuleiro usando a struct t_casa:

int identificar_vizinhos(t_casa *tabuleiro, int N_ROWS, int N_COLS);

int gerar_tabuleiro(t_casa *tabuleiro, int N_ROWS, int N_COLS, int N_BOMBS);

#endif
