
/**
 * @file tabuleiro.cpp
 * @brief Implementação genérica do tabuleiro para jogos de tabuleiro.
 */

#include "tabuleiro.hpp"

/**
 * @brief Construtor da classe JogoDeTabuleiro.
 * @param linhas O número de linhas do tabuleiro.
 * @param colunas O número de colunas do tabuleiro.
 */

JogoDeTabuleiro::JogoDeTabuleiro(int linhas, int colunas)
    : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, ' ')) {}

/**
 * @brief Exibe o estado atual do tabuleiro.
 */

void JogoDeTabuleiro::exibirTabuleiro() const {
    for (const auto& linha : tabuleiro) {
        for (char celula : linha) {
            std::cout << (celula == ' ' ? '.' : celula) << " ";
        }
        std::cout << "\n";
    }
}

/**
 * @brief Metodos para obter o número de linhas, colunas e o conteúdo de uma posição do tabuleiro.(para uso em testes)
 */
int JogoDeTabuleiro::getLinhas() const {
    return linhas;
}

int JogoDeTabuleiro::getColunas() const {
    return colunas;
}

char JogoDeTabuleiro::getPosicao(int linha, int coluna) const {
    if (linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas) {
        return tabuleiro[linha][coluna];
    }
    // Retorna um caractere nulo para indicar posição inválida
    return '\0';
}
