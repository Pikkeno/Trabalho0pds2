#include "jogador.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>

Jogador::Jogador() : Apelido(""), Nome(""), vitoriaReversi(0), derrotaReversi(0), vitoriaLiga4(0), derrotaLiga4(0), vitoriaVelha(0), derrotaVelha(0), totalVitorias(0), totalDerrotas(0) {}
Jogador::Jogador(const std::string& apelido, const std::string& nome) : Apelido(apelido), Nome(nome), vitoriaReversi(0), derrotaReversi(0), vitoriaLiga4(0), derrotaLiga4(0), vitoriaVelha(0), derrotaVelha(0), totalVitorias(0), totalDerrotas(0) {}

std::string Jogador::getApelido() const {
    return Apelido;
}

std::string Jogador::getNome() const {
    return Nome;
}

int Jogador::getVitorias() const {
    return totalVitorias;
}

int Jogador::getDerrotas() const {
    return totalDerrotas;
}

void Jogador::setVitorias(int vitorias) {
    totalVitorias = vitorias;
}

void Jogador::setDerrotas(int derrotas) {
    totalDerrotas = derrotas;
}

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

void Jogador::resetE() {
    vitoriaReversi = derrotaReversi = 0;
    vitoriaLiga4 = derrotaLiga4 = 0;
    vitoriaVelha = derrotaVelha = 0;
    totalVitorias = totalDerrotas = 0;
}

void Jogador::exibirE() const {
    std::cout << Apelido << " (" << Nome << "):\n"
              << "Reversi - Vitórias: " << vitoriaReversi << ", Derrotas: " << derrotaReversi << "\n"
              << "Lig4 - Vitórias: " << vitoriaLiga4 << ", Derrotas: " << derrotaLiga4 << "\n"
              << "Velha - Vitórias: " << vitoriaVelha << ", Derrotas: " << derrotaVelha << "\n"
              << "Total - Vitórias: " << totalVitorias << ", Derrotas: " << totalDerrotas << "\n";
}

std::string Jogador::serializar() const {
    return Apelido + " " + Nome + " " + std::to_string(vitoriaReversi) + " " + std::to_string(derrotaReversi) + " " + std::to_string(vitoriaLiga4) + " " + std::to_string(derrotaLiga4) + " " + std::to_string(vitoriaVelha) + " " + std::to_string(derrotaVelha) + " " + std::to_string(totalVitorias) + " " + std::to_string(totalDerrotas);
}

void Jogador::desserializar(const std::string& dados) {
    std::istringstream iss(dados);
    iss >> Apelido >> Nome >> vitoriaReversi >> derrotaReversi >> vitoriaLiga4 >> derrotaLiga4 >> vitoriaVelha >> derrotaVelha >> totalVitorias >> totalDerrotas;
}
