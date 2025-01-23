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
    JogoDeTabuleiro(int linhas, int colunas);
    virtual ~JogoDeTabuleiro() {}

    virtual bool jogar(int posicao, char jogador) = 0;
    virtual bool verificarVitoria() const = 0;
    virtual void exibirTabuleiro() const;
};

#endif // TABULEIRO_HPP
