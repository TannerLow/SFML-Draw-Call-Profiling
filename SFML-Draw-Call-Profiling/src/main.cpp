#include <SFML/Graphics.hpp>
#include "SpriteRenderer.h"
#include "DynamicVertexArrayRenderer.h"
#include <SFML/System.hpp>
#include <stdio.h>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "SFML Draw Call Profiling");

    //SpriteRenderer renderer(5000);
    DynamicVertexArrayRenderer renderer(10000);

    sf::Clock drawClock;
    std::vector<int64_t> drawTimes;
    int frameCount = 0;
    int maxFrameCount = 5000;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        renderer.update();


        drawClock.restart();

        window.clear();
        window.draw(renderer);
        window.display();

        int64_t drawTime = drawClock.getElapsedTime().asMicroseconds();
        drawTimes.push_back(drawTime);
        frameCount++;

        if (frameCount == maxFrameCount) {
            frameCount = 0;
            int64_t sum = 0;
            for (auto time : drawTimes) {
                sum += time;
            }
            double avg = (double)sum / maxFrameCount;
            double fps = 1000000.0 / avg;
            printf("Average us per frames across %d frames: %.2f = ", maxFrameCount, avg);
            printf("%.2f fps\n", fps);
            drawTimes.clear();
        }
    }
}