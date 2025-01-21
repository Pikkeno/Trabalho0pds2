#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>



int main() {
    JogoDaVelha jogo;

    std::cout << "Bem-vindo ao Jogo da Velha!\n";
    jogo.exibirTabuleiro();

    char jogadorAtual = 'X';
    for (int turno = 0; turno < 9; ++turno) {
        int linha, coluna;
        std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
        std::cin >> linha >> coluna;

        if (!jogo.jogar(linha - 1, coluna - 1, jogadorAtual)) {
            --turno; // Repetir o turno se a jogada for inválida
            continue;
        }

        jogo.exibirTabuleiro();

        if (jogo.verificarVitoria(jogadorAtual)) {
            std::cout << "Parabéns! Jogador " << jogadorAtual << " venceu!\n";
            return 0;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Alternar jogador
    }

    std::cout << "O jogo terminou empatado!\n";
    return 0;

    Reversi jogo;

    std::cout << "Bem-vindo ao Reversi!\n";
    jogo.exibirTabuleiro();
    
}
