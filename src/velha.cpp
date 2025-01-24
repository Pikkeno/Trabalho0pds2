#include "JogoDaVelha.hpp"

JogoDaVelha::JogoDaVelha() : JogoDeTabuleiro(3, 3) {}

bool JogoDaVelha::jogar(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= 3 || coluna < 0 || coluna >= 3) {
        std::cerr << "Posição fora do intervalo.\n";
        return false;
    }
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
    if (tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[0][0] != ' ' ||
        tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[0][2] != ' ') {
        return true; // Verifica diagonais
    }
    return false;
}
