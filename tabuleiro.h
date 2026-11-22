#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef struct s_casa {
    int linha;
    int coluna;
    int valor;
    int vizinhos[8];
} t_casa;

// Assinaturas das funções para alocar, limpar e exibir o tabuleiro usando a struct t_casa:

t_casa *alocar_tabuleiro(int N_ROWS, int N_COLS);

void limpar_tabuleiro(t_casa *tabuleiro);

void exibir_tabuleiro(const t_casa *tabuleiro, int N_ROWS, int N_COLS);

#endif
