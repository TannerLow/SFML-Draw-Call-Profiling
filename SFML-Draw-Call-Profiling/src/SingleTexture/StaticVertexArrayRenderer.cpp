#include "StaticVertexArrayRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include "../Util/VertexHelper.h"

StaticVertexArrayRenderer::StaticVertexArrayRenderer(int numberOfSprites) {
	if (!texture.loadFromFile("resources/rhino.png")) {
		printf("Failed to load image resources/rhino.png for SpriteRenderer\n");
	}

	vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
	vertices.resize(numberOfSprites * 6);

	for (int i = 0; i < numberOfSprites; i++) {
		sf::IntRect textureRect{ {i * 100 % 1180, i * 100 % 620}, {100, 100} };
		sf::FloatRect quad{ {800, 450}, {100, 100} };
		vh::positionQuad(&(vertices[i * 6]), quad);
		vh::updateQuadTexture(&(vertices[i * 6]), textureRect);
	}
}

void StaticVertexArrayRenderer::update() {
	sf::Vector2f offset;
	sf::FloatRect quad;
	quad.size = { 100, 100 };
	for (int i = 0; i < vertices.getVertexCount() / 6; i++) {
		sf::Vector2f& pos = vertices[i * 6].position;
		offset = { (float)(rand() % 21 - 10), (float)(rand() % 21 - 10) };
		pos += offset;
		if (pos.x < 0 or pos.x > 1400) {
			pos.x += -offset.x;
		}
		if (pos.y < 0 or pos.y > 800) {
			pos.y += -offset.y;
		}

		quad.position = pos;
		vh::positionQuad(&(vertices[i * 6]), quad);
	}
}

void StaticVertexArrayRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.texture = &texture;

	target.draw(vertices, states);
}
