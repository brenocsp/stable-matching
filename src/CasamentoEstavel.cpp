#include "CasamentoEstavel.hpp"

CasamentoEstavel::CasamentoEstavel() {
    _numPessoas = 0;
    _numPostos = 0;
    _preferenciaDasPessoas = nullptr;
    _preferenciaDosPostos = nullptr;
}

CasamentoEstavel::~CasamentoEstavel()  {
    for (int i = 0; i < _numPessoas; i++) {
        delete[] _preferenciaDasPessoas[i];
    }
    delete[] _preferenciaDasPessoas;
    delete[] _preferenciaDosPostos;
}

bool CasamentoEstavel::operator()(pair<int,int> pessoa1, pair<int,int> pessoa2) {
    if(pessoa1.first == pessoa2.first) return pessoa1.second < pessoa2.second;
    else return pessoa1.first > pessoa2.first;
}

void CasamentoEstavel::inserirPessoa(int idade, int x, int y) {
    _pessoas.push_back(Pessoa(idade, x, y));
}

void CasamentoEstavel::inserirPosto(int vagas, int x, int y) {
    _postos.push_back(Posto(vagas, x, y));
}

void CasamentoEstavel::lerDadosEntrada() {
    int idade, vagas, x, y;

    cin >> _numPostos;
    for (int i = 0; i < _numPostos; i++) {
        cin >> vagas >> x >> y;
        inserirPosto(vagas, x, y);
    }

    cin >> _numPessoas;
    for (int i = 0; i < _numPessoas; i++) {
        cin >> idade >> x >> y;
        inserirPessoa(idade, x, y);
    }
}

void CasamentoEstavel::ranquearPreferenciaDasPessoas() {
    vector<pair<double,int>> distancias;
    _preferenciaDasPessoas = new double*[_numPessoas];

    for(unsigned i = 0; (int)i < _numPessoas; i++) {
        _preferenciaDasPessoas[i] = new double[_numPostos];
        distancias.clear();
        for(unsigned j = 0; (int)j < _numPostos; j++) {
            distancias.push_back(make_pair(_pessoas[i].calcular_distancia(_postos[j].getX(), _postos[j].getY()), (int)j));
        }

        sort (distancias.begin(), distancias.end());
        for (unsigned k = 0; (int)k < _numPostos; k++) {
            _preferenciaDasPessoas[i][k] = distancias[k].second;
        }     
    }
}

void CasamentoEstavel::ranquearPreferenciaDosPostos() {
    vector<pair<int,int>> idades;
    _preferenciaDosPostos = new double[_numPessoas];

    for(unsigned i = 0; (int)i < _numPessoas; i++) {
        idades.push_back(make_pair(_pessoas[i].getIdade(), (int)i));
    }
    sort (idades.begin(), idades.end(), CasamentoEstavel());
    
    for (int i = 0; i < _numPessoas; i++) {
        _preferenciaDosPostos[i] = idades[i].second;
    } 
}

void CasamentoEstavel::gerarListaAtendimento() {
    vector<vector<int>> listaAtendimento(_numPostos);

    for(int i = 0; i < _numPessoas; i++) {
        int canditata = _preferenciaDosPostos[i];
        for (int j = 0; j < _numPostos; j++) {
            int postoPreferido = _preferenciaDasPessoas[canditata][j];
            if(!_pessoas[canditata].getTemAlocacao() && (int)listaAtendimento[postoPreferido].size() < _postos[postoPreferido].getVagas()) {
                listaAtendimento[postoPreferido].push_back(canditata);
                _pessoas[canditata].setTemAlocacao(true);
            }
        }
    }
    _listaAtendimento = listaAtendimento;
}

void CasamentoEstavel::imprimirListaAtendimento() {
    for(int i = 0; i < _numPostos; i++) {
        if(!_listaAtendimento[i].empty()) {
            cout << i << endl;
            for (int j = 0; j < (int)_listaAtendimento[i].size(); j++) {
                cout << _listaAtendimento[i][j];
                if (j != (int)_listaAtendimento[i].size()-1) cout << " ";
            }
            if (i != _numPostos-1) cout << endl;
        }
    }
}