#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi() : JogoDeTabuleiro(8, 8) {
    // Configuração inicial para Reversi
    tabuleiro[3][3] = tabuleiro[4][4] = 'X';
    tabuleiro[3][4] = tabuleiro[4][3] = 'O';
}

bool Reversi::jogar(int posicao, char jogador) {
    int linha = posicao / 8;
    int coluna = posicao % 8;
    // Adicionar lógica para verificar se a jogada é válida de acordo com as regras do Reversi
    if (tabuleiro[linha][coluna] == ' ') {
        tabuleiro[linha][coluna] = jogador;
        // Adicionar lógica para "flipping" das peças
        return true;
    }
    std::cerr << "Jogada inválida.\n";
    return false;
}

bool Reversi::verificarVitoria() const {
    // Implementar lógica para determinar o vencedor do jogo Reversi
    return false;
}
