#include "jogador.hpp"
#include <iostream>
#include <algorithm>

jogador::jogador() : Apelido(""), Nome("") {}
jogador::jogador(const std::string& apelido, const std::string& nome) : Apelido(apelido), Nome(nome) {}

std::string jogador::getApelido() const { return Apelido; }
std::string jogador::getNome() const { return Nome; }

void jogador::registrarV(const std::string& jogo) {
    if (jogo == "Reversi") vitoriaReversi++;
    else if (jogo == "Lig4") vitoriaLiga4++;
    else if (jogo == "Velha") vitoriaVelha++;
    else std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
}

void jogador::registrarD(const std::string& jogo) {
    if (jogo == "Reversi") derrotaReversi++;
    else if (jogo == "Lig4") derrotaLiga4++;
    else if (jogo == "Velha") derrotaVelha++;
    else std::cerr << "IMPOSSIVEL REGISTRAR, JOGO INVALIDO.\n";
}

void jogador::resetE() {
    vitoriaReversi = derrotaReversi = 0;
    vitoriaLiga4 = derrotaLiga4 = 0;
    vitoriaVelha = derrotaVelha = 0;
}
void jogador::exibirE() const {
    std::cout << Apelido << " (" << Nome << "):\n"
              << "Reversi - Vitórias: " << vitoriaReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriaLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriaVelha << ", Derrotas: " << derrotaVelha << "\n";
}
std::string jogador::serializar() const {
    return Apelido + " " + Nome + " " + std::to_string(vitoriaReversi) + " " + std::to_string(derrotaReversi) + " " + std::to_string(vitoriaLiga4) + " " + std::to_string(derrotaLiga4) + " " + std::to_string(vitoriaVelha) + " " + std::to_string(derrotaVelha);
}
void jogador::desserializar(const std::string& dados) {
    std::istringstream iss(dados);
    iss >> Apelido >> Nome >> vitoriaReversi >> derrotaReversi >> vitoriaLiga4 >> derrotaLiga4 >> vitoriaVelha >> derrotaVelha;
}
