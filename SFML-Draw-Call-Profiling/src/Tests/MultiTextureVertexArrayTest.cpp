#include "MultiTextureVertexArrayTest.h"

MultiTextureVertexArrayTest::MultiTextureVertexArrayTest(sf::RenderWindow* window){ //, bool randomizeTextureOrder) {
    this->window = window;
    renderer = new MultiTextureVertexArrayRenderer(3000, 100); // , randomizeTextureOrder);

    fullTimer.set("full", 2000);
    updateTimer.set("update", 2000);
    clearTimer.set("clear", 2000);
    drawTimer.set("draw", 2000);
    displayTimer.set("display", 2000);
}

MultiTextureVertexArrayTest::~MultiTextureVertexArrayTest() {
    delete renderer;
}

void MultiTextureVertexArrayTest::tick() {
    fullTimer.start();

    updateTimer.start();
    renderer->update();
    updateTimer.stop();

    clearTimer.start();
    window->clear();
    clearTimer.stop();

    drawTimer.start();
    window->draw(*renderer);
    drawTimer.stop();

    displayTimer.start();
    window->display();
    displayTimer.stop();

    fullTimer.stop();
}