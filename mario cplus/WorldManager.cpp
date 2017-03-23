#include "WorldManager.hpp"


namespace Game {
	WorldManager::WorldManager() : frameTime(static_cast<double>(1000.l / 60.l))	//game runs at 60FPS
											,HasCollided(false), NoTouches(true)
	{
	}
	//For each of the collision checking functions,
	//objects are passed as references to the types they are
	//For example Characters are normal fields of engine so
	//they are passed by value
	//Enemies are passed as const references to shared pointers
	void WorldManager::CheckCollision(Character & ch,Level & l, sf::RenderWindow& rw, sf::View& v)
	{
		NoTouches = true;
		for (unsigned int i = 0; i < l.coins.size(); ++i) {
			if(ch.boundingBox.intersects(l.coins[i].boundingBox)) {
				ch.tracker->addScore(Coin::s_scoreGiven);
				l.eraseCoin(i);
			}
	    }
		for (unsigned int i = 0; i < l.powerUps.size(); ++i) {
			if (ch.boundingBox.intersects(l.powerUps[i].boundingBox)) {
				
				if (ch.tracker->HasPowerUp) {
					ch.tracker->addScore(200);
				}
				else {
					ch.tracker->addScore(80);
					ch.restartPowerClock();
				}
				ch.tracker->setPowerUp(l.powerUps[i].type);
				l.erasePowerUp(i);
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
		if (NoTouches) {
			ch.CanFall = true;
		}
	
		
		
		
	
	}

	void WorldManager::CheckCollision(const std::unique_ptr<Enemy> & e, Level & l)
	{
		for (Tile& t : l.tiles) {
			checkCollision(e, t);
			if (HasCollided) {
				HasCollided = false;			
				return;
			}
		}
		e->CanFall = true;
		
		
		
		
		
	}
	void WorldManager::CheckCollision(ProjectileList pList, Character& c)
	{
		for (auto& projectile : pList) {
			if (projectile->HurtsPlayers && !projectile->Destroyed) {
				checkCollision(projectile, c);
			}				

		}
	}
	
	void WorldManager::checkCollision(Character & ch, Tile & t)
	{
		
		sf::FloatRect checkArea(ch.getPosition().x - 100, ch.getPosition().y - 100, 200, 200);
		if (!checkArea.contains(t.getPosition())) { return; }
		sf::Vector2f lengthBetweenCentres(ch.getPosition().x - t.getPosition().x, ch.getPosition().y - t.getPosition().y);
		if (ch.boundingBox.intersects(t.boundingBox)) //already colliding  
		{
			if (t.ID == tileID::CHECKFLAG) {//no movement needed
				ch.setRespawnPoint(t.getPosition());
				ch.respawnPointSet = true;
				return;
			}
			if (t.ID == tileID::FINISHFLAG)
			{
				ch.tracker->GameCompleted = true;
				return;
			}
					
			
			if (lengthBetweenCentres.y < 0 )// colliding from top
			{
				minVector = sf::Vector2f(0, -lengthBetweenCentres.y - (ch.getSize().y / 2) - (t.getSize().y / 2));
				ch.CanFall = false;
				ch.IsWalking = false;
				
			}
			else if (lengthBetweenCentres.y > 0) //colliding from below
			{	
			
				minVector = sf::Vector2f(0, -lengthBetweenCentres.y + (ch.getSize().y / 2) + (t.getSize().y / 2));
				ch.CanFall = true;
				ch.IsWalking = false;
			}				
			if (lengthBetweenCentres.x > 0) { //colliding from right
			
				minVector.x = -lengthBetweenCentres.x + (ch.getSize().x / 2) + (t.getSize().x / 2);
				
				
				
			}
			else if (lengthBetweenCentres.x < 0) { //colliding from left
				
				minVector.x = -lengthBetweenCentres.x - (ch.getSize().x / 2) - (t.getSize().x / 2);
				
				
			}
			if (minVector.x < minVector.y && !ch.IsJumping) {
				minVector.y = 0;
				ch.CanFall = false;
			}
			else {
				minVector.x = 0;

			}
		


			
			
				
			ch.IsAccelerating = false;
			ch.IsJumping = false;		
			ch.setVelocity(sf::Vector2f(ch.getVelocity().x, 0));
			HasCollided = true;
			NoTouches = false;
			
		}
		else if ((-lengthBetweenCentres.y - (ch.getSize().y / 2) - (t.getSize().y / 2) == 0) && abs(lengthBetweenCentres.x) <= 24) {
			NoTouches = false;
			HasCollided = true;
		}
		
		
		
		
		
		
	
	}
	void WorldManager::checkCollision(const std::unique_ptr<Projectile>& p, Character & c)
	{
		if (p->boundingBox.intersects(c.boundingBox)) {
			p->OnPlayerHit();
			c.Destroy();
		}
	}
	
	void WorldManager::checkCollision(const std::unique_ptr<Enemy> & e, Tile & t)
	{
		sf::FloatRect checkArea(e->getPosition().x - 50, e->getPosition().y - 50, 200, 200);
		if (!checkArea.contains(t.getPosition())) return;
		if (t.ID == tileID::CHECKFLAG || t.ID == tileID::CHECKPOLE || t.ID == tileID::FINISHFLAG) {//no movement needed
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
				e->CanFall = true;
			}

			if (lengthBetweenCentres.x > 0 && e->IsWalking) { //colliding from right

				minVector.x = -lengthBetweenCentres.x + (e->getSize().x / 2) + (t.getSize().x / 2);
				minVector.y = 0;
			}
			else if (lengthBetweenCentres.x < 0 && e->IsWalking) { //colliding from left
				minVector.x = -lengthBetweenCentres.x - (e->getSize().x / 2) - (t.getSize().x / 2);
				minVector.y = 0;
			}
			
			HasCollided = true;
			e->setVelocity(sf::Vector2f(e->getVelocity().x, 0));
		}
		
		
			
		
	}
	

	
}