// Reversi.hpp
#ifndef REVERSI_HPP
#define REVERSI_HPP

#include "tabuleiro.hpp"

class Reversi : public JogoDeTabuleiro {
public:
    Reversi();
    bool jogar(int linha, int coluna, char jogador) override;
    bool verificarVitoria() const override;
    void exibirTabuleiro() const override; // Apenas declaração
    std::string getNome() const override {
        return "Reversi";}

private:
    bool daPraandar(char player) const;
};

#endif // REVERSI_HPP