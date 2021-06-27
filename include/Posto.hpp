#ifndef POSTO_H
#define POSTO_H

class Posto{
    public:
        Posto(int vagas, int x, int y);

        int getVagas() {return _vagas;};
        int getX() {return _x;};
        int getY() {return _y;};
    
    private:
        int _vagas;
        int _x;
        int _y;
};

#endif