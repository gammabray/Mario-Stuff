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
		const sf::Vector2f& GetMinVector() { return minVector; }
		void ResetMinimumVector(){ minVector.x = 0; minVector.y = 0; }
		//NOTE: PascalCase collision functions are public methods
		//      camelCase  collision functions are private methods used by
		//		the public ones.
		void CheckCollision(Character& ch, Level& l, sf::RenderWindow& rw, sf::View& v);
		void CheckCollision(const std::shared_ptr<Enemy>& e, Level & l);

		bool MoveAfterCollision;
	private:
		sf::Vector2f minVector;
		double frameTime;
		bool HasCollided;
		void checkCollision(Character& ch, Tile& t);

		void checkCollision(const std::shared_ptr<Enemy>& e, Tile & t);

		;

		
		
		
	};
}

#endif