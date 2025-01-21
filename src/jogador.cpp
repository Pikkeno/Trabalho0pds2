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

void Gerente::iniciarPartida(const std::string& tipoJogo, const std::string& apelidoJogador1, const std::string& apelidoJogador2) {
    if (jogadores.find(apelidoJogador1) == jogadores.end() || jogadores.find(apelidoJogador2) == jogadores.end()) {
        std::cerr << "ERRO: Um ou ambos os jogadores não estão cadastrados.\n";
        return;
    }

    jogador& jogador1 = jogadores[apelidoJogador1];
    jogador& jogador2 = jogadores[apelidoJogador2];

    std::cout << "Iniciando partida de " << tipoJogo << " entre " << apelidoJogador1 << " e " << apelidoJogador2 << "...\n";

    // Lógica fictícia para determinar o vencedor (a ser substituída pela lógica real do jogo)
    std::string vencedor = (rand() % 2 == 0) ? apelidoJogador1 : apelidoJogador2;

    if (vencedor == apelidoJogador1) {
        jogador1.registrarV(tipoJogo);
        jogador2.registrarD(tipoJogo);
    } else {
        jogador2.registrarV(tipoJogo);
        jogador1.registrarD(tipoJogo);
    }

    salvarDados();
    std::cout << "Partida encerrada! Vencedor: " << vencedor << "\n";
}

void Gerente::salvarDados() const {
    std::ofstream arquivo("jogadores.txt");
    for (const auto& [apelido, jogador] : jogadores) {
        arquivo << jogador.serializar() << "\n";
    }
}

void Gerente::carregarDados() {
    std::ifstream arquivo("jogadores.txt");
    std::string linha;
    while (std::getline(arquivo, linha)) {
        jogador jogador;
        jogador.desserializar(linha);
        jogadores[jogador.getApelido()] = jogador;
    }
}
