#include "Mola.h"
#include <cmath> // Para funções matemáticas, caso necessário

// Implementação do construtor
Mola::Mola(float k, Objeto* m1, Objeto* m2) : k(k), objetoDir(m1), objetoEsq(m2) {}

// Implementação do método desenhar
void Mola::desenhar(sf::RenderWindow& window) {
    float posicaoEsq = objetoEsq->getPosicao();
    float posicaoDir = objetoDir->getPosicao();

    sf::RectangleShape linha(sf::Vector2f(std::fabs(posicaoEsq - posicaoDir), 2));
    linha.setPosition(posicaoEsq, window.getSize().y / 2);
    linha.setFillColor(sf::Color::Red); // Definir cor da linha
    window.draw(linha);
}

float Mola::getPosicaoDir() { return posicaoDir; }

void Mola::setPosicaoDir(float pd) { posicaoDir = pd;}

float Mola::getPosicaoEsq() { return posicaoEsq; }

void Mola::setPosicaoEsq(float pe) { posicaoEsq = pe; }

float Mola::getK() { return k; }

void Mola::setK(float km) { k = km; }

float Mola::getRep() { return rep; }

void Mola::setRep(float r) { rep = r;}

Objeto* Mola::getObjEsq() {
    return objetoEsq;
}

Objeto* Mola::getObjDir() {
    return objetoDir;
}

void Mola::setObjEsq(Objeto* dir) { objetoDir = dir; }

void Mola::setObjDir(Objeto* esq) { objetoEsq = esq; }