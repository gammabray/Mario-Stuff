#include <SFML\Graphics.hpp>
#include "DisplayObject.hpp"
Game::DisplayObject::DisplayObject(const Vector2f& startPosition, const Vector2f& startSize) {
	position = new Vector2f(startPosition);
	size = new Vector2f(startSize);
	scaleFactor = new Vector2f(1, 1);
	texture = new sf::Texture();
	sprite = new sf::Sprite();
	sprite->setPosition(*position);
	collisionBox = new sf::FloatRect();
}

Game::DisplayObject::~DisplayObject()
{
	delete position;
	delete size;
	delete scaleFactor;
	texture = nullptr;
	delete texture;
	delete sprite;	
	delete collisionBox;
}
