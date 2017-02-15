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
	case tileID::METAL:
		filepath = "Images\\metalblock.png";
		break;
	case tileID::CHECKPOLE:
		filepath = "Images\\checkpole.png";
		break;
	case tileID::CHECKFLAG:
		filepath = "Images\\checkflag.png";
		break;
	case tileID::LCORNER:
		filepath = "Images\\leftblock.png";
		break;
	case tileID::RCORNER:
		filepath = "Images\\rightblock.png";
		break;
	case tileID::POWERUP:
		filepath = "Images\\powerblock.png";
	case tileID::FINISHFLAG:
		filepath = "Images\\finishflag.png";


	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load tile texture";
	}
	sprite->setTexture(*texture);
	sprite->setPosition(position);
	sprite->setOrigin(16.f, 16.f);
	boundingBox = sprite->getGlobalBounds();
}




