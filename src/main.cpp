#include "cadastro.hpp"

int main() {
    CadastroJogadores cadastro;

    cadastro.cadastrarJogador("joao123", "João Silva");
    cadastro.cadastrarJogador("ana456", "Ana Maria");
    cadastro.listarJogadores();

    cadastro.removerJogador("joao123");
    cadastro.listarJogadores();

    return 0;
}
