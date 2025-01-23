// Jogador.hpp
#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <vector>

class Jogador {
private:
    std::string Apelido;
    std::string Nome;
    int vitoriaReversi = 0;    int derrotaReversi = 0;    int vitoriaLiga4 = 0;    
    int derrotaLiga4 = 0;       int vitoriaVelha = 0;      int derrotaVelha = 0;

public:
    Jogador();Jogador(const std::string& apelido, const std::string& nome);
    std::string getApelido() const;     std::string getNome() const;
    void registrarVitoria(const std::string& jogo);    void registrarDerrota(const std::string& jogo);    void resetE();
    
    std::string serializar() const;
    void desserializar(const std::string& dados);

    void exibirE() const;
};
#endif
