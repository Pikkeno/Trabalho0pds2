// tabuleiro.hpp
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

    virtual bool jogar(int linha, int coluna, char jogador) = 0;
    virtual bool jogar(int coluna, char jogador) { return false; }
    virtual bool verificarVitoria() const = 0;
    virtual void exibirTabuleiro() const ;
    virtual std::string getNome() const { return "JogoDeTabuleiro"; }
};
#endif