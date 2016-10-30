#include "Tile.hpp"
#include <SFML\Graphics.hpp>

Game::Tile::Tile(const Vector2f & startPos, const Vector2f & startSize, sf::Texture t)
	: DisplayObject(startPos,startSize)
{

}

Game::Tile::~Tile()
{
}

void Game::Tile::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{
}
