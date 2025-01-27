/**
 * @file tabuleiro.hpp
 * @brief Definição da classe base JogoDeTabuleiro para criação de jogos de tabuleiro genéricos.
 */

#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include <vector>
#include <iostream>

/**
 * @class JogoDeTabuleiro
 * @brief Classe base abstrata para criar e gerenciar jogos de tabuleiro.
 */
class JogoDeTabuleiro {
protected:
    /**
     * @brief Matriz que representa o tabuleiro do jogo.
     */
    std::vector<std::vector<char>> tabuleiro;

    /**
     * @brief Número de linhas do tabuleiro.
     */
    int linhas;

    /**
     * @brief Número de colunas do tabuleiro.
     */
    int colunas;

public:
    /**
     * @brief Construtor da classe JogoDeTabuleiro.
     * @param linhas O número de linhas do tabuleiro.
     * @param colunas O número de colunas do tabuleiro.
     */
    JogoDeTabuleiro(int linhas, int colunas);

    /**
     * @brief Destrutor virtual da classe JogoDeTabuleiro.
     */
    virtual ~JogoDeTabuleiro() {}

    /**
     * @brief Realiza uma jogada em uma posição específica do tabuleiro.
     * @param linha A linha onde o jogador deseja jogar.
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    virtual bool jogar(int linha, int coluna, char jogador) = 0;

    /**
     * @brief Realiza uma jogada baseada apenas na coluna (implementação padrão).
     * @param coluna A coluna onde o jogador deseja jogar.
     * @param jogador O símbolo do jogador (ex.: 'X' ou 'O').
     * @return true se a jogada foi válida, false caso contrário.
     */
    virtual bool jogar(int coluna, char jogador) { return false; }

    /**
     * @brief Verifica se houve um vencedor no jogo.
     * @return true se houve um vencedor, false caso contrário.
     */
    virtual bool verificarVitoria() const = 0;

    /**
     * @brief Exibe o estado atual do tabuleiro.
     */
    virtual void exibirTabuleiro() const;

    int getLinhas() const { return linhas; }
    int getColunas() const { return colunas; }
    char getPosicao(int linha, int coluna) const { return tabuleiro[linha][coluna]; }

    /**
     * @brief Obtém o nome do jogo.
     * @return Uma string com o nome "JogoDeTabuleiro" (padrão).
     */
    virtual std::string getNome() const { return "JogoDeTabuleiro"; }
};

#endif