#ifndef LIGA4_HPP
#define LIGA4_HPP

#include "tabuleiro.hpp" // Inclui a classe base

class Liga4 : public JogoDeTabuleiro {
public:
    // Construtor
    Liga4();

    // Sobrescrita do método jogar (comportamento específico de Liga4)
    bool jogar(int linha, int coluna, char jogador) override;

    // Sobrescrita do método verificar vitória
    bool verificarVitoria(char jogador) const override;

    // Sobrescrita do método exibir tabuleiro (opcional)
    void exibirTabuleiro() const override;
};

#endif // LIGA4_HPP
