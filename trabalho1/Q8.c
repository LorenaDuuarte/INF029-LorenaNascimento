#include <stdio.h>
#include <stdlib.h> 

//CÓDIGO EXECUTA APENAS NO TERMINAL

void imprime_tabuleiro(char tabuleiro[3][3], char jogador_atual) {

    printf("Jogo da Velha\n");
    
    printf("Jogador '%c'\n\n", jogador_atual); 

    printf("   1 | 2 | 3\n");
    printf("  --------------\n");

    printf("A  %c | %c | %c\n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("  --------------\n");
    
    printf("B  %c | %c | %c\n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("  --------------\n");

    printf("C  %c | %c | %c\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}


void jogoVelha() {
    char tabuleiro[3][3], jogador;
    int i, j, linha, coluna, rodada, ganhou;

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }

    ganhou = 0;

    for (rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {


        jogador = (rodada % 2 == 1 ? 'X' : 'O');


        imprime_tabuleiro(tabuleiro, jogador);

        do {
            printf("\nJOGADOR '%c':\n", jogador);
            printf("Informe a linha e a coluna (valores de 1 a 3, ex: 2 3 para B3): ");
            

            if (scanf("%d %d", &linha, &coluna) != 2) {
                while (getchar() != '\n');
                linha = 0; 
                coluna = 0; 
            }

        } while (linha < 1 || linha > 3 ||
                 coluna < 1 || coluna > 3 ||
                 tabuleiro[linha-1][coluna-1] != ' '); 

        tabuleiro[linha-1][coluna-1] = jogador;


        if (tabuleiro[linha-1][0] == jogador &&
            tabuleiro[linha-1][1] == jogador &&
            tabuleiro[linha-1][2] == jogador) {
            ganhou = 1;
        }

        else if (tabuleiro[0][coluna-1] == jogador &&
                 tabuleiro[1][coluna-1] == jogador &&
                 tabuleiro[2][coluna-1] == jogador) {
            ganhou = 1;
        }

        else if (linha == coluna &&
                 tabuleiro[0][0] == jogador &&
                 tabuleiro[1][1] == jogador &&
                 tabuleiro[2][2] == jogador) {
            ganhou = 1;
        }

        else if (linha + coluna == 4 && 
                 tabuleiro[0][2] == jogador &&
                 tabuleiro[1][1] == jogador &&
                 tabuleiro[2][0] == jogador) {
            ganhou = 1;
        }
    }

    imprime_tabuleiro(tabuleiro, jogador); 

    if (ganhou)
        printf("\n Jogador '%c' venceu!\n", jogador);
    else
        printf("\n Deu velha!\n");
}

int main() {
    jogoVelha();
    return 0;
}