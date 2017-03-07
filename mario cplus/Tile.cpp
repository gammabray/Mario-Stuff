#include "Tile.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

void Game::Tile::Draw(sf::RenderTarget & target, const sf::RenderStates & states) const
{
	target.draw(*this->sprite,states);
}


Game::Tile::Tile(const sf::Vector2f & startPos, const sf::Vector2f & startSize,Game::tileID ID, sf::Texture &t) :
	DisplayObject(startPos,startSize)
{


	std::string filepath;
	this->ID = ID;
	switch (this->ID) {
	case tileID::DIRT:
		filepath = "Images\\Levels\\block.png";
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
	case tileID::DLTOP:
		filepath = "Images\\Levels\\lefttopcornerblock.png";
		break;
	case tileID::DRTOP:
		filepath = "Images\\Levels\\righttopcornerblock.png";
		break;
	case tileID::DTEDGE:
		filepath = "Images\\Levels\\topedgeblock.png";
		break;
	case tileID::DBEDGE:
		filepath = "Images\\Levels\\botedgeblock.png";
		break;
	case tileID::DLBOT:
		filepath = "Images\\Levels\\leftbotcornerblock.png";
		break;
	case tileID::DRBOT:
		filepath = "Images\\Levels\\rightbotcornerblock.png";
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




