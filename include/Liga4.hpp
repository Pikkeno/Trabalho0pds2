#ifndef LIGA4_HPP
#define LIGA4_HPP

#include "tabuleiro.hpp"

class Liga4 : public JogoDeTabuleiro {
public:
    Liga4(int linhas = 6, int colunas = 7);
    virtual bool jogar(int linha, int coluna, char jogador) override;  // Override to satisfy base class requirement
    virtual bool verificarVitoria() const override;
    std::string getNome() const override {
        return "Liga4";
    }

private:
    bool jogar(int coluna, char jogador);  // Liga4 specific play method that uses only column
};

#endif // LIGA4_HPP
