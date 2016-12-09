#pragma once
#ifndef COIN_HPP
#define COIN_HPP
#include "AnimatedObject.hpp"
namespace Game {
	class Coin : public AnimatedObject {
	public:
		const static int ID = 3;
		const static int scoreGiven = 100;
		Coin();
		~Coin();
	
	protected:

	};

}

#endif
