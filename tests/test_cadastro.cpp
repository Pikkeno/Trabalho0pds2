#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Cadastro.hpp" // Inclua o cabeçalho da classe Cadastro

TEST_CASE("Teste da classe Cadastro") {
    Cadastro cadastro;

    SUBCASE("Adicionar jogador com apelido único") {
        CHECK(cadastro.adicionarJogador("jogador1", "Nome Completo 1") == true);
        CHECK(cadastro.getJogadores().size() == 1);
    }

    SUBCASE("Adicionar jogador com apelido duplicado") {
        cadastro.adicionarJogador("jogador1", "Nome Completo 1");
        CHECK(cadastro.adicionarJogador("jogador1", "Nome Completo 2") == false);
        CHECK(cadastro.getJogadores().size() == 1);
    }

    SUBCASE("Remover jogador existente") {
        cadastro.adicionarJogador("jogador1", "Nome Completo 1");
        CHECK(cadastro.removerJogador("jogador1") == true);
        CHECK(cadastro.getJogadores().empty() == true);
    }

    SUBCASE("Remover jogador inexistente") {
        CHECK(cadastro.removerJogador("jogadorInexistente") == false);
    }

    SUBCASE("Obter jogador existente") {
        cadastro.adicionarJogador("jogador1", "Nome Completo 1");
        Jogador* jogador = cadastro.obterJogador("jogador1");
        REQUIRE(jogador != nullptr);
        CHECK(jogador->getApelido() == "jogador1");
        CHECK(jogador->getNome() == "Nome Completo 1");
    }

    SUBCASE("Obter jogador inexistente") {
        Jogador* jogador = cadastro.obterJogador("jogadorInexistente");
        CHECK(jogador == nullptr);
    }
}
