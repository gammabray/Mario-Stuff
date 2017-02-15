#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "AnimatedObject.hpp"
namespace Game {
	enum class ProjectileType
		//p_ for player projectiles
		//e_ for enemy projectiles
	{
		p_fireball,
		e_bullet
	};
	class Projectile : public AnimatedObject
		//Represents projectiles fired by objects in the game.
		//This version represents the generic implementation
		//with more complicated version being derived from this class.
	{
	public:
		
		Projectile(const sf::Vector2f& startPos, ProjectileType type,direction d);
		~Projectile();
		bool HurtsPlayers;
		bool HurtsEnemies;
		bool Destroyed;

	private:
		const sf::Vector2f startSpeed;
		const sf::Vector2f size;
		



	};


}
#endif
