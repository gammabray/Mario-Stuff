#pragma once
#ifndef PLAYER_TRACKER_HPP
#define PLAYER_TRACKER_HPP

#include "PowerUp.hpp"


///<summary>
///Class: PlayerTracker
///Tracks information about the player in the game.
///</summary>
namespace Game {
	class PowerUp;
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
		 bool AllLivesLost;
		 bool GameCompleted;
		 bool HasPowerUp; // Only one power-up at a time
		 PlayerTracker();
		 void trackTime();
		 void setScore(int score);
		 void addScore(int score);
		 int  getScore() { return currScore; }
		 const sf::Time& getTime() { return timeSpent; }
		 void setPowerUp(PowerUpType newPowerUp);
		 const PowerUpType& getPowerUp();
		 
		 void addLife();
		 void removeLife();
		


	};

}

#endif