#include "jogador.hpp"
#include <iostream>

jogador::jogador(const std::string& apelido, const std::string& nome) 
    : apelido(apelido), nome(nome) {}

std::string jogador::getapelido() const { return apelido; }
std::string jogador::getNome() const { return nome; }

void jogador::registrarV(const std::string& jogo) {
    if (jogo == "Reversi") vitoriasReversi++;
    else if (jogo == "Lig4") vitoriasLiga4++;
    else if (jogo == "Velha") vitoriasVelha++;
}

void jogador::registrarD(const std::string& jogo) {
    if (jogo == "Reversi") derrotaReversi++;
    else if (jogo == "Lig4") derrotaLiga4++;
    else if (jogo == "Velha") derrotaVelha++;
}

void jogador::exibirE() const {
    std::cout << apelido << " (" << nome << "):\n"
              << "Reversi - Vitórias: " << vitoriasReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriasLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriasVelha << ", Derrotas: " << derrotaVelha << "\n";
}
