#ifndef CASAMENTO_ESTAVEL_H
#define CASAMENTO_ESTAVEL_H

#include <algorithm>
#include <iostream>
#include <vector>
#include "Pessoa.hpp"
#include "Posto.hpp"

using namespace std;

class CasamentoEstavel{
    public:
        CasamentoEstavel();
        ~CasamentoEstavel();

        bool operator()(pair<int,int> pessoa1, pair<int,int> pessoa2); //operador para função std::sort em ranquearPreferenciaDosPostos()
        int getNumPessoas() {return _numPessoas;};
        void setNumPessoas(int numPessoas) {_numPessoas = numPessoas;};
        void inserirPessoa(int idade, int x, int y);
        void inserirPosto(int vagas, int x, int y);
        void lerDadosEntrada();
        void ranquearPreferenciaDasPessoas();
        void ranquearPreferenciaDosPostos();
        void gerarListaAtendimento();
        void imprimirListaAtendimento();
    
    private:
        int _numPessoas;
        int _numPostos;
        double **_preferenciaDasPessoas;
        double *_preferenciaDosPostos;
        vector<Pessoa> _pessoas;
        vector<Posto> _postos;
        vector<vector<int>> _listaAtendimento;
};

#endif