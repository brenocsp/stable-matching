#include "CasamentoEstavel.hpp"

using namespace std;

int main() {
    
    CasamentoEstavel *casamento = new CasamentoEstavel();
    casamento->lerDadosEntrada();
    casamento->ranquearPreferenciaDasPessoas();
    casamento->ranquearPreferenciaDosPostos();
    casamento->gerarListaAtendimento();
    casamento->imprimirListaAtendimento();

    delete casamento;

    return 0;
}