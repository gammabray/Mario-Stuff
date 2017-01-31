#include "PlayerTracker.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>




Game::PlayerTracker::PlayerTracker() :  AllLivesLost(false)
{
	currScore = 0;
	clock.restart();
	currLives = 999;
}
 
void Game::PlayerTracker::trackTime()
{
	timeSpent = this->clock.getElapsedTime();
}

void Game::PlayerTracker::setScore(int score)
{
	currScore = score;
}
void Game::PlayerTracker::addScore(int score)
{
	currScore += score;
}

void Game::PlayerTracker::addLife()
{
	currLives++;
}

void Game::PlayerTracker::removeLife()
{
	currLives--;
	if (currLives < 0) {
		AllLivesLost = true;
	}
}


