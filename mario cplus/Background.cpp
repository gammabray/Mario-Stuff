#include "Background.hpp"
#include <cmath>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <typeinfo>

const sf::Vector2f Game::BackgroundTile::s_tilesize = sf::Vector2f(1000.f,720.f); // size of each piece of the background to be drawn
std::vector<std::unique_ptr<sf::Texture>> Game::Background::s_blockTextures;

//Functions for nested struct BackgroundTile
Game::BackgroundTile::BackgroundTile(sf::Vector2f pos, sf::Texture& t)	: position(pos)
{
	texture = std::make_shared<sf::Texture>();
	*texture = t;
	sprite = std::make_shared<sf::Sprite>();
	sprite->setTexture(*texture);
	
}

Game::BackgroundTile::~BackgroundTile()
{

	texture = nullptr;
	sprite = nullptr;
}

void Game::Background::addTextures()
{
	s_blockTextures.push_back(std::make_unique<sf::Texture>());
	if (!s_blockTextures[0]->loadFromFile("Images\\tilesample.png")) {						 
		std::cout << "Failed to load first tile image" << std::endl;
	}

}

void Game::Background::deleteTextures()
{
	for (auto &blocktexture : s_blockTextures) {
		blocktexture.release();
	}
}

Game::Background::Background(sf::Vector2f levelsize)
{
	int noOfTiles = static_cast<int>(ceil(levelsize.x / BackgroundTile::s_tilesize.x));
	this->generateBackgroundTiles(noOfTiles);
}

void Game::Background::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	for (auto &bt : backTiles) {
		target.draw(*bt.sprite);
	}
}

void Game::Background::generateBackgroundTiles(int NoOfTiles)
{
	BackgroundTile b1(sf::Vector2f(0, 0), *s_blockTextures[0]);
	BackgroundTile b2(sf::Vector2f(0, 0), *s_blockTextures[0]);
	for (int i = 0; i < NoOfTiles; i++) {
		backTiles.push_back(b1);
		backTiles.push_back(b2);
	}
	
}
