#pragma once
#include "../Util/Timer.h"
#include "../SingleTexture/SingleTextureSpriteRenderer.h"
#include <SFML/Graphics.hpp>

class SingleTextureSpritesTest {
private:
	Timer fullTimer;
	Timer updateTimer;
	Timer clearTimer;
	Timer drawTimer;
	Timer displayTimer;

	SingleTextureSpriteRenderer* renderer;
	sf::RenderWindow* window;

public:
	SingleTextureSpritesTest(sf::RenderWindow* window);
	~SingleTextureSpritesTest();

	void tick();
};