#pragma once
#include "../Util/Timer.h"
#include "../MultiTexture/MultiTextureVertexArrayRenderer.h"
#include <SFML/Graphics.hpp>

class MultiTextureVertexArrayTest {
private:
	Timer fullTimer;
	Timer updateTimer;
	Timer clearTimer;
	Timer drawTimer;
	Timer displayTimer;

	MultiTextureVertexArrayRenderer* renderer;
	sf::RenderWindow* window;

public:
	MultiTextureVertexArrayTest(sf::RenderWindow* window); //, bool randomizeTextureOrder = false);
	~MultiTextureVertexArrayTest();

	void tick();
};
