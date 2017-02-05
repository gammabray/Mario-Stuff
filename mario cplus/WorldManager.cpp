#include "WorldManager.hpp"

namespace Game {
	WorldManager::WorldManager() : frameTime(static_cast<double>(1000.l / 60.l))	//game runs at 60FPS
											,HasCollided(false)
	{
	}
	//For each of the collision checking functions,
	//objects are passed as references to the types they are
	//For example Characters are normal fields of engine so
	//they are passed by value
	//Enemies are passed as const references to shared pointers
	void WorldManager::CheckCollision(Character & ch,Level & l, sf::RenderWindow& rw, sf::View& v)
	{

		for (unsigned int i = 0; i < l.coins.size(); ++i) {
			if(ch.boundingBox.intersects(l.coins[i].boundingBox)) {
				ch.tracker->addScore(Coin::s_scoreGiven);
				l.eraseCoin(i);
			}
	    }
		for (Tile& t : l.tiles) {
		
		
			checkCollision(ch, t);
			
			rw.setView(v);
			if (HasCollided) {
				HasCollided = false;			
				return;
			}			 
		}	
	}

	void WorldManager::CheckCollision(const std::shared_ptr<Enemy> & e, Level & l)
	{
		for (Tile& t : l.tiles) {
			checkCollision(e, t);
		}
	}
	
	void WorldManager::checkCollision(Character & ch, Tile & t)
	{
		
		sf::FloatRect checkArea(ch.getPosition().x - ch.getSize().x, ch.getPosition().y - ch.getSize().y,200,200);
		if (!checkArea.contains(t.getPosition())) return;
		if (ch.boundingBox.intersects(t.boundingBox)) //already colliding  
		{
			if (t.ID == tileID::CHECKFLAG || t.ID == tileID::CHECKPOLE) {//no movement needed
				ch.SetRespawnPoint(t.getPosition());
				ch.respawnPointSet = true;
				return;
			} 
			sf::Vector2f lengthBetweenCentres(ch.getPosition().x - t.getPosition().x, ch.getPosition().y - t.getPosition().y);		
			
			if (lengthBetweenCentres.y < 0)// colliding from top
			{
				minVector = sf::Vector2f(0, -lengthBetweenCentres.y - (ch.getSize().y / 2) - (t.getSize().y / 2));
				ch.CanFall = false;
			}
			else if (lengthBetweenCentres.y > 0) //colliding from below
			{
				ch.CanFall = true;
				minVector = sf::Vector2f(0, -lengthBetweenCentres.y + (ch.getSize().y / 2) + (t.getSize().y / 2));
			}				
			if (lengthBetweenCentres.x > 0 && ch.IsWalking) { //colliding from right
			
				minVector.x = -lengthBetweenCentres.x + (ch.getSize().x / 2) + (t.getSize().x / 2);
				minVector.y = 0;
			}
			else if (lengthBetweenCentres.x < 0 && ch.IsWalking) { //colliding from left
				minVector.x = -lengthBetweenCentres.x - (ch.getSize().x / 2) - (t.getSize().x / 2);
				minVector.y = 0;
			}
				

			
			
			ch.setVelocity(sf::Vector2f(0, 0));
			ch.IsWalking = false;
			ch.IsAccelerating = false;
			ch.IsJumping = false;
			ch.IsJumping = false; 			
			HasCollided = true;				  
		}
		else {
			ch.CanFall = true;
		}
	
	}
	void WorldManager::checkCollision(const std::shared_ptr<Enemy> & e, Tile & t)
	{
		sf::FloatRect checkArea(e->getPosition().x - 50, e->getPosition().y - 50, 200, 200);
		if (!checkArea.contains(t.getPosition())) return;
		if (t.ID == tileID::CHECKFLAG || t.ID == tileID::CHECKPOLE) {//no movement needed
			return;
		}
		
		if (e->boundingBox.intersects(t.boundingBox)) {
			sf::Vector2f lengthBetweenCentres(e->getPosition().x - t.getPosition().x, e->getPosition().y - t.getPosition().y);
			if (lengthBetweenCentres.y < 0)// colliding from top
			{
				minVector = sf::Vector2f(0, -lengthBetweenCentres.y - (e->getSize().y / 2) - (t.getSize().y / 2));
				e->CanFall = false;

			}
			else if (lengthBetweenCentres.y > 0) //colliding from below
			{

				minVector = sf::Vector2f(0, -lengthBetweenCentres.y + (e->getSize().y / 2) + (t.getSize().y / 2));
			}

			if (lengthBetweenCentres.x > 0 && e->IsWalking) { //colliding from right

				minVector.x = -lengthBetweenCentres.x + (e->getSize().x / 2) + (t.getSize().x / 2);
				minVector.y = 0;
			}
			else if (lengthBetweenCentres.x < 0 && e->IsWalking) { //colliding from left
				minVector.x = -lengthBetweenCentres.x - (e->getSize().x / 2) - (t.getSize().x / 2);
				minVector.y = 0;
			}
		}
			else {
				e->CanFall = true;

			}

	}

	
}