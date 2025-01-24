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
    bool hasEmpty = false;  // Verifica se há espaços vazios
    int countX = 0, countO = 0;  // Contadores para as peças de cada jogador

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == ' ') {
                hasEmpty = true;
            } else if (tabuleiro[i][j] == 'X') {
                countX++;
            } else if (tabuleiro[i][j] == 'O') {
                countO++;
            }
        }
    }

    // Verificar se existem movimentos válidos para ambos os jogadores
    bool canMoveX = daPraandar('X');
    bool canMoveO = daPraandar('O');

    // Se não há espaços vazios ou nenhum jogador pode se mover, o jogo termina
    if (!hasEmpty || (!canMoveX && !canMoveO)) {
        std::cout << "Fim do jogo!\n";
        std::cout << "Pontuação -> X: " << countX << ", O: " << countO << "\n";
        return true;
    }

    return false;
}

bool Reversi::daPraandar(char player) const {
    char opponent = (player == 'X') ? 'O' : 'X';
    const int directions[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (tabuleiro[i][j] == ' ') {
                for (auto& dir : directions) {
                    int x = i + dir[0];
                    int y = j + dir[1];
                    bool hasOpponentBetween = false;

                    while (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == opponent) {
                        x += dir[0];
                        y += dir[1];
                        hasOpponentBetween = true;
                    }

                    if (x >= 0 && x < 8 && y >= 0 && y < 8 && tabuleiro[x][y] == player && hasOpponentBetween) {
                        return true;  // Há pelo menos um movimento válido
                    }
                }
            }
        }
    }
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
