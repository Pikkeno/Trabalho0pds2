#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "Jogador.hpp"
#include <map>
#include <string>

class Cadastro {
private:
    std::map<std::string, Jogador> jogadores;  // Mapa que mantém os jogadores registrados.

public:
    Cadastro();
    bool adicionarJogador(const std::string& apelido, const std::string& nome);
    bool removerJogador(const std::string& apelido);
    void listarJogadores() const;
    Jogador* obterJogador(const std::string& apelido);  // Retorna ponteiro para Jogador
    std::map<std::string, Jogador>& getJogadores();  // Utilizado pelo Gerente para acessar todos os jogadores
    void exibirJogadores() const;
};

#endif // CADASTRO_HPP
