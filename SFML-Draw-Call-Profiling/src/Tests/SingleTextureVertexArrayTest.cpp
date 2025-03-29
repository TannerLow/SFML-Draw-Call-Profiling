#include "SingleTextureVertexArrayTest.h"

SingleTextureVertexArrayTest::SingleTextureVertexArrayTest(sf::RenderWindow* window) {
    this->window = window;
    renderer = new StaticVertexArrayRenderer(3000);

    fullTimer.set("full", 2000);
    updateTimer.set("update", 2000);
    clearTimer.set("clear", 2000);
    drawTimer.set("draw", 2000);
    displayTimer.set("display", 2000);
}

SingleTextureVertexArrayTest::~SingleTextureVertexArrayTest() {
    delete renderer;
}

void SingleTextureVertexArrayTest::tick() {
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