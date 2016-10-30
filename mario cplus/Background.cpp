#include "Background.hpp"
#include <SFML\Graphics.hpp>

const sf::Vector2f Game::Background::BackgroundTile::size = sf::Vector2f(1000.f,720.f);
Game::Background::BackgroundTile::BackgroundTile(sf::Vector2f position, sf::Texture t)
{
	texture = new sf::Texture(t);
	sprite = new sf::Sprite(t);
}

Game::Background::BackgroundTile::~BackgroundTile()
{
}
