// src/CadastroJogadores.cpp
#include "cadastro.hpp"
#include <fstream>

Cadastrar::Cadastrar() {
   bool carregarDados();
}

bool Cadastrar::cadastrar(const std::string& apelido, const std::string& nome) {
    if (jogadores.find(apelido) != jogadores.end()) {
        std::cerr << "ERRO: jogador com apelido \"" << apelido << "\" já existe.\n";
        return false;
    }
    jogadores[apelido] = jogador(apelido, nome);
    salvarDados();
    std::cout << "Jogador \"" << apelido << "\" cadastrado com sucesso!\n";
    return true;
}

bool Cadastrar::remover(const std::string& apelido) {
    if (jogadores.erase(apelido) == 0) {
        std::cerr << "ERRO: jogador \"" << apelido << "\" não encontrado.\n";
        return false;
    }
    salvarDados();
    std::cout << "Jogador \"" << apelido << "\" removido com sucesso!\n";
    return true;
}

void Cadastrar::listar() const {
    for (const auto& [apelido, jogador] : jogadores) {
        jogador.exibirE();
    }
}

void Cadastrar::salvarDados() const {
    std::ofstream arquivo("jogadores.txt");
    for (const auto& [apelido, jogador] : jogadores) {
        arquivo << jogador.getapelido() << " " << jogador.getNome() << "\n";
    }
}

void cadastrarJogadores::carregarDados() {
    std::ifstream arquivo("jogadores.txt");
    std::string apelido, nome;
    while (arquivo >> apelido >> nome) {
        jogadores[apelido] = jogador(apelido, nome);
    }
}
