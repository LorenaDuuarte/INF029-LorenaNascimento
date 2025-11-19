

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TAMANHO 9
#define TAMANHO_REAL 8

void imprime_mapa(char mapa[TAMANHO][TAMANHO]) {

    printf("--- Batalha Naval ---\n\n");
    
    for (int x = 0; x < TAMANHO; x++) {
        for (int y = 0; y < TAMANHO; y++) {
            printf(" %c ", mapa[x][y]);
        }
        printf("\n");
    }
    printf("\n");
}

int batalha(char luta)
{
    char mapa[TAMANHO][TAMANHO];
    char tiro_letra_input;
    int tiro_numero_input;
    int torpedos = 20;
    int x, y;
    int acertos = 0;
    int linha_tiro, coluna_tiro;

    for (x = 0; x < TAMANHO; x++)
    {
        for (y = 0; y < TAMANHO; y++)
        {
            mapa[x][y] = '.';
        }
    }

    mapa[0][0] = ' ';
    for (y = 1; y < TAMANHO; y++) {
        mapa[0][y] = 'A' + (y - 1);
    }

    for (x = 1; x < TAMANHO; x++) {
        mapa[x][0] = '0' + x;
    }

    char navios[TAMANHO_REAL][TAMANHO_REAL] = {0};
    
    navios[1][7] = 1; 
    navios[2][2] = 1; 
    navios[2][7] = 1; 
    navios[3][2] = 1; 
    navios[3][7] = 1; 
    navios[5][2] = 1; 
    navios[5][5] = 1; 
    navios[6][2] = 1; 
    navios[6][5] = 1; 
    navios[7][2] = 1; 
    navios[7][5] = 1; 
    navios[8][2] = 1; 

    while (torpedos > 0 && acertos < 12)
    {
        imprime_mapa(mapa);
        printf("Torpedos restantes: %d | Acertos: %d\n", torpedos, acertos);
        printf("Informe o tiro (Letra e Numero, ex: A 7): ");
        
        if (scanf(" %c %d", &tiro_letra_input, &tiro_numero_input) != 2) {
            printf("Entrada invalida. Tente novamente (ex: B 5).\n");
            while (getchar() != '\n'); 
            continue;
        }
        
        tiro_letra_input = toupper(tiro_letra_input);
        
        coluna_tiro = tiro_letra_input - 'A' + 1; 
        linha_tiro = tiro_numero_input;

        if (coluna_tiro < 1 || coluna_tiro > 8 || linha_tiro < 1 || linha_tiro > 8) {
            printf("\nCoordenadas fora do tabuleiro (A-H e 1-8). Tente novamente.\n");
            continue;
        }

        if (mapa[linha_tiro][coluna_tiro] != '.') {
             printf("\nVoce ja atirou nesta posicao (%c%d). Tente novamente.\n", 
                     tiro_letra_input, tiro_numero_input);
             continue;
        }

        if (navios[coluna_tiro][linha_tiro] == 1)
        {
            printf("\n*** BOMBA!!! *** Navio atingido em %c%d!\n", 
                    tiro_letra_input, tiro_numero_input);
            acertos++;
            mapa[linha_tiro][coluna_tiro] = 'X';
        }
        else
        {
            printf("\n... AGUA! ... Tiro perdido em %c%d.\n", 
                    tiro_letra_input, tiro_numero_input);
            mapa[linha_tiro][coluna_tiro] = 'O';
        }
        
        torpedos--;

        printf("Pressione ENTER para continuar...");
        while (getchar() != '\n'); 
        getchar();
    }

    imprime_mapa(mapa); 

    if (acertos == 12)
    {
        printf("\n\n*** Todos os navios inimigos foram afundados! Parabens, Capitao! ***\n");
        return 1;
    }
    else
    {
        printf("\n\n*** Voce ficou sem torpedos! Voce foi derrotado! ***\n");
        return 0;
    }
}

int main() {
    int resultado = batalha('S'); 

    if (resultado == 1) {
        printf("\nFIM DE JOGO: VITORIA!\n");
    } else {
        printf("\nFIM DE JOGO: DERROTA!\n");
    }
    
    return 0;
}