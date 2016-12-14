#include "Tile.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

Game::Tile::Tile(const sf::Vector2f & startPos, const sf::Vector2f & startSize,Game::TileID ID, sf::Texture &t) : 
	position(startPos),size(startSize)
{
	this->texture = std::make_shared<sf::Texture>();
	this->sprite = std::make_shared<sf::Sprite>();

	std::string filepath;
	this->ID = ID;
	switch (this->ID) {
	case 0:
		break;
	case 1:
		filepath = "Images\\block.png";
		break;
	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load tile texture";
	}
	sprite->setTexture(*texture);
	sprite->setPosition(position);
	sprite->setOrigin(16.f, 16.f);
}

Game::Tile::Tile(const Tile & copy){
	this->ID = copy.ID;
	this->position = copy.position;
	this->size = copy.size;
	this->texture = copy.texture;
	this->sprite = copy.sprite;
}



