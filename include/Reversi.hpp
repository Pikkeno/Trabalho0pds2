#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "tabuleiro.hpp"

class Reversi : public JogoDeTabuleiro {
public:
    Reversi();
    bool jogar(int posicao, char jogador) override;
    bool verificarVitoria() const override;
};

#endif // REVERSI_HPP
