#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Gerente.hpp"
#include "Cadastro.hpp"
#include "Jogador.hpp"
#include <cstdio> // Para a função std::remove

TEST_CASE("Teste de salvamento e carregamento de dados") {
    const std::string arquivoTeste = "jogadores_data_test.txt";

    // Função auxiliar para remover o arquivo de teste após cada caso de teste
    auto removerArquivoTeste = [&]() {
        std::remove(arquivoTeste.c_str());
    };

    SUBCASE("Salvar dados de jogadores") {
        Cadastro cadastro;
        Gerente gerente(cadastro);

        // Adiciona jogadores ao cadastro
        cadastro.adicionarJogador("jogador1", "Nome Completo 1");
        cadastro.adicionarJogador("jogador2", "Nome Completo 2");

        // Define vitórias e derrotas para os jogadores
        auto* jogador1 = cadastro.obterJogador("jogador1");
        auto* jogador2 = cadastro.obterJogador("jogador2");
        if (jogador1) {
            jogador1->setVitorias(5);
            jogador1->setDerrotas(2);
        }
        if (jogador2) {
            jogador2->setVitorias(3);
            jogador2->setDerrotas(4);
        }

        // Salva os dados no arquivo de teste
        gerente.salvarDados();

        // Verifica se o arquivo foi criado
        std::ifstream arquivo(arquivoTeste);
        CHECK(arquivo.is_open());

        // Verifica o conteúdo do arquivo
        std::string linha;
        std::getline(arquivo, linha);
        CHECK(linha == "jogador1;Nome Completo 1;5;2");
        std::getline(arquivo, linha);
        CHECK(linha == "jogador2;Nome Completo 2;3;4");

        arquivo.close();
        removerArquivoTeste();
    }

    SUBCASE("Carregar dados de jogadores") {
        // Cria um arquivo de teste com dados de jogadores
        {
            std::ofstream arquivo(arquivoTeste);
            arquivo << "jogador1;Nome Completo 1;5;2\n";
            arquivo << "jogador2;Nome Completo 2;3;4\n";
        }

        Cadastro cadastro;
        Gerente gerente(cadastro);

        // Carrega os dados do arquivo de teste
        gerente.carregarDados();

        // Verifica se os jogadores foram carregados corretamente
        auto* jogador1 = cadastro.obterJogador("jogador1");
        auto* jogador2 = cadastro.obterJogador("jogador2");

        REQUIRE(jogador1 != nullptr);
        CHECK(jogador1->getApelido() == "jogador1");
        CHECK(jogador1->getNome() == "Nome Completo 1");
        CHECK(jogador1->getVitorias() == 5);
        CHECK(jogador1->getDerrotas() == 2);

        REQUIRE(jogador2 != nullptr);
        CHECK(jogador2->getApelido() == "jogador2");
        CHECK(jogador2->getNome() == "Nome Completo 2");
        CHECK(jogador2->getVitorias() == 3);
        CHECK(jogador2->getDerrotas() == 4);

        removerArquivoTeste();
    }
}
