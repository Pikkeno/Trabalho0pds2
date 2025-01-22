#include "tabuleiro.hpp"

class Liga4 : public JogoDeTabuleiro {
public:
    Liga4() : JogoDeTabuleiro(6, 7) {}

    // Implementação do método jogar
    bool jogar(int linha, int coluna, char jogador) override {
        if (coluna < 0 || coluna >= colunas) {
            std::cerr << "Coluna inválida.\n";
            return false;
        }
        if (jogador != 'X' && jogador != 'O') {
            std::cerr << "Jogador inválido.\n";
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

    // Implementação do método verificarVitoria
    bool verificarVitoria(char jogador) const override {
        // Verificar linhas
        for (int i = 0; i < linhas; ++i) {
            for (int j = 0; j <= colunas - 4; ++j) {
                if (tabuleiro[i][j] == jogador &&
                    tabuleiro[i][j + 1] == jogador &&
                    tabuleiro[i][j + 2] == jogador &&
                    tabuleiro[i][j + 3] == jogador) {
                    return true;
                }
            }
        }
        // Verificar colunas, diagonais principais e secundárias (similar ao anterior)
        return false;
    }

    // Implementação personalizada para exibir o tabuleiro
    void exibirTabuleiro() const override {
        for (const auto& linha : tabuleiro) {
            for (const auto& celula : linha) {
                std::cout << (celula == ' ' ? '.' : celula) << " ";
            }
            std::cout << "\n";
        }
    }
};
