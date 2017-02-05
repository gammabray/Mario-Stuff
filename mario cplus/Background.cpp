#include "Background.hpp"
#include <cmath>
#include <iostream>
#include <SFML\Graphics.hpp>
#include <typeinfo>

const sf::Vector2f Game::BackgroundTile::s_tilesize = sf::Vector2f(1000.f,720.f); // size of each piece of the background to be drawn
std::vector<std::shared_ptr<sf::Texture>> Game::Background::s_blockTextures;

//Functions for nested struct BackgroundTile
Game::BackgroundTile::BackgroundTile(sf::Vector2f pos, sf::Texture& t)	: position(pos)
{
	texture = std::make_unique<sf::Texture>();//create unique pointer
	*texture = t;
	sprite = std::make_unique<sf::Sprite>();

	sprite->setTexture(*texture);
	sprite->setPosition(position);
}

Game::BackgroundTile::BackgroundTile(const BackgroundTile & copy) 
{
	this->texture = copy.texture;
	this->sprite = copy.sprite;
	this->position = copy.position;
	sprite->setTexture(*texture);
	sprite->setPosition(position);



}



void Game::Background::s_addTextures()
{
	s_blockTextures.push_back(std::make_shared<sf::Texture>());
	if (!s_blockTextures[0]->loadFromFile("Images\\tilesample.png")) {						 
		std::cout << "Failed to load first tile image" << std::endl;
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
	
	for (int i = 0; i < NoOfTiles; ++i) {
		backTiles.emplace_back(sf::Vector2f(i * BackgroundTile::s_tilesize.x, 0), *s_blockTextures[0]);
		//backTiles.emplace_back(sf::Vector2f(i * BackgroundTile::s_tilesize.x, BackgroundTile::s_tilesize.y), *s_blockTextures[0]);
	}
	
}
