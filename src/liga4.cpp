
/**
 * @file liga4.cpp
 * @brief Implementação das regras do jogo Liga4.
 */

#include "Liga4.hpp"
#include <iostream>

/**
 * @brief Construtor da classe Liga4.
 * @param linhas O número de linhas do tabuleiro.
 * @param colunas O número de colunas do tabuleiro.
 */

Liga4::Liga4(int linhas, int colunas) : JogoDeTabuleiro(linhas, colunas) {}

// Liga4 implementação só pro liga4

/**
 * @brief Realiza uma jogada no jogo Liga4 especificando a linha e a coluna.
 * @param linha A linha onde o jogador deseja jogar (não utilizado em Liga4).
 * @param coluna A coluna onde o jogador deseja jogar.
 * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
 * @return true se a jogada foi válida, false caso contrário.
 */

bool Liga4::jogar(int linha, int coluna, char jogador) {
    // Liga4 só usa a coluna
    return this->jogar(coluna, jogador);  // mudar para jogar(coluna, jogador) para usar a função específica
}

/**
 * @brief Realiza uma jogada no jogo Liga4 especificando a coluna.
 * @param coluna A coluna onde o jogador deseja jogar.
 * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
 * @return true se a jogada foi válida, false caso contrário.
 */

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

/**
 * @brief Verifica se houve um vencedor no jogo Liga4.
 * @return true se houve um vencedor, false caso contrário.
 */

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
