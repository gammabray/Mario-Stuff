#pragma once
#ifndef COIN_HPP
#define COIN_HPP
#include "DisplayObject.hpp"
#include <iostream>
namespace Game {
	
	class Coin : public DisplayObject {
	public:
		const static int s_ID = 16;
		const static int s_scoreGiven = 25;
		const static sf::Vector2f s_size;
		Coin(const sf::Vector2f& startPos);
		void Draw(sf::RenderTarget & target, const sf::RenderStates & states) const;
		
	
	
	
	};

}

#endif
