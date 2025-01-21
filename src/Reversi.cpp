#include "Reversi.hpp"

Reversi::Reversi() : JogoDeTabuleiro(8, 8) {
    tabuleiro[3][3] = tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = tabuleiro[4][3] = 'O';

}

bool Reversi::jogar(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || tabuleiro[linha][coluna] != ' ') {
        std::cerr << "Jogada inválida.\n";
        return false;
    }
    tabuleiro[linha][coluna] = jogador;
    return true;
}

bool Reversi::verificarVitoria(char jogador) const {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < linhas; ++i)
        for (int j = 0; j < colunas; ++j)
            if (tabuleiro[i][j] == jogador)
                return true;

    return false;
}