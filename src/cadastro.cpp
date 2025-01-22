#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include <iostream>
#include <string>
#include <map>

// Classe Jogador (certifique-se de que existe no seu código)
class Jogador {
private:
    std::string apelido;
    std::string nome;

public:
    Jogador(const std::string& apelido, const std::string& nome)
        : apelido(apelido), nome(nome) {}

    const std::string& getApelido() const { return apelido; }
    const std::string& getNome() const { return nome; }
};

class Cadastrar {
private:
    std::map<std::string, Jogador> jogadores;

    // Função auxiliar
    void carregarDados();

public:
    Cadastrar(); // Declaração do construtor
    bool cadastrar(const std::string& apelido, const std::string& nome);
    bool remover(const std::string& apelido);
    void listar() const;
    void salvarDados() const;
};

#endif // CADASTRO_HPP
