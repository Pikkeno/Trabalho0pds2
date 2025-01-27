
/**
 * @file jogador.cpp
 * @brief Implementação das funções relacionadas aos jogadores.
 */

#include "Jogador.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

/**
 * @brief Construtor padrão da classe Jogador.
 */

Jogador::Jogador() : Apelido(""), Nome(""), vitoriaReversi(0), derrotaReversi(0), vitoriaLiga4(0), derrotaLiga4(0), vitoriaVelha(0), derrotaVelha(0), totalVitorias(0), totalDerrotas(0) {}

/**
 * @brief Construtor da classe Jogador.
 * @param apelido O apelido do jogador.
 * @param nome O nome completo do jogador.
 */
Jogador::Jogador(const std::string& apelido, const std::string& nome) : Apelido(apelido), Nome(nome), vitoriaReversi(0), derrotaReversi(0), vitoriaLiga4(0), derrotaLiga4(0), vitoriaVelha(0), derrotaVelha(0), totalVitorias(0), totalDerrotas(0) {}

/**
 * @brief Obtém o apelido do jogador.
 * @return O apelido do jogador.
 */

std::string Jogador::getApelido() const {
    return Apelido;
}

/**
 * @brief Obtém o nome completo do jogador.
 * @return O nome completo do jogador.
 */

std::string Jogador::getNome() const {
    return Nome;
}

/**
 * @brief Obtém o total de vitórias do jogador.
 * @return O total de vitórias.
 */

int Jogador::getVitorias() const {
    return totalVitorias;
}

/**
 * @brief Obtém o total de derrotas do jogador.
 * @return O total de derrotas.
 */

int Jogador::getDerrotas() const {
    return totalDerrotas;
}

/**
 * @brief Define o total de vitórias do jogador.
 * @param vitorias O novo total de vitórias.
 */

void Jogador::setVitorias(int vitorias) {
    totalVitorias = vitorias;
}

/**
 * @brief Define o total de derrotas do jogador.
 * @param derrotas O novo total de derrotas.
 */

void Jogador::setDerrotas(int derrotas) {
    totalDerrotas = derrotas;
}

/**
 * @brief Registra uma vitória para o jogador em um jogo específico.
 * @param jogo O nome do jogo ("Reversi", "Liga4", ou "JogoDaVelha").
 */

void Jogador::registrarVitoria(const std::string& jogo) {
    if (jogo == "Reversi") vitoriaReversi++;
    else if (jogo == "Liga4") vitoriaLiga4++;
    else if (jogo == "JogoDaVelha") vitoriaVelha++;
    else {
        std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
        return;
    }
    totalVitorias++;
}

/**
 * @brief Registra uma derrota para o jogador em um jogo específico.
 * @param jogo O nome do jogo ("Reversi", "Liga4", ou "JogoDaVelha").
 */

void Jogador::registrarDerrota(const std::string& jogo) {
    if (jogo == "Reversi") derrotaReversi++;
    else if (jogo == "Liga4") derrotaLiga4++;
    else if (jogo == "JogoDaVelha") derrotaVelha++;
    else {
        std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
        return;
    }
    totalDerrotas++;
}

/**
 * @brief Reseta os dados do jogador, zerando vitórias e derrotas.
 */

void Jogador::resetJogador() {
    vitoriaReversi = derrotaReversi = 0;
    vitoriaLiga4 = derrotaLiga4 = 0;
    vitoriaVelha = derrotaVelha = 0;
    totalVitorias = totalDerrotas = 0;
}

/**
 * @brief Exibe as estatísticas do jogador.
 */

void Jogador::exibirJogador() const {
    std::cout << Apelido << " (" << Nome << "):\n"
              << "Reversi - Vitórias: " << vitoriaReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriaLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriaVelha << ", Derrotas: " << derrotaVelha << "\n"
              << "Total - Vitórias: " << totalVitorias << ", Derrotas: " << totalDerrotas << "\n";
}

/**
 * @brief Serializa os dados do jogador em uma string.
 * @return A string contendo os dados do jogador.
 */

std::string Jogador::serializar() const {
    return Apelido + " " + Nome + " " + std::to_string(vitoriaReversi) + " " + std::to_string(derrotaReversi) + " " + std::to_string(vitoriaLiga4) + " " + std::to_string(derrotaLiga4) + " " + std::to_string(vitoriaVelha) + " " + std::to_string(derrotaVelha) + " " + std::to_string(totalVitorias) + " " + std::to_string(totalDerrotas);
}

/**
 * @brief Desserializa os dados do jogador a partir de uma string.
 * @param dados A string contendo os dados do jogador.
 */

void Jogador::desserializar(const std::string& dados) {
    std::istringstream iss(dados);
    iss >> Apelido >> Nome >> vitoriaReversi >> derrotaReversi >> vitoriaLiga4 >> derrotaLiga4 >> vitoriaVelha >> derrotaVelha >> totalVitorias >> totalDerrotas;
}
