#include "Cadastro.hpp"
#include <iostream>


Cadastro::Cadastro() {}

bool Cadastro::adicionarJogador(const std::string& apelido, const std::string& nome) {
    if (jogadores.find(apelido) != jogadores.end()) {
        std::cerr << "Erro: Jogador com apelido '" << apelido << "' já está cadastrado.\n";
        return false;
    }
    jogadores[apelido] = Jogador(apelido, nome);
    return true;
}

bool Cadastro::removerJogador(const std::string& apelido) {
    if (jogadores.erase(apelido) == 0) {
        std::cerr << "Erro: Jogador com apelido '" << apelido << "' não encontrado.\n";
        return false;
    }
    return true;
}

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

std::map<std::string, Jogador>& Cadastro::getJogadores() {
    return jogadores;
}

Jogador* Cadastro::obterJogador(const std::string& apelido) {
    auto it = jogadores.find(apelido);
    if (it != jogadores.end()) {
        return &it->second;
    }
    return nullptr;
}
