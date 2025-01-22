#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>



int main() {
    JogoDaVelha VelhaJogo;

    std::cout << "Bem-vindo ao Jogo da Velha!\n";
    
    VelhaJogo.exibirTabuleiro();

    char jogadorAtual = 'X';
    for (int turno = 0; turno < 9; ++turno) {
        int linha, coluna;
        std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
        std::cin >> linha >> coluna;

        if (!VelhaJogo.jogar(linha - 1, coluna - 1, jogadorAtual)) {
            --turno; // Repetir o turno se a jogada for inválida
            continue;
        }

        VelhaJogo.exibirTabuleiro();

        if (VelhaJogo.verificarVitoria(jogadorAtual)) {
            std::cout << "Parabéns! Jogador " << jogadorAtual << " venceu!\n";
            return 0;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Alternar jogador
    }

    std::cout << "O jogo terminou empatado!\n";
    return 0;

    Reversi ReversiJogo;

    std::cout << "Bem-vindo ao Reversi!\n";
    ReversiJogo.exibirTabuleiro();

    char jogadorAtualreversi = 'X';
    for (int turno = 0; turno < 64; ++turno) {
        int linha, coluna;
        std::cout << "Jogador " << jogadorAtual << ", insira sua jogada (linha e coluna): ";
        std::cin >> linha >> coluna;

        if (!ReversiJogo.jogar(linha - 1, coluna - 1, jogadorAtual)) {
            --turno; // Repetir o turno se a jogada for inválida
            continue;
        }

        ReversiJogo.exibirTabuleiro();

        if (ReversiJogo.verificarVitoria(jogadorAtual)) {
            std::cout << "Parabéns! Jogador " << jogadorAtual << " venceu!\n";
            return 0;
        }

        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X'; // Alternar jogador
    }
}
