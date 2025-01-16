#include "cadastro.hpp"

int main() {
    Cadastrar cadastro;

    cadastro.cadastrar("joao123", "João Silva");
    cadastro.cadastrar("ana456", "Ana Maria");
    cadastro.listar();

    cadastro.remover("joao123");
    cadastro.listar();

    return 0;
}
