#include "Projectile.hpp"
#include <iostream>

Game::Projectile::Projectile(const sf::Vector2f & startPos,const sf::Vector2f & startSize, const sf::Vector2f & startSpeed, direction d,int NoOfSprites)
	: AnimatedObject(startPos,startSize,NoOfSprites,sf::Vector2f(0.f,0.f),startSpeed)
{
		travelling = d;
}
