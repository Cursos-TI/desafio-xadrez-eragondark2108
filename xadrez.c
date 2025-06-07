#include <stdio.h>

// Função recursiva para mover o bispo 5 casas na diagonal direita para cima
void moverBispo(int x, int y, int passos) {
    if (passos == 0) return;
    x++;
    y--;
    printf("Bispo -> (%d, %d)\n", x, y);
    moverBispo(x, y, passos - 1);
}

// Função recursiva para mover a torre 5 casas para a direita
void moverTorre(int x, int y, int passos) {
    if (passos == 0) return;
    x++;
    printf("Torre -> (%d, %d)\n", x, y);
    moverTorre(x, y, passos - 1);
}

// Função recursiva para mover a rainha 8 casas para a esquerda
void moverRainha(int x, int y, int passos) {
    if (passos == 0) return;
    x--;
    printf("Rainha -> (%d, %d)\n", x, y);
    moverRainha(x, y, passos - 1);
}

// Loop aninhado para movimentação do cavalo em L (1 vez para cima à direita)
void moverCavalo(int x, int y) {
    int movimentos[8][2] = {
        {1, 2}, {2, 1}, {-1, 2}, {-2, 1},
        {1, -2}, {2, -1}, {-1, -2}, {-2, -1}
    };
    printf("Cavalo - posições possíveis a partir de (%d, %d):\n", x, y);
    for (int i = 0; i < 8; i++) {
        int nx = x + movimentos[i][0];
        int ny = y + movimentos[i][1];
        // Apenas um movimento em L para cima à direita: {1, -2} e {2, -1} são para cima
        if ((movimentos[i][0] > 0 && movimentos[i][1] < 0)) {
            printf("Cavalo -> (%d, %d)\n", nx, ny);
        }
    }
}

int main() {
    int x = 4, y = 4; // Posição inicial central para referência

    printf("Movimentação Bispo (5 casas na diagonal direita para cima):\n");
    moverBispo(x, y, 5);

    printf("\nMovimentação Torre (5 casas para a direita):\n");
    moverTorre(x, y, 5);

    printf("\nMovimentação Rainha (8 casas para a esquerda):\n");
    moverRainha(x, y, 8);

    printf("\nMovimentação Cavalo (1 vez em L para cima à direita):\n");
    moverCavalo(x, y);

    return 0;
}
