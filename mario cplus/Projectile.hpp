#ifndef PROJECTILE_HPP
#define PROJECTILE_HPP
#include "AnimatedObject.hpp"
namespace Game {
	class Projectile : public AnimatedObject
		//Represents projectiles fired by objects in the game.
		//This version represents the generic implementation
		//with more complicated version being derived from this class.
	{
	public:
		enum class ProjectileType
			//p_ for player projectiles
			//e_ for enemy projectiles
		{
			p_fireball,
			p_lightning
		};
		Projectile();
		~Projectile();

	private:

	};


}
#endif
