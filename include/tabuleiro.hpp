#ifndef JOGODETABULEIRO_HPP
#define JOGODETABULEIRO_HPP

#include <vector>
#include <string>
#include <iostream>

class JogoDeTabuleiro {
protected:
    std::vector<std::vector<char>> tabuleiro; // Matriz que representa o tabuleiro
    int linhas;
    int colunas;

public:
    // Construtor
    JogoDeTabuleiro(int linhas, int colunas);

    // Destrutor virtual
    virtual ~JogoDeTabuleiro() = default;

    // Métodos básicos
    virtual void exibirTabuleiro() const;
    virtual bool jogar(int linha, int coluna, char jogador) = 0; // Jogada abstrata
    virtual bool verificarVitoria(char jogador) const = 0;      // Verificação de vitória abstrata

    // Limpa o tabuleiro
    void resetTabuleiro();
};

#endif // JOGODETABULEIRO_HPP
