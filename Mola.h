#ifndef MOLA_H
#define MOLA_H

#include <SFML/Graphics.hpp>
#include "Objeto.h" // Inclua Objeto.h aqui porque Mola usa detalhes de Objeto

class Mola {
public:
    Mola(float k, Objeto* m1, Objeto* m2);
    void desenhar(sf::RenderWindow& window);

    float getPosicaoDir() ;
    void setPosicaoDir(float pd);

    float getPosicaoEsq() ;
    void setPosicaoEsq(float pe);

    float getRep() ;
    void setRep(float r);

    float getK() ;
    void setK(float km);

    Objeto* getObjDir() ;
    void setObjDir(Objeto* dir);

    Objeto* getObjEsq() ;
    void setObjEsq(Objeto* esq);

private:
    float k;
    float posicaoDir;
    float posicaoEsq;
    float rep;
    Objeto* objetoDir;
    Objeto* objetoEsq;
};

#endif // MOLA_H
