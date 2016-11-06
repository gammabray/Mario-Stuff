#include "Background.hpp"
#include <cmath>
#include <SFML\Graphics.hpp>

const sf::Vector2f Game::Background::BackgroundTile::s_tilesize = sf::Vector2f(1000.f,720.f); // size of each piece of the background to be drawn
std::vector<sf::Texture*> Game::Background::s_blockTextures;

//Functions for nested struct BackgroundTile
Game::Background::BackgroundTile::BackgroundTile(sf::Vector2f position, sf::Texture t)
{
	texture = new sf::Texture(t);
	sprite = new sf::Sprite(*texture);
	this->position = new sf::Vector2f(position);
}

	Game::Background::BackgroundTile::~BackgroundTile()
{
	delete texture;
	delete sprite;
	delete position;
}

void Game::Background::addTextures()
{


}

Game::Background::Background(sf::Vector2f levelsize)
{
	int noOfTiles = static_cast<int>(ceil(levelsize.x / BackgroundTile::s_tilesize.x));
	this->generateBackgroundTiles(noOfTiles);
}

void Game::Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (BackgroundTile bt : backTiles) {
		target.draw(*bt.sprite);
	}
}

void Game::Background::generateBackgroundTiles(int NoOfTiles)
{
	for (int i = 0; i < NoOfTiles; i++) {
		backTiles.push_back(BackgroundTile{ sf::Vector2f(0,0),sf::Texture(*s_blockTextures[i]) }); 
	}
	
}
