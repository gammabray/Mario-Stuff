#include <SFML\Graphics.hpp>
#include "DisplayObject.hpp"

Game::DisplayObject::DisplayObject(const Vector2f& startPosition, const Vector2f& startSize) {
	position = startPosition;
	size = startSize;
	scaleFactor = Vector2f(1, 1);
	texture = std::make_unique<sf::Texture>();
	sprite = std::make_unique <sf::Sprite>();
	sprite->setTexture(*texture);
	sprite->setPosition(position);
	collisionBox;
}

Game::DisplayObject::~DisplayObject()
{
	texture.release();
	sprite.release();
}
