#include "Objeto.h"

Objeto::Objeto(float m, float p, float v) : massa(m), posicao(p), velocidade(v) {}
void Objeto::desenhar(sf::RenderWindow& window) const {
    // Cria um ret�ngulo com largura e altura fixas
    sf::RectangleShape rectangle(sf::Vector2f(20, 20));

    // Define a cor do ret�ngulo
    rectangle.setFillColor(sf::Color::White);

    // Centraliza o ret�ngulo na posi��o definida horizontalmente e verticalmente no meio da janela
    rectangle.setPosition(posicao - rectangle.getSize().x / 2, window.getSize().y / 2 - rectangle.getSize().y / 2);

    // Desenha o ret�ngulo na janela
    window.draw(rectangle);
}


float Objeto::getMassa()  {
    return massa;
}

void Objeto::setMassa(float m) {
    massa = m;
}

float Objeto::getPosicao()  {
    return posicao;
}

void Objeto::setPosicao(float p) {
    posicao = p;
}

float Objeto::getVelocidade() {
    return velocidade;
}

void Objeto::setVelocidade(float v) {

    velocidade = v;
}

float Objeto::getAceleracao() { return getForca()/getMassa(); }

void Objeto::setAceleracao(float a)
{
    aceleracao = a;
}

float Objeto::getForca() { return forca; }

void Objeto::setMolaEsq(Mola* esq) { molaEsq = esq; }

void Objeto::setMolaDir(Mola* dir) { molaDir = dir; }

Mola* Objeto::getMolaEsq() { return molaEsq; }

Mola* Objeto::getMolaDir() { return molaDir; }

void Objeto::setForca(float f) {
    forca = f;
}