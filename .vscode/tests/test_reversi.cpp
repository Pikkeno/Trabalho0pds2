#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Reversi.hpp"

TEST_CASE("Teste do construtor padrão") {
    Reversi jogo;
    // Verifica a configuração inicial do tabuleiro
    CHECK(jogo.getPosicao(3, 3) == 'O');
    CHECK(jogo.getPosicao(3, 4) == 'X');
    CHECK(jogo.getPosicao(4, 3) == 'X');
    CHECK(jogo.getPosicao(4, 4) == 'O');
}

TEST_CASE("Teste de jogada válida") {
    Reversi jogo;
    // Jogador 'X' faz uma jogada válida
    CHECK(jogo.jogar(2, 3, 'X') == true);
    // Verifica se a peça foi colocada corretamente
    CHECK(jogo.getPosicao(2, 3) == 'X');
    // Verifica se a peça do oponente foi virada
    CHECK(jogo.getPosicao(3, 3) == 'X');
}

TEST_CASE("Teste de jogada inválida") {
    Reversi jogo;
    // Tentativa de jogada em uma posição já ocupada
    CHECK(jogo.jogar(3, 3, 'X') == false);
    // Tentativa de jogada fora do tabuleiro
    CHECK(jogo.jogar(8, 8, 'O') == false);
}

TEST_CASE("Teste de verificação de vitória") {
    Reversi jogo;
    // Configura o tabuleiro para um estado de fim de jogo
    // (Este é apenas um exemplo; ajuste conforme necessário)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            jogo.setPosicao(i, j, 'X');
        }
    }
    // Verifica se o jogo detecta o fim corretamente
    CHECK(jogo.verificarVitoria() == true);
}
