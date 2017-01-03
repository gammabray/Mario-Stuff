#pragma once
#ifndef POWERUP_HPP
#define POWERUP_HPP
#include "DisplayObject.hpp"
#include "Character.hpp"
namespace Game {
	class Character;
	
	class PowerUp : public DisplayObject {
	public:	 
		enum PowerUpType : char {
			BETTERJUMP = 'J',
			FIREBALL = 'F'
		};
		PowerUpType effect;
		PowerUp(const sf::Vector2f& startPos);

		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
	};
}
#endif