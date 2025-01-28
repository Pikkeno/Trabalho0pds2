
/**
 * @file cadastro.cpp
 * @brief Implementação das funções relacionadas ao cadastro de jogadores.
 */

#include "Cadastro.hpp"
#include <iostream>

/**
 * @brief Construtor padrão da classe Cadastro.
 */

Cadastro::Cadastro() {}

/**
 * @brief Adiciona um novo jogador ao cadastro.
 * @param apelido O apelido do jogador.
 * @param nome O nome completo do jogador.
 * @return true se o jogador foi adicionado com sucesso, false caso contrário.
 */

bool Cadastro::adicionarJogador(const std::string& apelido, const std::string& nome) {
    if (jogadores.find(apelido) != jogadores.end()) {
        std::cerr << "Erro: Jogador com apelido '" << apelido << "' ja esta cadastrado.\n";
        return false;
    }
    jogadores[apelido] = Jogador(apelido, nome);
    return true;
}

/**
 * @brief Remove um jogador do cadastro.
 * @param apelido O apelido do jogador a ser removido.
 * @return true se o jogador foi removido com sucesso, false caso contrário.
 */

bool Cadastro::removerJogador(const std::string& apelido) {
    if (jogadores.erase(apelido) == 0) {
        std::cerr << "Erro: Jogador com apelido '" << apelido << "' nao encontrado.\n";
        return false;
    }
    return true;
}

/**
 * @brief Exibe a lista de jogadores cadastrados.
 */

void Cadastro::exibirJogadores() const {
    if (jogadores.empty()) {
        std::cout << "Nenhum jogador cadastrado.\n";
    } else {
        std::cout << "Lista de Jogadores:\n";
        for (const auto& par : jogadores) {
             par.second.exibirJogador(); '\n';
             std::cout << "-----------\n";
        }
    }
}

/**
 * @brief Obtém o mapa de jogadores cadastrados.
 * @return Referência ao mapa contendo os jogadores.
 */

std::map<std::string, Jogador>& Cadastro::getJogadores() {
    return jogadores;
}

/**
 * @brief Obtém um jogador específico com base no apelido.
 * @param apelido O apelido do jogador.
 * @return Ponteiro para o jogador, ou nullptr se não encontrado.
 */

Jogador* Cadastro::obterJogador(const std::string& apelido) {
    auto it = jogadores.find(apelido);
    if (it != jogadores.end()) {
        return &it->second;
    }
    return nullptr;
}
