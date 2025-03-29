#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include "Util/Timer.h"
#include "Util/RateLimiter.h"
#include "Tests/SingleTextureSpritesTest.h"
#include "Tests/SingleTextureVertexArrayTest.h"
#include "Tests/MultiTextureSpritesTest.h"
#include "Tests/MultiTextureVertexArrayTest.h"

void generateSubTextureImages();

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "SFML Draw Call Profiling");

    // generateSubTextureImages();

    SingleTextureSpritesTest singleTextureSpritesTest(&window);
    SingleTextureVertexArrayTest singleTextureVertexArrayTest(&window);
    MultiTextureSpritesTest multiTextureSpritesTest(&window);
    MultiTextureSpritesTest multiTextureSpritesTestRandomTextureOrder(&window, true);
    MultiTextureVertexArrayTest multiTextureVertexArrayTest(&window);

    RateLimiter rateLimiter(1000);

    enum Test {
        READY = 0,
        SINGLE_TEXTURE_SPRITES,
        SINGLE_TEXTURE_VERTEX_ARRAY,
        MULTI_TEXTURE_SPRITES,
        MULTI_TEXTURE_SPRITES_RANDOM_TEXTURE_ORDER,
        MULTI_TEXTURE_VERTEX_ARRAY,
        DONE
    };

    Test currentTest = READY;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Enter) {
                    currentTest = (Test)(currentTest + 1);
                    printf("\n-----\nRunning test #%d\n-----\n", (int)currentTest);
                    srand(0);
                }
            }
        }

        rateLimiter.tick();

        switch (currentTest) {
        case READY: break;
        case SINGLE_TEXTURE_SPRITES: singleTextureSpritesTest.tick(); break;
        case SINGLE_TEXTURE_VERTEX_ARRAY: singleTextureVertexArrayTest.tick(); break;
        case MULTI_TEXTURE_SPRITES: multiTextureSpritesTest.tick(); break;
        case MULTI_TEXTURE_SPRITES_RANDOM_TEXTURE_ORDER: multiTextureSpritesTestRandomTextureOrder.tick(); break;
        case MULTI_TEXTURE_VERTEX_ARRAY: multiTextureVertexArrayTest.tick(); break;
        case DONE:
        default: window.close(); break;
        }
    }

    return 0;
}

void generateSubTextureImages() {
    sf::Image image;
    image.loadFromFile("resources/rhino.png");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            sf::Image subImage(sf::Vector2u{ 128, 72 });
            printf("Image copy  : %d\n", subImage.copy(image, { 0,0 }, { {i * 128, j * 72}, {128, 72} }));
            printf("Save to file: %d\n", subImage.saveToFile("resources/rhino_" + std::to_string(i * 10 + j) + ".png"));
        }
    }
}