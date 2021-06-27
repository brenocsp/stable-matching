#ifndef PESSOA_H
#define PESSOA_H

class Pessoa{
    public:
        Pessoa(int idade, int x, int y);
        double calcular_distancia(int x, int y);

        int getIdade() {return _idade;};
        int getX() {return _x;};
        int getY() {return _y;};
        int getTemAlocacao() {return _temAlocacao;};
        void setTemAlocacao(bool alocacao){_temAlocacao = alocacao;};
    
    private:
        int _idade;
        int _x;
        int _y;
        bool _temAlocacao;
};

#endif