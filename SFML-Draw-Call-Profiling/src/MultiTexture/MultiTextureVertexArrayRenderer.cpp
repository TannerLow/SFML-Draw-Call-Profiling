#include "MultiTextureVertexArrayRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Util/VertexHelper.h"

MultiTextureVertexArrayRenderer::MultiTextureVertexArrayRenderer(int numberOfSprites, int numberOfTextures) { //, bool randomizeTextureOrder) {
	textures.resize(numberOfTextures);

	for (int i = 0; i < numberOfTextures; i++) {
		std::string file = "resources/rhino_" + std::to_string(i) + ".png";
		if (!textures[i].loadFromFile(file)) {
			printf("Failed to load texture %s in MultiTextureSpriteRenderer\n", file.c_str());
		}
	}

	int spritesPerTexture = numberOfSprites / numberOfTextures;

	for (int i = 0; i < numberOfTextures; i++) {
		arrays.push_back(sf::VertexArray());
		sf::VertexArray& vertices = arrays.back();
		vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
		vertices.resize(spritesPerTexture * 6);

		for (int j = 0; j < spritesPerTexture; j++) {
			vh::positionQuad(&vertices[j * 6], {{800, 450}, sf::Vector2f(textures[i].getSize())});
			vh::updateQuadTexture(&vertices[j * 6], {{0, 0}, sf::Vector2i(textures[i].getSize())});
		}
	}
}

void MultiTextureVertexArrayRenderer::update() {
	sf::Vector2f offset;
	sf::FloatRect quad;
	quad.size = { 128, 72 };
	for (int i = 0; i < arrays.size(); i++) {
		for (int j = 0; j < arrays[i].getVertexCount() / 6; j++) {
			sf::Vector2f& pos = arrays[i][j * 6].position;
			offset = { (float)(rand() % 21 - 10), (float)(rand() % 21 - 10) };
			pos += offset;
			if (pos.x < 0 or pos.x > 1400) {
				pos.x += -offset.x;
			}
			if (pos.y < 0 or pos.y > 800) {
				pos.y += -offset.y;
			}

			quad.position = pos;
			vh::positionQuad(&(arrays[i][j * 6]), quad);
		}
	}
}

void MultiTextureVertexArrayRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.transform *= getTransform();

	for (int i = 0; i < textures.size(); i++) {
		states.texture = &textures[i];
		target.draw(arrays[i], states);
	}
}
