#include "gerente.hpp"
#include <iostream>
#include <fstream>

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