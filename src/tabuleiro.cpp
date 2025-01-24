#include "tabuleiro.hpp"

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, ' ')) {}

void JogoDeTabuleiro::exibirTabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            std::cout << (celula == ' ' ? '.' : celula) << " ";
        }
        std::cout << "\n";
    }
}