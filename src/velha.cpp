#include "JogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

bool JogoDaVelha::jogar(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= linhas || coluna < 0 || coluna >= colunas || tabuleiro[linha][coluna] != ' ') {
        std::cerr << "Jogada inválida.\n";
        return false;
    }
    tabuleiro[linha][coluna] = jogador;
    return true;
}

bool JogoDaVelha::verificarVitoria(char jogador) const {
    // Verifica linhas, colunas e diagonais
    for (int i = 0; i < linhas; ++i)
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador)
            return true;

    for (int j = 0; j < colunas; ++j)
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador)
            return true;

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador)
        return true;

    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador)
        return true;

    return false;
}
