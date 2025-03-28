#include <SFML/Graphics.hpp>
#include "SpriteRenderer.h"
#include "DynamicVertexArrayRenderer.h"
#include <SFML/System.hpp>
#include <stdio.h>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "SFML Draw Call Profiling");

    //SpriteRenderer renderer(1000);
    DynamicVertexArrayRenderer renderer(10000);

    sf::Clock drawClock;
    int frameCount = 0;
    int maxFrameCount = 2000;
    int64_t drawTimeSum = 0;


    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        renderer.update();


        //drawClock.restart();

        window.clear();

        ///////////////
        //drawClock.restart();

        //window.clear();
        window.draw(renderer);

        drawClock.restart();
        window.display();

        int64_t drawTime = drawClock.getElapsedTime().asMicroseconds();
        drawTimeSum += drawTime;
        frameCount++;

        if (frameCount >= maxFrameCount) {
            frameCount = 0;
            double avg = (double)drawTimeSum / maxFrameCount;
            double fps = 1000000.0 / avg;
            printf("Average us per frames across %d frames: %.2f = ", maxFrameCount, avg);
            printf("%.2f fps\n", fps);
            drawTimeSum = 0;
        }
        ///////////////

        //window.display();
    }

    return 0;
}