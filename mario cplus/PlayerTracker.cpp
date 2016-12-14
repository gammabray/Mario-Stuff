#include "PlayerTracker.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <string>




Game::PlayerTracker::PlayerTracker() : currScore(0), currLives(3), timeSpent("0"), clock(), isDead(false)
{

}
std::string Game::PlayerTracker::convertToStandardTime(sf::Time & t) //e.g in the form minutes:seconds (12:03)
{
	std::stringstream ss;
	ss << std::fixed << std::setprecision(3) << t.asSeconds();
	return ss.str();
	

}	 
void Game::PlayerTracker::trackTime()
{
	timeSpent = convertToStandardTime(clock.getElapsedTime());
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


