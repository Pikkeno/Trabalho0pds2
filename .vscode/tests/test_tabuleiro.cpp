#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Liga4.hpp"
/**
 * @brief Teste do construtor de JogoDeTabuleiro via Liga4
 */
TEST_CASE("Teste do construtor de JogoDeTabuleiro via Liga4") {
    Liga4 jogo;  // Instancia a classe derivada
    CHECK(jogo.getLinhas() == 6);   // Verifica o número de linhas padrão
    CHECK(jogo.getColunas() == 7);  // Verifica o número de colunas padrão
}

TEST_CASE("Teste de exibição do tabuleiro via Liga4") {
    Liga4 jogo;  // Instancia a classe derivada com dimensões padrão
    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    jogo.exibirTabuleiro();

    std::cout.rdbuf(p_cout_streambuf);
    // Verifica se a saída corresponde ao tabuleiro inicial esperado
    CHECK(oss.str() == ". . . . . . . \n. . . . . . . \n. . . . . . . \n. . . . . . . \n. . . . . . . \n. . . . . . . \n");
}
