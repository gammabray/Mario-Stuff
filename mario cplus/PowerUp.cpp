#include "PowerUp.hpp"
#include <iostream>

Game::PowerUp::PowerUp(const sf::Vector2f & startPos, PowerUpType effect)
	: DisplayObject(startPos,sf::Vector2f(20,20)) ,type(effect)
{
	std::string filepath;
	switch (effect)
	{
	case PowerUpType::BETTERJUMP:
		filepath = "Images\\Collectibles\\jump.png";
		break;
	case PowerUpType::FIREBALL:
		filepath = "Images\\Collectibles\\fireball.png";
		break;
	default:
		break;
	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load texture for power-up" << std::endl;
	}
	sprite->setTexture(*texture);
	boundingBox = sprite->getGlobalBounds();
}

void Game::PowerUp::Draw(sf::RenderTarget & target, const sf::RenderStates & states) const
{
	target.draw(*sprite, states);
}
