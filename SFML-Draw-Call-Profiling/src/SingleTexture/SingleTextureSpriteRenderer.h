#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SingleTextureSpriteRenderer : public sf::Drawable {
public:
	std::vector<sf::Sprite> sprites;
	sf::Texture texture;

	SingleTextureSpriteRenderer(int numberOfSprites);
	~SingleTextureSpriteRenderer() {}

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};