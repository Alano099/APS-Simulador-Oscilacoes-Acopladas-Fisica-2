#include "Simulador.h"
#include <iostream>

Simulador::Simulador() : window(sf::VideoMode(800, 600), "Simulador de Massas e Molas") {
    window.setFramerateLimit(60);

    int numObjetos;
    std::cout << "Entre com o número de massas: ";
    std::cin >> numObjetos;

    // Adiciona objeto fixo no início (parede esquerda)
    objetos.emplace_back(INFINITY, 10, 0); // massa infinita, posição x = 10, velocidade = 0

    for (int i = 0; i < numObjetos; ++i) {
        float massa, posicaoInicial, velocidadeInicial;
        std::cout << "Entre com a massa, posição inicial e velocidade inicial para a massa " << i + 1 << ": ";
        std::cin >> massa >> posicaoInicial >> velocidadeInicial;
        objetos.emplace_back(massa, posicaoInicial, velocidadeInicial);
    }

    // Adiciona objeto fixo no final (parede direita)
    objetos.emplace_back(INFINITY, 790, 0); // posição x = 790

    // Conectar molas incluindo as extremidades
    for (int i = 0; i <= numObjetos; ++i) {
        float constanteMola;
        std::cout << "Entre com a constante da mola para conectar as massas " << i << " e " << i + 1 << ": ";
        std::cin >> constanteMola;
        molas.emplace_back(constanteMola, &objetos[i], &objetos[i + 1]);
    }

    executar();
}


float calcForca(float kD, float kE, float dXE, float dXD) {
    return -kE * dXE + kD * dXD;
}

float calcAceleracao(float f, float m) {
    return f / m;
}

void atualizarVel(Objeto* obj, float a, float t) {
    float vel = obj->getVelocidade() + a * t;  // Correção: multiplicação por t em vez de divisão
    obj->setVelocidade(vel);
}

void atualizarPos(Objeto* obj, float dt) {
    float pos = obj->getPosicao() + obj->getVelocidade() * dt;
    obj->setPosicao(pos);
}

void Simulador::executar() {
    float dt = 0.01;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black); // Limpa a janela

        // Calcular a força para cada objeto móvel
        for (size_t i = 1; i < objetos.size() - 1; ++i) { // Não atualiza os objetos fixos
            float kEsq = molas[i - 1].getK();
            float kDir = molas[i].getK();
            float dxEsq = objetos[i - 1].getPosicao() - objetos[i].getPosicao();
            float dxDir = objetos[i].getPosicao() - objetos[i + 1].getPosicao();

            float forca = calcForca(kDir, kEsq, dxDir, dxEsq);
            float acel = calcAceleracao(forca, objetos[i].getMassa());
            atualizarVel(&objetos[i], acel, dt);
            atualizarPos(&objetos[i], dt);
            objetos[i].desenhar(window);
        }

        // Desenhar molas
        for (size_t i = 0; i < molas.size(); ++i) {
            molas[i].desenhar(window);
        }

        window.display(); // Exibe o conteúdo renderizado
    }
}