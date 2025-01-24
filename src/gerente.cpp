#include "Gerente.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

Gerente::Gerente(Cadastro& cadastro) : cadastro(cadastro) {}

void Gerente::salvarDados() const {
    std::ofstream arquivo("jogadores_data.txt");
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    // Assumindo que getJogadores() retorna std::map<std::string, Jogador>
    const auto& jogadores = cadastro.getJogadores();
    for (const auto& par : jogadores) {
        arquivo << par.second.serializar() << "\n"; // Certifique-se de que `serializar()` fornece os dados corretos.
    }

    arquivo.close();
    std::cout << "Dados dos jogadores salvos com sucesso.\n";
}

void Gerente::carregarDados() {
    std::ifstream arquivo("jogadores_data.txt");
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para leitura.\n";
        return;
    }

    std::string linha;
    while (std::getline(arquivo, linha)) {
        Jogador novoJogador;
        novoJogador.desserializar(linha);
        cadastro.adicionarJogador(novoJogador.getApelido(), novoJogador.getNome());
        // Configura vitórias e derrotas após adicionar ao cadastro
        Jogador* jogador = cadastro.obterJogador(novoJogador.getApelido());
        if (jogador) {
            jogador->setVitorias(novoJogador.getVitorias());
            jogador->setDerrotas(novoJogador.getDerrotas());
        }
    }

    arquivo.close();
    std::cout << "Dados dos jogadores carregados com sucesso.\n";
}
