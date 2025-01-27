/**
 * @file JogoDaVelha.hpp
 * @brief Definição da classe JogoDaVelha, que implementa as regras do jogo da velha.
 */

#ifndef JOGODAVELHA_HPP
#define JOGODAVELHA_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "tabuleiro.hpp"

/**
 * @class JogoDaVelha
 * @brief Classe que gerencia o jogo da velha, incluindo as regras e a verificação de vitórias.
 */
class JogoDaVelha : public JogoDeTabuleiro {
public:
    /**
     * @brief Construtor do jogo da velha.
     * 
     * Inicializa o tabuleiro do jogo com dimensões de 3x3.
     */
    JogoDaVelha();

    /**
     * @brief Realiza uma jogada no jogo da velha.
     * @param linha A linha onde o jogador deseja jogar.
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    bool jogar(int linha, int coluna, char jogador) override;

    /**
     * @brief Verifica se houve um vencedor no jogo da velha.
     * @return true se houve um vencedor, false caso contrário.
     */
    bool verificarVitoria() const override;

    /**
     * @brief Obtém o nome do jogo.
     * @return Uma string com o nome "JogoDaVelha".
     */
    std::string getNome() const override {
        return "JogoDaVelha";
    }
};

#endif // JOGODAVELHA_HPP
