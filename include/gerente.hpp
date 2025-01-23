#ifndef GERENTE_HPP
#define GERENTE_HPP

#include "Cadastro.hpp"
#include <fstream>

class Gerente {
private:
    Cadastro& cadastro;

public:
    Gerente(Cadastro& cadastro);
    void salvarDados() const;
};

#endif // GERENTE_HPP
