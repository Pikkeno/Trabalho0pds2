/**
 * @file Gerente.hpp
 * @brief Definição da classe Gerente, responsável pelo manejo de dados dos jogadores.
 */

#ifndef GERENTE_HPP
#define GERENTE_HPP
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN


#include "Cadastro.hpp"
#include <fstream>

/**
 * @class Gerente
 * @brief Classe responsável por salvar e carregar os dados dos jogadores.
 */
class Gerente {
private:
    /**
     * @brief Referência ao objeto Cadastro para manipulação dos jogadores.
     */
    Cadastro& cadastro;

public:
    /**
     * @brief Construtor da classe Gerente.
     * @param cadastro Referência ao objeto Cadastro utilizado para gerenciar os jogadores.
     */
    Gerente(Cadastro& cadastro);

    /**
     * @brief Salva os dados dos jogadores em um arquivo.
     * 
     * Os dados são serializados e escritos em um arquivo para posterior recuperação.
     */
    void salvarDados() const;

    /**
     * @brief Carrega os dados dos jogadores de um arquivo.
     * 
     * Lê os dados do arquivo e atualiza o cadastro com as informações recuperadas.
     */
    void carregarDados();
};

#endif // GERENTE_HPP
