#pragma once

#ifndef FIREBALL_H
#define FIREBALL_H

#include "Projectile.hpp"

namespace Game {
	class Fireball :
		public Projectile
	{
	public:
		Fireball(const sf::Vector2f& startPos, direction d );
	
		void addSprites();//add co-ordinate information for sprite areas
		void DisplayInfo();// show where sprite is
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const;
		void changeSprite(int changeTo);
		void update();
		
	private:
		const static sf::Vector2f s_size;
		const static sf::Vector2f s_speed;
	};
}
#endif 



