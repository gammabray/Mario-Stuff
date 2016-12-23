#pragma once
#ifndef PLAYER_TRACKER_HPP
#define PLAYER_TRACKER_HPP
#include "GameInterface.hpp"
#include "PowerUp.hpp"


///<summary>
///Class: PlayerTracker
///Tracks information about the player in the game.
///</summary>
namespace Game {
	
	class PlayerTracker {
	 private:
		int currScore;
		int currLives;
		
		PowerUpType currPowerUp;
		sf::Clock clock;
		
		friend class GameInterface;//to allow the GameInterface class to get all information
								   // about the player without public methods
		
		sf::Time timeSpent;
		
	 public:
		 bool isDead;
		 PlayerTracker();
		 void trackTime();
		 void setScore(int score);
		 void addScore(int score);
		 void addLife();
		 void removeLife();
		 //void updatePowerUp(PowerUpType type);	//not implemented power-ups yet.


	};

}

#endif