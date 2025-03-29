#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class MultiTextureSpriteRenderer : public sf::Drawable, public sf::Transformable {
private:
	std::vector<sf::Sprite> sprites;
	std::vector<sf::Texture> textures;

public:
	MultiTextureSpriteRenderer(int numberOfSprites, int numberOfTextures, bool randomizeTextureOrder);
	~MultiTextureSpriteRenderer() {}

	void update();

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};