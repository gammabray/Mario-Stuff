#include "Projectile.hpp"
#include <iostream>

Game::Projectile::Projectile(const sf::Vector2f & startPos, ProjectileType type, direction d)
	:size(8.f,8.f),startSpeed(0.2f,0.f),
	AnimatedObject(startPos,size,1,sf::Vector2f(0.f,0.f),startSpeed)
{
	std::string filepath;
	switch (type)
	{
	case ProjectileType::p_fireball:
		filepath = "Images\\fireball.png";
		HurtsEnemies = true;
		HurtsPlayers = false;
		break;
	case ProjectileType::e_bullet:
		filepath = "Images\\bullet.png";
		HurtsEnemies = false;
		HurtsPlayers = true;
		break;
	default:
		break;

	}
	if (!texture->loadFromFile(filepath)) {
		std::cout << "Failed to load texture for projectile" << std::endl;
	}
	
}
