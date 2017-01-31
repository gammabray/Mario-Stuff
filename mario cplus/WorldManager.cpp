#include "WorldManager.hpp"

namespace Game {
	WorldManager::WorldManager() : frameTime(static_cast<double>(1000.l / 60.l))	//game runs at 60FPS
											,HasCollided(false)
	{
	}
	void WorldManager::AddGravity(Character & ch, float delta)
	{
		if (ch.CanFall) {
		
		}
	}
	void WorldManager::CheckCollision(Character & ch, Level & l, sf::RenderWindow& rw, sf::View& v)
	{

		for (unsigned int i = 0; i < l.getCoins().size(); i++) {
			if(ch.boundingBox.intersects(l.getCoins()[i].boundingBox)) {
				ch.tracker->addScore(Coin::s_scoreGiven);
				l.eraseCoin(i);
			}
	    }
		for (Tile& t : l.getTiles()) {
		
		
			CheckCollision(ch, t);
			
			rw.setView(v);
			if (HasCollided) {
				HasCollided = false;			
				return;
			}			 
		}	
	}
	
	void WorldManager::CheckCollision(Character & ch, Tile & t)
	{
		
		sf::FloatRect checkArea(ch.getPosition().x - ch.getSize().x, ch.getPosition().y - ch.getSize().y,1000,1000);
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
	
	}
	
}