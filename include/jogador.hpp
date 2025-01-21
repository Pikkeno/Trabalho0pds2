// Jogador.hpp
#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>

class jogador {
private:
    std::string Apelido;
    std::string Nome;
    int vitoriaReversi = 0;    int derrotaReversi = 0;    int vitoriaLiga4 = 0;    
    int derrotaLiga4 = 0;       int vitoriaVelha = 0;      int derrotaVelha = 0;

public:
    jogador();jogador(const std::string& apelido, const std::string& nome);
    std::string getApelido() const;     std::string getNome() const;
    void registrarV(const std::string& jogo);    void registrarD(const std::string& jogo);    void resetE();
    
    std::string serializar() const;
    void desserializar(const std::string& dados);

    void exibirE() const;
};
#endif;
