#ifndef LIGA4_HPP
#define LIGA4_HPP

#include "tabuleiro.hpp"

class Liga4 : public JogoDeTabuleiro {
public:
    Liga4(int linhas = 6, int colunas = 7);
    bool jogar(int coluna, char jogador) override;
    bool verificarVitoria() const override;
};

#endif // LIGA4_HPP
