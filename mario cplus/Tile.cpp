#include "Tile.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

Game::Tile::Tile(const sf::Vector2f & startPos, const sf::Vector2f & startSize,Game::TileID ID, sf::Texture &t) : 
	position(startPos),size(startSize)
{
	this->texture = std::make_unique<sf::Texture>();
	this->sprite = std::make_unique<sf::Sprite>();

	std::string filepath;
	this->ID = ID;
	switch (this->ID) {
	case 0:
		break;
	case 1:
		filepath = "Images\\tile1.gif";
		break;
	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load tile texture";
	}
	sprite->setTexture(*texture);
	sprite->setPosition(position);
}

Game::Tile::Tile(const Tile & copy){
	this->ID = copy.ID;
	this->position = copy.position;
	this->size = copy.size;
	this->texture = std::make_unique<sf::Texture>(*copy.texture);
	this->sprite = std::make_unique<sf::Sprite>(*copy.sprite);
}

Game::Tile::~Tile()
{
	texture.release();
	sprite.release();
}
