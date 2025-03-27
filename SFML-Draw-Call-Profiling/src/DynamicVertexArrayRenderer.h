#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class DynamicVertexArrayRenderer : public sf::Drawable {
public:
	sf::VertexArray vertices;
	sf::Texture texture;
	//std::vector<sf::Texture*> textures;

	DynamicVertexArrayRenderer(int numberOfSprites);
	~DynamicVertexArrayRenderer();

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};