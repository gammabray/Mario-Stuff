#include "PlayerTracker.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>




Game::PlayerTracker::PlayerTracker() :  isDead(false)
{
	currScore = 0;
	clock.restart();
}
 
void Game::PlayerTracker::trackTime()
{
	timeSpent = this->clock.getElapsedTime();
}

void Game::PlayerTracker::setScore(int score)
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
		isDead = true;
	}
}


