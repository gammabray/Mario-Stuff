#include "Enemy.hpp"
#include "Character.hpp"
#include <iostream>


const sf::Vector2f Game::Enemy::startSpeed(0.15f,0.0f);


Game::Enemy::Enemy(const sf::Vector2f& startPos, const sf::Vector2f& startSize, int NoOfSprites, Game::EnemyType t)
	:AnimatedObject(startPos, startSize, NoOfSprites), type(t), colFlag(false)
{
	collisionBox = sprite->getGlobalBounds();
	switch (t) {
	case EnemyType::TY1:
		if (!texture->loadFromFile("Images\\goomba.png")) {
			std::cout << "Failed to load enemy texture..." << std::endl;
		}
		break;
	case EnemyType::TY2:
		if (!texture->loadFromFile("")) {
			std::cout << "Failed to load enemy texture..." << std::endl;
		}
		break;

	}
	
	sprite->setTexture(*texture);
	sprite->setOrigin(startSize.x / 2, startSize.y / 2 );

}


Game::Enemy::~Enemy()
{
}
void Game::Enemy::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{	
	target.draw(*sprite, states);
}
void Game::Enemy::update(Character& ch)
{
	collisionBox = sprite->getGlobalBounds();
	
	float delta = static_cast<float>(speedClock.restart().asMilliseconds());
	move(delta, ch);
}
void Game::Enemy::move(float delta,Game::Character &ch) {
	switch (type) {
	default://temporary
		if (this->position.x == ch.getPosition().x) {
			colFlag = true;
			return;
		}
		if (this->position.x > ch.getPosition().x && !colFlag) {
			sprite->move(-startSpeed.x * delta,0);
			position += sf::Vector2f(-startSpeed.x * delta, 0);
			

		}
		else if (this->position.x < ch.getPosition().x && !colFlag) {
			sprite->move(startSpeed.x * delta, 0);
			position += sf::Vector2f(startSpeed.x * delta, 0);
			
		}
		colFlag = false;
		
		
		
		
	}
}

void Game::Enemy::addSprites()
{
}

void Game::Enemy::DisplayInfo()
{
	
	std::cout << "position: " << this->position << std::endl;

}
