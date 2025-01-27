#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Liga4.hpp"

TEST_CASE("Teste do construtor padrão") {
    Liga4 jogo;
    CHECK(jogo.getLinhas() == 6);
    CHECK(jogo.getColunas() == 7);
}

TEST_CASE("Teste de jogada válida") {
    Liga4 jogo;
    CHECK(jogo.jogar(0, 3, 'X') == true); // Jogador 'X' joga na coluna 3
    CHECK(jogo.getPosicao(5, 3) == 'X');  // Verifica se a peça caiu na linha inferior
}

TEST_CASE("Teste de jogada inválida") {
    Liga4 jogo;
    for (int i = 0; i < 6; ++i) {
        jogo.jogar(0, 3, 'X'); // Preenche a coluna 3
    }
    CHECK(jogo.jogar(0, 3, 'O') == false); // Tenta jogar na coluna 3 já cheia
}

TEST_CASE("Teste de vitória horizontal") {
    Liga4 jogo;
    for (int i = 0; i < 4; ++i) {
        jogo.jogar(0, i, 'X'); // Jogador 'X' joga nas colunas 0 a 3
    }
    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste de vitória vertical") {
    Liga4 jogo;
    for (int i = 0; i < 4; ++i) {
        jogo.jogar(0, 2, 'O'); // Jogador 'O' joga na coluna 2
    }
    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste de vitória diagonal crescente") {
    Liga4 jogo;
    jogo.jogar(0, 0, 'X'); // Diagonal \
    jogo.jogar(0, 1, 'O');
    jogo.jogar(0, 1, 'X');
    jogo.jogar(0, 2, 'O');
    jogo.jogar(0, 2, 'O');
    jogo.jogar(0, 2, 'X');
    jogo.jogar(0, 3, 'O');
    jogo.jogar(0, 3, 'O');
    jogo.jogar(0, 3, 'O');
    jogo.jogar(0, 3, 'X');
    CHECK(jogo.verificarVitoria() == true);
}

TEST_CASE("Teste de vitória diagonal decrescente") {
    Liga4 jogo;
    jogo.jogar(0, 3, 'X'); // Diagonal /
    jogo.jogar(0, 2, 'O');
    jogo.jogar(0, 2, 'X');
    jogo.jogar(0, 1, 'O');
    jogo.jogar(0, 1, 'O');
    jogo.jogar(0, 1, 'X');
    jogo.jogar(0, 0, 'O');
    jogo.jogar(0, 0, 'O');
    jogo.jogar(0, 0, 'O');
    jogo.jogar(0, 0, 'X');
    CHECK(jogo.verificarVitoria() == true);
}
