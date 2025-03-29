#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MultiTextureVertexArrayRenderer : public sf::Drawable, public sf::Transformable {
private:
	std::vector<sf::VertexArray> arrays;
	std::vector<sf::Texture> textures;

public:
	MultiTextureVertexArrayRenderer(int numberOfSprites, int numberOfTextures); //, bool randomizeTextureOrder);
	~MultiTextureVertexArrayRenderer() {}

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};