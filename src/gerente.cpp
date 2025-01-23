#include "Gerente.hpp"
#include <iostream>
#include <fstream>

Gerente::Gerente(Cadastro& cadastro) : cadastro(cadastro) {}

void Gerente::salvarDados() const {
    std::ofstream arquivo("jogadores_data.txt");
    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo para escrita.\n";
        return;
    }

    // Assumindo que getJogadores() retorna std::map<std::string, Jogador>
    const auto& jogadores = cadastro.getJogadores();  // Corrigindo o nome do método para getJogadores()
    for (const auto& par : jogadores) {
        arquivo << par.first << ";" << par.second.serializar() << "\n"; // Supõe que 'serializar()' retorna uma string com dados do jogador
    }

    arquivo.close();
    std::cout << "Dados dos jogadores salvos com sucesso.\n";
}
