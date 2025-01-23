#include "JogoDaVelha.hpp"
#include <iostream>

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

bool JogoDaVelha::jogar(int posicao, char jogador) {
    int linha = posicao / 3;
    int coluna = posicao % 3;
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        return true;
    }
    std::cerr << "Posição já ocupada.\n";
    return false;
}

bool JogoDaVelha::verificarVitoria() const {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != ' ') {
            return true; // Verifica linhas
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != ' ') {
            return true; // Verifica colunas
        }
    }
    // Verifica diagonais
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ' ||
        tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true;
    }
    return false;
}
