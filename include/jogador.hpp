#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>
#include <sstream>

class jogador {
    private:
            std::string apelido;
            std::string nome;
            int vitoriasReversi = 0; int vitoriasLiga4 = 0; int vitoriasVelha = 0;
            int derrotaReversi = 0; int derrotaLiga4 = 0; int derrotaVelha = 0;
    public:
            jogador();
            jogador(const std::string& apelido, const std::string& nome);

            std::string getapelido() const;
            std::string getNome() const;

            void registrarV(const std::string& jogo); void registrarD(const std::string& jogo); void reset();
            
            std::string serie() const; void deserie(const std::string& dados);
            
            void exibirE() const;

};
#endif