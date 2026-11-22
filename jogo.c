#include <limits.h>
#include <stdlib.h>

#include "jogo.h"

int identificar_vizinhos(t_casa *tabuleiro, int N_ROWS, int N_COLS)
{
    // Verifica se o tabuleiro é nulo ou se as dimensões são inválidas: 
    // Se os valores são inválidos, não existem vizinhos a serem identificados, então a função retorna 0 (falso)
    if (tabuleiro == NULL || N_ROWS <= 0 || N_COLS <= 0 || N_ROWS > INT_MAX / N_COLS){
        return 0;
    }

    for (int linha = 0; linha < N_ROWS; linha++){
        for (int coluna = 0; coluna < N_COLS; coluna++){
            int indice = linha * N_COLS + coluna;
            t_casa *casa = &tabuleiro[indice]; // Uma casa é representada por um índice no array tabuleiro porque é a posição no tabuleiro

            casa->linha = linha; // Atribui a linha da casa
            casa->coluna = coluna; // Atribui a coluna da casa
            casa->valor = 0; // Inicializa o valor da casa como 0, indicando que não há bombas vizinhas inicialmente

            for (int i = 0; i < 8; i++){ // O array percorre os 8 vizinhos possíveis de uma casa (norte, nordeste, leste, sudeste, sul, sudoeste, oeste, noroeste)
                casa->vizinhos[i] = -1;
            }

            int vizinho = 0;

            for (int delta_linha = -1; delta_linha <= 1; delta_linha++){
                for (int delta_coluna = -1; delta_coluna <= 1; delta_coluna++){
                    if (delta_linha == 0 && delta_coluna == 0){
                        // Se apenas a casa atual, não é um vizinho, então continue para o próximo vizinho
                        continue;
                    }

                    int linha_vizinha = linha + delta_linha;
                    int coluna_vizinha = coluna + delta_coluna;

                    if (linha_vizinha >= 0 && linha_vizinha < N_ROWS && coluna_vizinha >= 0 && coluna_vizinha < N_COLS){
                        casa->vizinhos[vizinho++] = linha_vizinha * N_COLS + coluna_vizinha;
                    }
                }
            }
        }
    }

    return 1;
}

int gerar_tabuleiro(t_casa *tabuleiro, int N_ROWS, int N_COLS, int N_BOMBS)
{
    if (tabuleiro == NULL || N_ROWS <= 0 || N_COLS <= 0 || N_ROWS > INT_MAX / N_COLS || N_BOMBS < 0 ||N_BOMBS > N_ROWS * N_COLS){
        return 0;
    }

    if (!identificar_vizinhos(tabuleiro, N_ROWS, N_COLS)){
        return 0;
    }

    int total_casas = N_ROWS * N_COLS;
    int bombas_colocadas = 0;

    while (bombas_colocadas < N_BOMBS) {
        int indice = rand() % total_casas;
        if (tabuleiro[indice].valor == 0){
            tabuleiro[indice].valor = -1;
            bombas_colocadas++;
        }
    }

    for (int indice = 0; indice < total_casas; indice++){
        t_casa *casa = &tabuleiro[indice];
        if (casa->valor == -1){
            continue;
        }

        int bombas_vizinhas = 0;
        for (int i = 0; i < 8 && casa->vizinhos[i] != -1; i++){
            if (tabuleiro[casa->vizinhos[i]].valor == -1){
                //Verifica se o vizinho é uma bomba, se for, incrementa o contador de bombas vizinhas
                bombas_vizinhas++;
            }
        }
        
        casa->valor = bombas_vizinhas;
    }

    return 1;
}
