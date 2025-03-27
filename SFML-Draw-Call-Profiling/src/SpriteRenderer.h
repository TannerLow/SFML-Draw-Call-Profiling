#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class SpriteRenderer : public sf::Drawable {
public:
	std::vector<sf::Sprite> sprites;
	sf::Texture texture;
	//std::vector<sf::Texture*> textures;

	SpriteRenderer(int numberOfSprites);
	~SpriteRenderer();

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};