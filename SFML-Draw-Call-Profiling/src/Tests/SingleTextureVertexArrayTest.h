#pragma once
#include "../Util/Timer.h"
#include "../SingleTexture/StaticVertexArrayRenderer.h"
#include <SFML/Graphics.hpp>

class SingleTextureVertexArrayTest {
private:
	Timer fullTimer;
	Timer updateTimer;
	Timer clearTimer;
	Timer drawTimer;
	Timer displayTimer;

	StaticVertexArrayRenderer* renderer;
	sf::RenderWindow* window;

public:
	SingleTextureVertexArrayTest(sf::RenderWindow* window);
	~SingleTextureVertexArrayTest();

	void tick();
};