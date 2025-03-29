#pragma once
#include "../Util/Timer.h"
#include "../MultiTexture/MultiTextureSpriteRenderer.h"
#include <SFML/Graphics.hpp>

class MultiTextureSpritesTest {
private:
	Timer fullTimer;
	Timer updateTimer;
	Timer clearTimer;
	Timer drawTimer;
	Timer displayTimer;

	MultiTextureSpriteRenderer* renderer;
	sf::RenderWindow* window;

public:
	MultiTextureSpritesTest(sf::RenderWindow* window, bool randomizeTextureOrder = false);
	~MultiTextureSpritesTest();

	void tick();
};
