// src/CadastroJogadores.cpp
#include "cadastro.hpp"
#include <fstream>

CadastroJogadores::CadastroJogadores() {
    carregarDados();
}

bool CadastroJogadores::cadastrarJogador(const std::string& apelido, const std::string& nome) {
    if (jogadores.find(apelido) != jogadores.end()) {
        std::cerr << "ERRO: jogador com apelido \"" << apelido << "\" já existe.\n";
        return false;
    }
    jogadores[apelido] = Jogador(apelido, nome);
    salvarDados();
    std::cout << "Jogador \"" << apelido << "\" cadastrado com sucesso!\n";
    return true;
}

bool CadastroJogadores::removerJogador(const std::string& apelido) {
    if (jogadores.erase(apelido) == 0) {
        std::cerr << "ERRO: jogador \"" << apelido << "\" não encontrado.\n";
        return false;
    }
    salvarDados();
    std::cout << "Jogador \"" << apelido << "\" removido com sucesso!\n";
    return true;
}

void CadastroJogadores::listarJogadores() const {
    for (const auto& [apelido, jogador] : jogadores) {
        jogador.exibirEstatisticas();
    }
}

void CadastroJogadores::salvarDados() const {
    std::ofstream arquivo("jogadores.txt");
    for (const auto& [apelido, jogador] : jogadores) {
        arquivo << jogador.getApelido() << " " << jogador.getNome() << "\n";
    }
}

void CadastroJogadores::carregarDados() {
    std::ifstream arquivo("jogadores.txt");
    std::string apelido, nome;
    while (arquivo >> apelido >> nome) {
        jogadores[apelido] = Jogador(apelido, nome);
    }
}
