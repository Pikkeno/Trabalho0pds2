#ifndef GERENTE_HPP
#define GERENTE_HPP

#include <unordered_map>
#include <string>
#include "jogador.hpp"

class Gerente {
private:
    std::unordered_map<std::string, jogador> jogadores; 

    void salvarDados() const;
    void carregarDados();

public:
    Gerente();
    void iniciarPartida(const std::string& tipoJogo, const std::string& apelidoJogador1, const std::string& apelidoJogador2);
};

#endif