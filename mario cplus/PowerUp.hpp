#pragma once
#ifndef POWERUP_HPP
#define POWERUP_HPP

#include "DisplayObject.hpp"
namespace Game {
	
	enum PowerUpType{
		FIREBALL = 18,
		BETTERJUMP = 19,
		
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