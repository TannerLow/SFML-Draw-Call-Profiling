#include "DynamicVertexArrayRenderer.h"
#include <stdio.h>
#include <stdlib.h>
#include "util/VertexHelper.h"

DynamicVertexArrayRenderer::DynamicVertexArrayRenderer(int numberOfSprites) {
	if (!texture.loadFromFile("resources/o2craftround.png")) {
		printf("Failed to load image resources/o2craftround.png for SpriteRenderer\n");
	}

	vertices.setPrimitiveType(sf::PrimitiveType::Triangles);
	vertices.resize(numberOfSprites * 6);

	for (int i = 0; i < numberOfSprites; i++) {
		sf::IntRect textureRect{ {i * 100 % 1500, i * 100 % 800}, {100, 100} };
		sf::FloatRect quad{ {800, 450}, {100, 100} };
		vh::positionQuad(&(vertices[i * 6]), quad);
		vh::updateQuadTexture(&(vertices[i * 6]), textureRect);
	}

	srand(0);
}

DynamicVertexArrayRenderer::~DynamicVertexArrayRenderer() {

}

void DynamicVertexArrayRenderer::update() {
	sf::Vector2f offset;
	sf::FloatRect quad;
	quad.size = { 100, 100 };
	for (int i = 0; i < vertices.getVertexCount() / 6; i++) {
		sf::Vector2f& pos = vertices[i * 6].position;
		offset = { (float)(rand() % 21 - 10), (float)(rand() % 21 - 10) };
		pos += offset;
		if (pos.x < 0 or pos.x > 1600) {
			pos.x += -offset.x;
		}
		if (pos.y < 0 or pos.y > 900) {
			pos.y += -offset.y;
		}
		quad.position = pos;
		vh::positionQuad(&(vertices[i * 6]), quad);
	}
}

void DynamicVertexArrayRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	states.texture = &texture;

	target.draw(vertices, states);
}
