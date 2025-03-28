#include <SFML/Graphics.hpp>
#include "SpriteRenderer.h"
#include "DynamicVertexArrayRenderer.h"
#include <SFML/System.hpp>
#include <stdio.h>
#include <vector>
#include "Timer.h"
#include "util/RateLimiter.h"

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "SFML Draw Call Profiling");

    //SpriteRenderer renderer(1000);
    DynamicVertexArrayRenderer renderer(5000);

    Timer updateTimer("update", 2000);
    Timer clearTimer("clear", 2000);
    Timer drawTimer("draw", 2000);
    Timer displayTimer("display", 2000);

    RateLimiter rateLimiter(1000);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        rateLimiter.tick();

        updateTimer.start();
        renderer.update();
        updateTimer.stop();

        clearTimer.start();
        window.clear();
        clearTimer.stop();

        drawTimer.start();
        window.draw(renderer);
        drawTimer.stop();

        displayTimer.start();
        window.display();
        displayTimer.stop();
    }

    return 0;
}