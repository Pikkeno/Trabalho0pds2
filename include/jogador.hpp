/**
 * @file Jogador.hpp
 * @brief Definição da classe Jogador, que gerencia informações sobre os jogadores e suas estatísticas.
 */

#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include <locale.h>
#include <string>

/**
 * @class Jogador
 * @brief Classe que representa um jogador, registrando suas vitórias, derrotas e estatísticas gerais em diferentes jogos.
 */
class Jogador {
private:
    /**
     * @brief Apelido do jogador.
     */
    std::string Apelido;

    /**
     * @brief Nome completo do jogador.
     */
    std::string Nome;

    /**
     * @brief Vitórias e derrotas no jogo Reversi.
     */
    int vitoriaReversi, derrotaReversi;

    /**
     * @brief Vitórias e derrotas no jogo Liga4.
     */
    int vitoriaLiga4, derrotaLiga4;

    /**
     * @brief Vitórias e derrotas no jogo Jogo da Velha.
     */
    int vitoriaVelha, derrotaVelha;

    /**
     * @brief Total de vitórias e derrotas em todos os jogos.
     */
    int totalVitorias;
    int totalDerrotas;

public:
    /**
     * @brief Construtor padrão da classe Jogador.
     */
    Jogador();

    /**
     * @brief Construtor que inicializa o jogador com apelido e nome.
     * @param apelido Apelido do jogador.
     * @param nome Nome completo do jogador.
     */
    Jogador(const std::string& apelido, const std::string& nome);

    /**
     * @brief Obtém o apelido do jogador.
     * @return Apelido do jogador.
     */
    std::string getApelido() const;

    /**
     * @brief Obtém o nome completo do jogador.
     * @return Nome completo do jogador.
     */
    std::string getNome() const;

    /**
     * @brief Obtém o total de vitórias do jogador.
     * @return Total de vitórias.
     */
    int getVitorias() const;

    /**
     * @brief Define o total de vitórias do jogador.
     * @param vitorias Novo total de vitórias.
     */
    void setVitorias(int vitorias);

    /**
     * @brief Obtém o total de derrotas do jogador.
     * @return Total de derrotas.
     */
    int getDerrotas() const;

    /**
     * @brief Define o total de derrotas do jogador.
     * @param derrotas Novo total de derrotas.
     */
    void setDerrotas(int derrotas);

    /**
     * @brief Registra uma vitória para o jogador em um jogo específico.
     * @param jogo Nome do jogo ("Reversi", "Liga4", ou "JogoDaVelha").
     */
    void registrarVitoria(const std::string& jogo);

    /**
     * @brief Registra uma derrota para o jogador em um jogo específico.
     * @param jogo Nome do jogo ("Reversi", "Liga4", ou "JogoDaVelha").
     */
    void registrarDerrota(const std::string& jogo);

    /**
     * @brief Reseta as estatísticas do jogador, zerando vitórias e derrotas.
     */
    void resetJogador();

    /**
     * @brief Exibe as estatísticas do jogador.
     */
    void exibirJogador() const;

    /**
     * @brief Serializa os dados do jogador em uma string.
     * @return String contendo os dados do jogador.
     */
    std::string serializar() const;

    /**
     * @brief Desserializa os dados do jogador a partir de uma string.
     * @param dados String contendo os dados do jogador.
     */
    void desserializar(const std::string& dados);
};

#endif // JOGADOR_HPP