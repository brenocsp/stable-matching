#include <math.h>
#include "Pessoa.hpp"

Pessoa::Pessoa(int idade, int x, int y) {
    _idade = idade;
    _x = x;
    _y = y;
    _temAlocacao = false;
}

double Pessoa::calcular_distancia(int x, int y) {
    return sqrt(pow(_x-x,2) + pow(_y-y,2));
}