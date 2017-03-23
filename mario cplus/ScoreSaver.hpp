#pragma once
#ifndef SCORESAVER_HPP
#define SCORESAVER_HPP
#include "PlayerTracker.hpp"
namespace Game {
	class ScoreSaver
	{
	private:
		sf::Time time;
		int score;

	public:
		bool SaveScore(int currLevel);
		ScoreSaver(PlayerTracker & tracker);
		~ScoreSaver();
	};
}

#endif 



