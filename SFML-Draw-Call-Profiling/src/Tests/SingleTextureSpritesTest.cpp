#include "SingleTextureSpritesTest.h"

SingleTextureSpritesTest::SingleTextureSpritesTest(sf::RenderWindow* window) {
    this->window = window;
    renderer = new SingleTextureSpriteRenderer(3000);

    fullTimer.set("full", 2000);
    updateTimer.set("update", 2000);
    clearTimer.set("clear", 2000);
    drawTimer.set("draw", 2000);
    displayTimer.set("display", 2000);
}

SingleTextureSpritesTest::~SingleTextureSpritesTest() {
    delete renderer;
}

void SingleTextureSpritesTest::tick() {
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
