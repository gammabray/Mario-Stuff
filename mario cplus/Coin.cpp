#include "Coin.hpp"
const sf::Vector2f Game::Coin::s_size(16, 16);
Game::Coin::Coin(const sf::Vector2f& startPos) : DisplayObject(startPos,s_size)
{
	if (!texture->loadFromFile("Images\\Coin.png")) {
		std::cout << "Failed to load texture for coin...";
	}
	sprite->setTexture(*texture);
	boundingBox = sprite->getGlobalBounds();

}

void Game::Coin::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{
	target.draw(*sprite);
}

