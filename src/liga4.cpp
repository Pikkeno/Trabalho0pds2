#include "Liga4.hpp"

Liga4::Liga4(int linhas, int colunas) : JogoDeTabuleiro(linhas, colunas) {}

bool Liga4::jogar(int coluna, char jogador) {
    if (coluna < 0 || coluna >= colunas) {
        std::cerr << "Coluna inválida.\n";
        return false;
    }

    for (int i = linhas - 1; i >= 0; --i) {
        if (tabuleiro[i][coluna] == ' ') {
            tabuleiro[i][coluna] = jogador;
            return true;
        }
    }

    std::cerr << "Coluna cheia.\n";
    return false;
}

bool Liga4::verificarVitoria() const {
    // Implementação da lógica de verificação de vitória
    // Simplificada para demonstração
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j <= colunas - 4; ++j) {
            if (tabuleiro[i][j] == tabuleiro[i][j+1] &&
                tabuleiro[i][j+1] == tabuleiro[i][j+2] &&
                tabuleiro[i][j+2] == tabuleiro[i][j+3] &&
                tabuleiro[i][j] != ' ') {
                return true;
            }
        }
    }
    return false;
}
