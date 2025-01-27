/**
 * @file Liga4.hpp
 * @brief Definição da classe Liga4, que implementa as regras do jogo Liga4.
 */

#ifndef LIGA4_HPP
#define LIGA4_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "tabuleiro.hpp"

/**
 * @class Liga4
 * @brief Classe que gerencia o jogo Liga4, incluindo as regras e a verificação de vitórias.
 */
class Liga4 : public JogoDeTabuleiro {
public:
    /**
     * @brief Construtor do jogo Liga4.
     * @param linhas O número de linhas do tabuleiro (padrão: 6).
     * @param colunas O número de colunas do tabuleiro (padrão: 7).
     */
    Liga4(int linhas = 6, int colunas = 7);

    /**
     * @brief Realiza uma jogada no jogo Liga4.
     * @param linha Ignorado (necessário para satisfazer a interface da classe base).
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    virtual bool jogar(int linha, int coluna, char jogador) override;

    /**
     * @brief Verifica se houve um vencedor no jogo Liga4.
     * @return true se houve um vencedor, false caso contrário.
     */
    virtual bool verificarVitoria() const override;

    /**
     * @brief Obtém o nome do jogo.
     * @return Uma string com o nome "Liga4".
     */
    std::string getNome() const override {
        return "Liga4";
    }

private:
    /**
     * @brief Realiza uma jogada no jogo Liga4 usando apenas a coluna especificada.
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    bool jogar(int coluna, char jogador);
};

#endif // LIGA4_HPP