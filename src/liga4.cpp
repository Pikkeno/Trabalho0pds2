#include "Liga4.hpp"
#include <iostream>

Liga4::Liga4(int linhas, int colunas) : JogoDeTabuleiro(linhas, colunas) {}

// Liga4 implementação só pro liga4
bool Liga4::jogar(int linha, int coluna, char jogador) {
    // Liga4 só usa a coluna
    return this->jogar(coluna, jogador);  // mudar para jogar(coluna, jogador) para usar a função específica
}

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
    // condições de vitória
    char currentPlayer;

    // Horizontal Check
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas - 3; j++) {
            currentPlayer = tabuleiro[i][j];
            if (currentPlayer != ' ' &&
                currentPlayer == tabuleiro[i][j+1] &&
                currentPlayer == tabuleiro[i][j+2] &&
                currentPlayer == tabuleiro[i][j+3]) {
                return true;
            }
        }
    }

    // check vertical
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas; j++) {
            currentPlayer = tabuleiro[i][j];
            if (currentPlayer != ' ' &&
                currentPlayer == tabuleiro[i+1][j] &&
                currentPlayer == tabuleiro[i+2][j] &&
                currentPlayer == tabuleiro[i+3][j]) {
                return true;
            }
        }
    }

    // diagonal ascendente
    for (int i = 3; i < linhas; i++) {
        for (int j = 0; j < colunas - 3; j++) {
            currentPlayer = tabuleiro[i][j];
            if (currentPlayer != ' ' &&
                currentPlayer == tabuleiro[i-1][j+1] &&
                currentPlayer == tabuleiro[i-2][j+2] &&
                currentPlayer == tabuleiro[i-3][j+3]) {
                return true;
            }
        }
    }

    // descendent diagonal
    for (int i = 0; i < linhas - 3; i++) {
        for (int j = 0; j < colunas - 3; j++) {
            currentPlayer = tabuleiro[i][j];
            if (currentPlayer != ' ' &&
                currentPlayer == tabuleiro[i+1][j+1] &&
                currentPlayer == tabuleiro[i+2][j+2] &&
                currentPlayer == tabuleiro[i+3][j+3]) {
                return true;
            }
        }
    }

    return false;
}
