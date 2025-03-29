#include "SingleTextureSpriteRenderer.h"
#include <stdio.h>
#include <stdlib.h>

SingleTextureSpriteRenderer::SingleTextureSpriteRenderer(int numberOfSprites) {
	if (!texture.loadFromFile("resources/rhino.png")) {
		printf("Failed to load image resources/rhino.png for SingleTextureSpriteRenderer\n");
	}

	for (int i = 0; i < numberOfSprites; i++) {
		sf::Sprite sprite(texture, sf::IntRect({ {i * 100 % 1180, i * 100 % 620}, {100, 100} }));
		sprite.setPosition({ 800, 450 });
		sprites.push_back(sprite);
	}
}

void SingleTextureSpriteRenderer::update() {
	sf::Vector2f offset;
	for (auto& sprite : sprites) {
		offset = {(float)(rand() % 21 - 10), (float)(rand() % 21 - 10)};
		sprite.move(offset);
		const sf::Vector2f& pos = sprite.getPosition();
		if (pos.x < 0 or pos.x > 1400) {
			sprite.move({ -offset.x, 0 });
		}
		if (pos.y < 0 or pos.y > 800) {
			sprite.move({ 0, -offset.y });
		}
	}
}

void SingleTextureSpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (const auto& sprite : sprites) {
		target.draw(sprite, states);
	}
}
