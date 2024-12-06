#ifndef SIMULADOR_H
#define SIMULADOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Objeto.h"
#include "Mola.h"

class Simulador {
private:
    sf::RenderWindow window;
    std::vector<Objeto> objetos;
    std::vector<Mola> molas;

public:
    Simulador();  // Construtor
    void executar();  // M�todo para executar a simula��o
};

#endif // SIMULADOR_H