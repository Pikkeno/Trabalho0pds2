
/**
 * @file velha.cpp
 * @brief Implementação do jogo Jogo da Velha.
 */

#include "JogoDaVelha.hpp"

/**
 * @brief Construtor do jogo Jogo da Velha.
 * 
 * Inicializa o tabuleiro com dimensões de 3x3.
 */

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

/**
 * @brief Realiza uma jogada no jogo Jogo da Velha.
 * @param linha A linha onde o jogador deseja jogar.
 * @param coluna A coluna onde o jogador deseja jogar.
 * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
 * @return true se a jogada foi válida, false caso contrário.
 */

bool JogoDaVelha::jogar(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {
        std::cerr << "Posiçao fora do intervalo.\n";
        return false;
    }
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return true;
    }
    std::cerr << "Posiçao já ocupada.\n";
    return false;
}

/**
 * @brief Verifica se houve um vencedor no jogo Jogo da Velha.
 * @return true se houve um vencedor, false caso contrário.
 */

bool JogoDaVelha::verificarVitoria() const {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return true; // Verifica linhas
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return true; // Verifica colunas
        }
    }
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ' ||
        tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true; // Verifica diagonais
    }
    return false;
}
