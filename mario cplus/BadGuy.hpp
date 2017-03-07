#pragma once
#ifndef BADGUY_HPP
#define BADGUY_HPP
#include "Enemy.hpp"
namespace Game {
	class BadGuy :
		public Enemy
		//Simple enemy that moves towards the player
	{
	private:
		void fall();
		bool colFlag;
	public:
		BadGuy(const sf::Vector2f& startPos);
		
		void update(Character & ch);
		void move(float delta, Character & ch);
		void addSprites();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const;
		void changeSprite(int changeTo) {}
	};
}
#endif


