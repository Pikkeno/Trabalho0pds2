#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP

#include "tabuleiro.hpp"

class JogoDaVelha : public JogoDeTabuleiro {
public:
    JogoDaVelha();
    bool jogar(int linha,int coluna, char jogador) override;
    bool verificarVitoria() const override;
    std::string getNome() const override {
        return "JogoDaVelha";
    }
};

#endif // JOGODAVELHA_HPP
