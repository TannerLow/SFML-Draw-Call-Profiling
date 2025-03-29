#include "MultiTextureSpriteRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <random>

MultiTextureSpriteRenderer::MultiTextureSpriteRenderer(int numberOfSprites, int numberOfTextures, bool randomizeTextureOrder) {
	textures.resize(numberOfTextures);

	for (int i = 0; i < numberOfTextures; i++) {
		std::string file = "resources/rhino_" + std::to_string(i) + ".png";
		if (!textures[i].loadFromFile(file)) {
			printf("Failed to load texture %s in MultiTextureSpriteRenderer\n", file.c_str());
		}
	}

	int spritesPerTexture = numberOfSprites / numberOfTextures;

	for (int i = 0; i < numberOfTextures; i++) {
		for (int j = 0; j < spritesPerTexture; j++) {
			sprites.emplace_back(textures[i]);
			sprites.back().setPosition({800, 450});
		}
	}

	while (sprites.size() < numberOfSprites) {
		sprites.emplace_back(textures.back());
		sprites.back().setPosition({ 800, 450 });
	}

	if (randomizeTextureOrder) {
		std::random_device rd;
		std::mt19937 g(rd());
		std::shuffle(sprites.begin(), sprites.end(), g);
	}
}

void MultiTextureSpriteRenderer::update() {
	sf::Vector2f offset;
	for (auto& sprite : sprites) {
		offset = { (float)(rand() % 21 - 10), (float)(rand() % 21 - 10) };
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

void MultiTextureSpriteRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	for (const auto& sprite : sprites) {
		target.draw(sprite, states);
	}
}
