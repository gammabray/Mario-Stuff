#include <SFML\Graphics.hpp>
#include "DisplayObject.hpp"

Game::DisplayObject::DisplayObject(const Vector2f& startPosition, const Vector2f& startSize)
	: collisionBox(startSize,startPosition) {
	position = startPosition;
	size = startSize;
	scaleFactor = Vector2f(1, 1);
	texture = std::make_unique<sf::Texture>();
	sprite = std::make_unique<sf::Sprite>();
	sprite->setPosition(position);
	sprite->setOrigin(size.x / 2, size.y / 2);
	
}




