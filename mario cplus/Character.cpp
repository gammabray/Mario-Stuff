#include "Character.hpp"
#include <iostream>


Game::Character::Character(const Vector2f& startPos, const Vector2f& startSize) 
	: AnimatedObject(startPos,startSize,6)
	,IsJumping(false), IsWalking(false)
//remember to add no of sprites later
{
	
	if (!_texture->loadFromFile("Images\\marioSpriteSheet.gif")) {
		delete _texture;
		std::cout << "Failed to load Texture for Character..." << std::endl;
	}
	_sprite->setTexture(*_texture);
	addSprites();
	_sprite->setTextureRect(SpriteStates[0]);
	_sprite->setPosition(*_position);
	_sprite->setScale(*_scaleFactor);
	IsVisible = true;

}


void Game::Character::addSprites()
{
	
	SpriteStates.push_back(sf::IntRect(3,0,13,17));
	SpriteStates.push_back(sf::IntRect(34,0,14,16));
	SpriteStates.push_back(sf::IntRect(66,0,12,17));
	SpriteStates.push_back(sf::IntRect(94,0,17,17));
	SpriteStates.push_back(sf::IntRect(SpriteStates[2]));
	SpriteStates.push_back(sf::IntRect(155,0,17,17));
}
void Game::Character::update(const sf::View& v, sf::Keyboard::Key k)
{
	float delta = static_cast<float>( _speedClock.restart().asMilliseconds());
	switch (k) {
	case sf::Keyboard::Unknown:
		break;
	case sf::Keyboard::Up:
		travelling = direction::UP;
		break;
	case sf::Keyboard::Down:
		travelling = direction::DOWN;
		break;
	case sf::Keyboard::Left:
		travelling = direction::LEFT;
		break;
	case sf::Keyboard::Right:
		travelling = direction::DOWN;
		break;


	}


}
void Game::Character::move(float delta, const sf::View& v)
{
}



void Game::Character::DisplayInfo()
{
}

void Game::Character::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{
	
	if(IsVisible)
		target.draw(*_sprite,states.Default);
}
