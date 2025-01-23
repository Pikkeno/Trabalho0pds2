#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include "tabuleiro.hpp"

class JogoDaVelha : public JogoDeTabuleiro {
public:
    JogoDaVelha();
    bool jogar(int posicao, char jogador) override;
    bool verificarVitoria() const override;
};

#endif // JOGODAVELHA_HPP
