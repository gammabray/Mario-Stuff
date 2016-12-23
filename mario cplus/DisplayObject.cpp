#include <SFML\Graphics.hpp>
#include "DisplayObject.hpp"

Game::DisplayObject::DisplayObject(const Vector2f& startPosition, const Vector2f& startSize): collisionBox(startSize,startPosition) {
	position = startPosition;
	size = startSize;
	scaleFactor = Vector2f(1, 1);
	texture = std::make_unique<sf::Texture>();
	sprite = std::make_unique<sf::Sprite>();
	sprite->setPosition(position);
	
}

Game::DisplayObject::DisplayObject(const DisplayObject & copy) :collisionBox(copy.size,copy.position)
{
	this->position = copy.position;
	this->size = copy.size;
	this->scaleFactor = copy.scaleFactor;
	this->texture = std::make_unique<sf::Texture>(*copy.texture);
	this->sprite = std::make_unique<sf::Sprite>(*copy.sprite);
	this->collisionBox = copy.collisionBox;
}


