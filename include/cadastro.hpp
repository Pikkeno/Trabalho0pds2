#ifndef CADASTRO_HPP
#define CADASTRO_HPP

#include "Jogador.hpp"
#include <map>
#include <string>

class Cadastro {
private:
    std::map<std::string, Jogador> jogadores;  // Mapa de jogadores com chave sendo o apelido.

public:
    Cadastro();
    bool adicionarJogador(const std::string& apelido, const std::string& nome);
    bool removerJogador(const std::string& apelido);
    void listarJogadores() const;
    std::map<std::string, Jogador>& getJogadores();  // Método para retornar todos os jogadores.
};

#endif // CADASTRO_HPP
