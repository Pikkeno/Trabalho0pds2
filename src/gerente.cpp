
/**
 * @file gerente.cpp
 * @brief Implementação das funções de gerenciamento relacionadas ao cadastro de jogadores.
 */

#include "Gerente.hpp"
#include <fstream>
#include <iostream>
#include <sstream>

/**
 * @brief Construtor da classe Gerente.
 * @param cadastro Referência ao objeto Cadastro utilizado para manipulação dos jogadores.
 */

Gerente::Gerente(Cadastro& cadastro) : cadastro(cadastro) {}

/**
 * @brief Salva os dados dos jogadores em um arquivo.
 * 
 * Os dados dos jogadores são serializados e escritos no arquivo "jogadores_data.txt".
 */

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

/**
 * @brief Carrega os dados dos jogadores de um arquivo.
 * 
 * Lê os dados serializados do arquivo "jogadores_data.txt" e os adiciona ao cadastro.
 */

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
