/**
 * @file Reversi.hpp
 * @brief Definição da classe Reversi, que implementa as regras do jogo Reversi.
 */

#ifndef REVERSI_HPP
#define REVERSI_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "tabuleiro.hpp"

/**
 * @class Reversi
 * @brief Classe que gerencia o jogo Reversi, incluindo as regras e a verificação de vitórias.
 */
class Reversi : public JogoDeTabuleiro {
public:
    /**
     * @brief Construtor do jogo Reversi.
     * 
     * Inicializa o tabuleiro com a configuração inicial padrão do jogo.
     */
    Reversi();

    /**
     * @brief Realiza uma jogada no jogo Reversi.
     * @param linha A linha onde o jogador deseja jogar.
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    bool jogar(int linha, int coluna, char jogador) override;

    /**
     * @brief Verifica se o jogo Reversi foi concluído.
     * @return true se o jogo terminou, false caso contrário.
     */
    bool verificarVitoria() const override;

    /**
     * @brief Exibe o estado atual do tabuleiro do jogo Reversi.
     */
    void exibirTabuleiro() const override;

    /**
     * @brief Obtém o nome do jogo.
     * @return Uma string com o nome "Reversi".
     */
    std::string getNome() const override {
        return "Reversi";
    }

private:
    /**
     * @brief Verifica se um jogador tem jogadas válidas disponíveis.
     * @param player O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se existem jogadas válidas, false caso contrário.
     */
    bool daPraandar(char player) const;
};

#endif // REVERSI_HPP