int** alocar_tabuleiro(int ***tabuleiro, int N_ROWS, int N_COLS)
{
    *tabuleiro = malloc((size_t)N_ROWS * sizeof **tabuleiro);

    if (*tabuleiro == NULL)
    {
        printf("Não foi possível criar o tabuleiro");
        return *tabuleiro = NULL;
    }
    else
    {
        for (int i = 0; i < N_ROWS; i++)
        {
            (*tabuleiro)[i] = malloc((size_t)N_COLS * sizeof *(*tabuleiro)[i]);

            if ((*tabuleiro)[i] == NULL)
            {
                for (int j = 0; j < i; j++)
                {
                    free((*tabuleiro)[j]);
                }
                free(*tabuleiro);
                *tabuleiro = NULL;
            } else {
                for (int j = 0; j < N_COLS; j++)
                {
                    (*tabuleiro)[i][j] = 0;
                }
            }
        }

        return *tabuleiro;
    }
}

void limpar_tabuleiro(int **tabuleiro, int N_ROWS)
{
    for (int i = 0; i < N_ROWS; i++)
    {
        free(tabuleiro[i]);
    }
    free(tabuleiro);
}

void exibir_tabuleiro(int **tabuleiro, int N_ROWS, int N_COLS)
{
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            if(tabuleiro[i][j] == -1)
            {
                printf("X ");
            }
            else
            {
                printf("%d ", tabuleiro[i][j]);
            }
        }
        printf("\n");
    }
}