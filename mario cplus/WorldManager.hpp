#ifndef COLLISIONMANAGER_HPP
#define COLLISIONMANAGER_HPP
#include "Character.hpp"
#include "Tile.hpp"
#include <SFML\Graphics.hpp>

namespace Game {
	class WorldManager {//manages the world the player is in
						//this includes collision with other objects
						//(formerly known as CollisionManager)
	public:
		WorldManager();
		void AddGravity(Character & ch, float delta);
		const sf::Vector2f& GetMinVector() { return minVector; }
		void ResetMinimumVector(){ minVector.x = 0; minVector.y = 0; }
		
		void CheckCollision(Character& ch, Level& l
			 //);
			, sf::RenderWindow& rw, sf::View& v);
	

		
		bool MoveAfterCollision;
	private:
		sf::Vector2f minVector;
		double frameTime;
		bool HasCollided;
		void CheckCollision(Character& ch, Tile& t);
		
		
	};
}

#endif