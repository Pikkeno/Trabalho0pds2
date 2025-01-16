#include "jogador.hpp"
#include <iostream>

jogador::jogador(const std::string& apelido, const std::string& nome) 
    : apelido(apelido), nome(nome) {}

std::string jogador::getapelido() const { return apelido; }
std::string jogador::getNome() const { return nome; }

void jogador::registrarV(const std::string& jogo) {
    if (jogo == "Reversi") vitoriaReversi++;
    else if (jogo == "Lig4") vitoriaLiga4++;
    else if (jogo == "Velha") vitoriaVelha++;
}

void jogador::registrarD(const std::string& jogo) {
    if (jogo == "Reversi") derrotaReversi++;
    else if (jogo == "Lig4") derrotaLiga4++;
    else if (jogo == "Velha") derrotaVelha++;
}

void jogador::exibirE() const {
    std::cout << apelido << " (" << nome << "):\n"
              << "Reversi - Vitórias: " << vitoriaReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriaLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriaVelha << ", Derrotas: " << derrotaVelha << "\n";
}
