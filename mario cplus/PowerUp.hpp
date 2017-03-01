#pragma once
#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "DisplayObject.hpp"
namespace Game {
	
	enum PowerUpType : char {
		BETTERJUMP = 'J',
		FIREBALL = 'B',
		NONE = 'N'
	};
	class PowerUp : public DisplayObject {// The collectible that creates the powerup
	private:
		
	public:	 
		
		
		PowerUpType type;
		PowerUp(const sf::Vector2f& startPos,PowerUpType effect);

		void Draw(sf::RenderTarget & target, const sf::RenderStates & states) const;

		
	};
}
#endif