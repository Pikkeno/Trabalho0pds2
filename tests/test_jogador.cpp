#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Jogador.hpp"

TEST_CASE("Teste do construtor padrão") {
    Jogador jogador;
    CHECK(jogador.getApelido() == "");
    CHECK(jogador.getNome() == "");
    CHECK(jogador.getVitorias() == 0);
    CHECK(jogador.getDerrotas() == 0);
}

TEST_CASE("Teste do construtor com parâmetros") {
    Jogador jogador("apelido1", "Nome Completo 1");
    CHECK(jogador.getApelido() == "apelido1");
    CHECK(jogador.getNome() == "Nome Completo 1");
    CHECK(jogador.getVitorias() == 0);
    CHECK(jogador.getDerrotas() == 0);
}

TEST_CASE("Teste de registro de vitórias e derrotas") {
    Jogador jogador("apelido2", "Nome Completo 2");

    jogador.registrarVitoria("Reversi");
    CHECK(jogador.getVitorias() == 1);
    jogador.registrarVitoria("Liga4");
    CHECK(jogador.getVitorias() == 2);
   
