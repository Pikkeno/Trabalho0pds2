#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "jogador.hpp"
#include <unordered_map>
#include <vector>
#include <iostream>
#include <string>

class Cadastrar {
    private: std::unordered_map<std::string, jogador> jogadores;
    void salvarDados() const;
    void carregarDados();

    public: bool cadastrarJogadores();
    bool cadastrar(const std::string& apelido, const std::string& nome);
    bool remover(const std::string& apelido);
    void listar() const;
};
#endif
