#include "jogador.hpp"
#include <iostream>
#include <algorithm>

Jogador::Jogador() : Apelido(""), Nome("") {}
Jogador::Jogador(const std::string& apelido, const std::string& nome) : Apelido(apelido), Nome(nome) {}

std::string Jogador::getApelido() const { return Apelido; }
std::string Jogador::getNome() const { return Nome; }

void Jogador::registrarVitoria(const std::string& jogo) {
    if (jogo == "Reversi") vitoriaReversi++;
    else if (jogo == "Lig4") vitoriaLiga4++;
    else if (jogo == "Velha") vitoriaVelha++;
    else std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
}

void Jogador::registrarDerrota(const std::string& jogo) {
    if (jogo == "Reversi") derrotaReversi++;
    else if (jogo == "Lig4") derrotaLiga4++;
    else if (jogo == "Velha") derrotaVelha++;
    else std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
}

void Jogador::resetE() {
    vitoriaReversi = derrotaReversi = 0;
    vitoriaLiga4 = derrotaLiga4 = 0;
    vitoriaVelha = derrotaVelha = 0;
}
void Jogador::exibirE() const {
    std::cout << Apelido << " (" << Nome << "):\n"
              << "Reversi - Vitórias: " << vitoriaReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriaLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriaVelha << ", Derrotas: " << derrotaVelha << "\n";
}
std::string Jogador::serializar() const {
    return Apelido + " " + Nome + " " + std::to_string(vitoriaReversi) + " " + std::to_string(derrotaReversi) + " " + std::to_string(vitoriaLiga4) + " " + std::to_string(derrotaLiga4) + " " + std::to_string(vitoriaVelha) + " " + std::to_string(derrotaVelha);
}
void Jogador::desserializar(const std::string& dados) {
    std::istringstream iss(dados);
    iss >> Apelido >> Nome >> vitoriaReversi >> derrotaReversi >> vitoriaLiga4 >> derrotaLiga4 >> vitoriaVelha >> derrotaVelha;
}
