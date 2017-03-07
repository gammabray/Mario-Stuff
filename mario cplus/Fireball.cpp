#include "Fireball.hpp"
#include <iostream>

const sf::Vector2f Game::Fireball::s_size(8.f, 8.f);
const sf::Vector2f Game::Fireball::s_speed(0.5f, 0.f);

Game::Fireball::Fireball(const sf::Vector2f & startPos, direction d)
	: Projectile(startPos,s_size,s_speed,d,3)
{
	addSprites();
	currSprite = 0;
	if (!texture->loadFromFile("Images\\Common\\fireball.png")) {
		std::cout << "Unable to load fireball texture.." << std::endl;
	}
	sprite->setTexture(*texture);
	sprite->setTextureRect(SpriteStates[currSprite]);
	travelling = d;
}

void Game::Fireball::addSprites()
{
	SpriteStates.push_back(sf::IntRect(0, 0, 8, 8));//move 1
	SpriteStates.push_back(sf::IntRect(10, 0, 8, 8));//move 2
	SpriteStates.push_back(sf::IntRect(20, 0, 10, 10));//destruction
}

void Game::Fireball::DisplayInfo()
{
	
}

void Game::Fireball::Draw(sf::RenderTarget & target, const sf::RenderStates & states) const
{
	target.draw(*sprite, states.Default);
}

void Game::Fireball::changeSprite(int changeTo = 0)
{
	if (changeTo == 0) {
		if (animationClock.getElapsedTime().asMilliseconds() >= 600) {
			currSprite++;
			if (currSprite > 1) {
				currSprite = 0;
			}
			animationClock.restart();
		}
	}
	else{
		currSprite = 0;
	}
	
}

void Game::Fireball::update()
{
	float delta = static_cast<float>(speedClock.restart().asMilliseconds());
	changeSprite();
	sprite->setTextureRect(SpriteStates[currSprite]);
	if (travelling == direction::RIGHT){
		sprite->move(delta * maxVelocity.x, 0);
	}
	else if (travelling == direction::LEFT) {
		sprite->move(-delta * maxVelocity.x, 0);
	}
	
}

