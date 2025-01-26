#ifndef JOGADOR_HPP
#define JOGADOR_HPP
#include <locale.h>
#include <string>

class Jogador {
private:
    std::string Apelido;
    std::string Nome;
    int vitoriaReversi, derrotaReversi;
    int vitoriaLiga4, derrotaLiga4;
    int vitoriaVelha, derrotaVelha;
    int totalVitorias;  // Total de vitórias em todos os jogos
    int totalDerrotas;  // Total de derrotas em todos os jogos

public:
    Jogador();
    Jogador(const std::string& apelido, const std::string& nome);

    std::string getApelido() const;
    std::string getNome() const;

    int getVitorias() const;
    void setVitorias(int vitorias);

    int getDerrotas() const;
    void setDerrotas(int derrotas);

    void registrarVitoria(const std::string& jogo);
    void registrarDerrota(const std::string& jogo);

    void resetJogador();
    void exibirJogador() const;

    std::string serializar() const;
    void desserializar(const std::string& dados);
};

#endif // JOGADOR_HPP
