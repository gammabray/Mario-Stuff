#include "Enemy.hpp"
#include "Character.hpp"
#include <iostream>





Game::Enemy::Enemy(const sf::Vector2f& startPos,const sf::Vector2f& startSize,const sf::Vector2f& startSpeed, Game::EnemyType t)
	:  startSpeed(startSpeed),
	AnimatedObject(startPos, startSize, 1 ,sf::Vector2f(0,0.08f),sf::Vector2f(0.15f,0.f)),
	type(t)
{
	collisionBox.setPosition(this->position);
	switch (t) {
	case EnemyType::BADGUY:
		if (!texture->loadFromFile("Images\\enemy.png")) {
			std::cout << "Failed to load enemy texture..." << std::endl;
		}
		break;
	case EnemyType::SHOOTINGENEMY:
		if (!texture->loadFromFile("Images\\shootingenemy.png")) {
			std::cout << "Failed to load enemy texture..." << std::endl;
		}
		break;

	}
	
	
	sprite->setTexture(*texture);
	sprite->setOrigin(size.x / 2, size.y / 2 );

}



void Game::Enemy::Draw(sf::RenderTarget & target, const sf::RenderStates & states)
{	
	target.draw(*sprite, states);
}




void Game::Enemy::DisplayInfo()
{

	std::cout << "position: " << this->position << std::endl;

}
