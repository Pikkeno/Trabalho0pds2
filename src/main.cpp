
/**
 * @file main.cpp
 * @brief Arquivo principal do programa, gerencia o fluxo de execução.
 */

#include "Cadastro.hpp"
#include "Gerente.hpp"
#include "JogoDaVelha.hpp"
#include "Reversi.hpp"
#include "Liga4.hpp"
#include <iostream>
#include <memory>
#include <locale.h>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN 

/**
 * @brief Permite ao usuário selecionar um jogo.
 * @return Um ponteiro exclusivo para o jogo selecionado.
 */

std::unique_ptr<JogoDeTabuleiro> selecionarJogo() {
    int escolha;
    std::cout << "\nSelecione um jogo:\n";
    std::cout << "1. Jogo da Velha\n";
    std::cout << "2. Reversi\n";
    std::cout << "3. Liga4\n";
    std::cout << "Escolha: ";
    std::cin >> escolha;

    switch (escolha) {
        case 1:
            return std::unique_ptr<JogoDaVelha>(new JogoDaVelha());
        case 2:
            return std::unique_ptr<Reversi>(new Reversi());
        case 3:
            return std::unique_ptr<Liga4>(new Liga4(6, 7)); // Ajustar conforme necessário
        default:
            std::cout << "Seleçao invalida. Escolhendo Jogo da Velha por padrao.\n";
            return std::unique_ptr<JogoDaVelha>(new JogoDaVelha());
    }
}

/**
 * @brief Gerencia a execução de uma partida do jogo.
 * @param jogo Ponteiro para o jogo que será jogado.
 * @param cadastro Referência ao objeto Cadastro para manipular jogadores.
 * @param gerente Referência ao objeto Gerente para salvar e carregar dados.
 */

void jogarJogo(JogoDeTabuleiro* jogo, Cadastro& cadastro, Gerente& gerente) {
    std::string apelido1, apelido2;
    std::cout << "Digite o apelido do jogador 1: ";
    std::cin >> apelido1;
    std::cout << "Digite o apelido do jogador 2: ";
    std::cin >> apelido2;

    Jogador* jogador1 = cadastro.obterJogador(apelido1);
    Jogador* jogador2 = cadastro.obterJogador(apelido2);

    if (!jogador1 || !jogador2) {
        std::cerr << "Erro: Ambos os jogadores devem estar cadastrados para iniciar o jogo.\n";
        return;
    }

    char jogadorAtual = 'X'; // Alternar entre 'X' e 'O'
    bool jogoAtivo = true;

    while (jogoAtivo) {
        jogo->exibirTabuleiro();
        int linha, coluna;
        if (dynamic_cast<Liga4*>(jogo) != nullptr) {
            std::cout << "Digite a coluna para jogar: ";
            std::cin >> coluna;
            if (jogo->jogar(coluna, jogadorAtual)) {
                if (jogo->verificarVitoria()) {
                    std::cout << "Parabens, " << (jogadorAtual == 'X' ? apelido1 : apelido2) << "Voce venceu!\n";
                    (jogadorAtual == 'X' ? jogador1 : jogador2)->registrarVitoria(jogo->getNome());
                    (jogadorAtual == 'X' ? jogador2 : jogador1)->registrarDerrota(jogo->getNome());
                    gerente.salvarDados();
                    jogoAtivo = false;
                }
            } else {
                std::cout << "Jogada invalida. Tente novamente.\n";
            }
        } else {
            std::cout << "Digite a linha e a coluna para jogar (separados por espaço): ";
            std::cin >> linha >> coluna;
            if (jogo->jogar(linha, coluna, jogadorAtual)) {
                if (jogo->verificarVitoria()) {
                    std::cout << "Parabens, " << (jogadorAtual == 'X' ? apelido1 : apelido2) << "Voce venceu!\n";
                    (jogadorAtual == 'X' ? jogador1 : jogador2)->registrarVitoria(jogo->getNome());
                    (jogadorAtual == 'X' ? jogador2 : jogador1)->registrarDerrota(jogo->getNome());
                    gerente.salvarDados();
                    jogoAtivo = false;
                }
            } else {
                std::cout << "Jogada invalida. Tente novamente.\n";
            }
        }

        if (jogoAtivo) {
            jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
        }
    }
}

/**
 * @brief Função principal do programa.
 * 
 * Gerencia o cadastro de jogadores, escolha de jogos e execução das partidas.
 * @return int Status de saída do programa.
 */

int main() {
    setlocale(LC_ALL, "Portuguese");

    Cadastro cadastro;
    Gerente gerente(cadastro);

    gerente.carregarDados(); // Carregar dados no início

    char opcao;

    do {
        std::cout << "\nMenu Principal:\n";
        std::cout << "1. Adicionar Jogador\n";
        std::cout << "2. Remover Jogador\n";
        std::cout << "3. Listar Jogadores\n";
        std::cout << "4. Jogar\n";
        std::cout << "5. Sair\n";
        std::cout << "Escolha uma opçao: ";
        std::cin >> opcao;

        switch (opcao) {
            case '1': {
                std::string apelido, nome;
                std::cout << "Digite o apelido do jogador: ";
                std::cin >> apelido;
                std::cout << "Digite o nome completo do jogador: ";
                std::cin.ignore();
                std::getline(std::cin, nome);
                cadastro.adicionarJogador(apelido, nome);
                gerente.salvarDados();
                break;
            }
            case '2': {
                std::string apelido;
                std::cout << "Digite o apelido do jogador a remover: ";
                std::cin >> apelido;
                cadastro.removerJogador(apelido);
                gerente.salvarDados();
                break;
            }
            case '3':
                cadastro.exibirJogadores();
                break;
            case '4': {
                std::unique_ptr<JogoDeTabuleiro> jogo = selecionarJogo();
                jogarJogo(jogo.get(), cadastro, gerente);
                break;
            }
            case '5':
                gerente.salvarDados(); // Salvar dados ao sair
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opçao invalida!\n";
        }
    } while (opcao != '5');

    return 0;
}