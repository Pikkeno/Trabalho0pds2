#include "Reversi.hpp"
#include <iostream>

Reversi::Reversi() : JogoDeTabuleiro(8, 8) {
    // Configuração inicial do tabuleiro
    tabuleiro[3][3] = tabuleiro[4][4] = 'O';
    tabuleiro[3][4] = tabuleiro[4][3] = 'X';
}

bool Reversi::jogar(int linha, int coluna, char jogador) {
    if (linha < 0 || linha >= 8 || coluna < 0 || coluna >= 8) {
        std::cerr << "Posição fora do intervalo.\n";
        return false;
    }

    if (tabuleiro[linha][coluna] != ' ') {
        std::cerr << "Posição já ocupada.\n";
        return false;
    }

    bool validMove = false;
    char opponent = (jogador == 'X') ? 'O' : 'X';

    // Direções para verificar: N, NE, E, SE, S, SW, W, NW
    const int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
    
    for (auto direction : directions) {
        int x = linha + direction[0];
        int y = coluna + direction[1];
        bool hasOpponentBetween = false;

        while (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == opponent) {
            x += direction[0];
            y += direction[1];
            hasOpponentBetween = true;
        }

        if (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == jogador && hasOpponentBetween) {
            // Confirmar movimento e virar as peças
            x = linha + direction[0];
            y = coluna + direction[1];

            while (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == opponent) {
                tabuleiro[x][y] = jogador;
                x += direction[0];
                y += direction[1];
            }

            tabuleiro[linha][coluna] = jogador;
            validMove = true;
        }
    }

    if (!validMove) {
        std::cerr << "Jogada inválida.\n";
        return false;
    }

    return true;
}

bool Reversi::verificarVitoria() const {
    // Uma implementação possível: verificar se não existem mais movimentos válidos para ambos jogadores
    // Por enquanto, deixaremos essa função retornar false, indicando que o jogo ainda não terminou.
    return false; // Esta lógica precisa ser desenvolvida de acordo com as regras específicas.
}

void Reversi::exibirTabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            std::cout << (celula == ' ' ? '.' : celula) << " ";
        }
        std::cout << "\n";
    }
}
