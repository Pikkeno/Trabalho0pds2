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
    std::string apelido;
    std::string nome;
    int vitoriaReversi = 0;    int derrotaReversi = 0;    int vitoriaLiga4 = 0;    
    int derrotaLiga4 = 0;       int vitoriaVelha = 0;      int derrotaVelha = 0;

public:
    jogador();jogador(const std::string& apelido, const std::string& nome);
    std::string getapelido() const;     std::string getNome() const;
    void registrarV(const std::string& jogo);    void registrarD(const std::string& jogo);    void resetE();
    
    std::string serializar() const;
    void desserializar(const std::string& dados);

    // Exibição de estatísticas
    void exibirE() const;
};

class GerenciadorJogadores {
private:
    std::unordered_map<std::string, jogador> jogadores; // Mapeia apelidos para objetos Jogador

    // Métodos auxiliares para persistência
    void salvarDados() const;
    void carregarDados();

public:
    // Construtor
    GerenciadorJogadores();

    // Gerenciamento de jogadores
    bool cadastrarJogador(const std::string& apelido, const std::string& nome);
    bool removerJogador(const std::string& apelido);
    void listarJogadores() const;

    // Gerenciamento de partidas
    void iniciarPartida(const std::string& tipoJogo, const std::string& apelidoJogador1, const std::string& apelidoJogador2);
};

#endif // JOGADOR_HPP
