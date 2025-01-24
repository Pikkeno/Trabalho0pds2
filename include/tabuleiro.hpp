#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP

#include <vector>
#include <iostream>

class JogoDeTabuleiro {
protected:
    std::vector<std::vector<char>> tabuleiro;
    int linhas;
    int colunas;

public:
    JogoDeTabuleiro(int linhas, int colunas) : linhas(linhas), colunas(colunas), tabuleiro(linhas, std::vector<char>(colunas, ' ')) {}
    virtual ~JogoDeTabuleiro() {}

    virtual bool jogar(int linha, int coluna, char jogador) = 0;
    virtual bool jogar(int coluna, char jogador) { return false; }
    virtual bool verificarVitoria() const = 0;
    virtual void exibirTabuleiro() const {
        for (const auto& linha : tabuleiro) {
            for (char celula : linha) {
                std::cout << (celula == ' ' ? '.' : celula) << " ";
            }
            std::cout << "\n";
        }
    }
};

#endif // TABULEIRO_HPP
