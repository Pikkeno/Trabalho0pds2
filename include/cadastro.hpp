/**
 * @file Cadastro.hpp
 * @brief Definição da classe Cadastro, que gerencia jogadores.
 */

#ifndef CADASTRO_HPP
#define CADASTRO_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "Jogador.hpp"
#include <map>
#include <string>

/**
 * @class Cadastro
 * @brief Classe responsável por gerenciar os jogadores, incluindo adição, remoção e listagem.
 */
class Cadastro {
private:
    /**
     * @brief Mapa que armazena os jogadores registrados, onde a chave é o apelido do jogador.
     */
    std::map<std::string, Jogador> jogadores;

public:
    /**
     * @brief Construtor padrão da classe Cadastro.
     */
    Cadastro();

    /**
     * @brief Adiciona um novo jogador ao cadastro.
     * @param apelido O apelido do jogador.
     * @param nome O nome completo do jogador.
     * @return true se o jogador foi adicionado com sucesso, false caso o apelido já exista.
     */
    bool adicionarJogador(const std::string& apelido, const std::string& nome);

    /**
     * @brief Remove um jogador do cadastro com base no apelido.
     * @param apelido O apelido do jogador a ser removido.
     * @return true se o jogador foi removido com sucesso, false caso o apelido não seja encontrado.
     */
    bool removerJogador(const std::string& apelido);

    /**
     * @brief Exibe a lista de jogadores cadastrados.
     */
    void listarJogadores() const;

    /**
     * @brief Obtém um jogador com base no apelido.
     * @param apelido O apelido do jogador.
     * @return Ponteiro para o jogador, ou nullptr se não encontrado.
     */
    Jogador* obterJogador(const std::string& apelido);

    /**
     * @brief Obtém todos os jogadores cadastrados.
     * @return Referência ao mapa contendo os jogadores.
     * 
     * Esta função é utilizada pelo Gerente para acessar todos os jogadores.
     */
    std::map<std::string, Jogador>& getJogadores();

    /**
     * @brief Exibe os detalhes de todos os jogadores cadastrados.
     */
    void exibirJogadores() const;
};

#endif // CADASTRO_HPP