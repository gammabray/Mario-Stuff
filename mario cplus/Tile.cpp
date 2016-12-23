#include "Tile.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

void Game::Tile::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{
	target.draw(*this->sprite);
}

Game::Tile::Tile(const sf::Vector2f & startPos, const sf::Vector2f & startSize,Game::tileID ID, sf::Texture &t) :
	DisplayObject(startPos,startSize)
{


	std::string filepath;
	this->ID = ID;
	switch (this->ID) {
	case tileID::DIRT:
		filepath = "Images\\block.png";
		break;
	case tileID::SNOW:
		
		break;
	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load tile texture";
	}
	sprite->setTexture(*texture);
	sprite->setPosition(position);
	sprite->setOrigin(16.f, 16.f);
}




