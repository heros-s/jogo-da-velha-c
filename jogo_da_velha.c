#include <stdio.h>

void mostra_tabuleiro(char tabuleiro[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("-----------\n");
    }
    printf("\n");
}

int testa_vencedor(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ')
            return 1;
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ')
            return 1;
    }

    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ')
        return 1;
    if (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ')
        return 1;

    return 0;
}

int vazia(char tabuleiro[3][3], int linha, int coluna) {
    return tabuleiro[linha][coluna] == ' ';
}

int main() {
    char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int linha, coluna, jogador = 1, jogadas = 0;

    do {
        jogador = (jogador % 2) ? 1 : 2;

        mostra_tabuleiro(tabuleiro);

        printf("jogador %d, escolha sua casa (linha e coluna): ", jogador);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (vazia(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = (jogador == 1) ? 'X' : 'O';
            jogadas++;
        } else {
            printf("celula ocupada. tente novamente.\n");
            continue;
        }

        if (testa_vencedor(tabuleiro)) {
            mostra_tabuleiro(tabuleiro);
            printf("parabens! o jogador %d venceu!\n", jogador);
            break;
        }

        if (jogadas == 9) {
            mostra_tabuleiro(tabuleiro);
            printf("empate!\n");
            break;
        }

        jogador++;
    } while (1);

    return 0;
}
