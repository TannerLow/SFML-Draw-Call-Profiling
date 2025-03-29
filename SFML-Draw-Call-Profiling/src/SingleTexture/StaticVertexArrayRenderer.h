#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class StaticVertexArrayRenderer : public sf::Drawable {
public:
	sf::VertexArray vertices;
	sf::Texture texture;
	//std::vector<sf::Texture*> textures;

	StaticVertexArrayRenderer(int numberOfSprites);
	~StaticVertexArrayRenderer() {}

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};