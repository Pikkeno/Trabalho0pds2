#include "tabuleiro.hpp"

// Construtor
JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, ' ')) {}

// Exibe o tabuleiro no console
void JogoDeTabuleiro::exibirTabuleiro() const {
    for (int i = 0; i < linhas; ++i) {
        for (int j = 0; j < colunas; ++j) {
            std::cout << (tabuleiro[i][j] == ' ' ? '.' : tabuleiro[i][j]) << " ";
        }
        std::cout << "\n";
    }
}

// Limpa o tabuleiro
void JogoDeTabuleiro::resetTabuleiro() {
    for (auto& linha : tabuleiro) {
        std::fill(linha.begin(), linha.end(), ' ');
    }
}
