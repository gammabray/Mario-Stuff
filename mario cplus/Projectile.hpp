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
		
		Projectile(const sf::Vector2f& startPos,const sf::Vector2f& startSize,const sf::Vector2f& startSpeed,direction d, int NoOfSprites);
		ProjectileType type;		
		bool Destroyed,
			HurtsPlayers,
			HurtsEnemies;
		virtual void update() = 0;
		virtual void OnPlayerHit() {}   //Optional action to be called when the projectile hits player
		virtual void OnTerrainHit() {}; //Optional action to be called when the projectile hits the terrain
		virtual void OnEnemyHit() {};   //Optional action to be called when the projectile hits enemies
		const sf::Time& getTimeRemaining() { return deathClock.getElapsedTime(); } //The time remaining until the projectile despawns
	protected:
		sf::Clock deathClock;	

	};
	typedef std::vector<std::unique_ptr<Projectile>> ProjectileList;


}
#endif
