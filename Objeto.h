#ifndef OBJETO_H
#define OBJETO_H

#include <SFML/Graphics.hpp>

class Mola; // Forward declaration para a classe Mola

class Objeto {
public:
    Objeto(float massa, float posicao, float velocidade);
    void desenhar(sf::RenderWindow& window) const;

    float getMassa() ;
    void setMassa(float m);

    float getPosicao() ;
    void setPosicao(float p);

    float getVelocidade() ;
    void setVelocidade(float v);

    float getForca() ;
    void setForca(float f);

    float getAceleracao() ;
    void setAceleracao(float a);

    Mola* getMolaEsq();
    void setMolaEsq(Mola* esq);

    Mola* getMolaDir() ;
    void setMolaDir(Mola* dir);

private:
    float massa;
    float posicao;
    float velocidade;
    float forca;
    float aceleracao;
    Mola* molaEsq;
    Mola* molaDir;
};

#endif // OBJETO_H