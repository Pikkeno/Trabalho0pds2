#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "JogoDaVelha.hpp"

TEST_CASE("Teste do construtor padrão") {
    JogoDaVelha jogo;
    // Verifica se o tabuleiro foi inicializado corretamente
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            CHECK(jogo.getPosicao(i, j) == ' ');
        }
    }
}

TEST_CASE("Teste de jogada válida") {
    JogoDaVelha jogo;
    // Jogador 'X' faz uma jogada válida
    CHECK(jogo.jogar(0, 0, 'X') == true);
    // Verifica se a posição foi atualizada corretamente
    CHECK(jogo.getPosicao(0, 0) == 'X');
}

TEST_CASE("Teste de jogada inválida") {
    JogoDaVelha jogo;
    // Jogador 'X' faz uma jogada válida
    CHECK(jogo.jogar(0, 0, 'X') == true);
    // Jogador 'O' tenta jogar na mesma posição
    CHECK(jogo.jogar(0, 0, 'O') == false);
}

TEST_CASE("Teste de condição de vitória") {
    JogoDaVelha jogo;
    // Jogador 'X' faz uma sequência vencedora
    jogo.jogar(0, 0, 'X');
    jogo.jogar(0, 1, 'X');
    jogo.jogar(0, 2, 'X');
    // Verifica se o jogo detecta a vitória
    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste de empate") {
    JogoDaVelha jogo;
    // Preenche o tabuleiro sem vencedores
    jogo.jogar(0, 0, 'X');
    jogo.jogar(0, 1, 'O');
    jogo.jogar(0, 2, 'X');
    jogo.jogar(1, 0, 'X');
    jogo.jogar(1, 1, 'O');
    jogo.jogar(1, 2, 'X');
    jogo.jogar(2, 0, 'O');
    jogo.jogar(2, 1, 'X');
    jogo.jogar(2, 2, 'O');
    // Verifica se o jogo não detecta vitória
    CHECK(jogo.verificarVitoria() == false);
}
