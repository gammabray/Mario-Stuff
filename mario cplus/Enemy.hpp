#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedObject.hpp"
#include "Character.hpp"
namespace Game {
	
	class Character;
	enum class EnemyType
	{
		BADGUY,
		SHOOTINGENEMY,
		FIREBALLENEMY
	};
	class Enemy : public AnimatedObject
		//Base class for all enemies in the game
		//It contains common code for all enemies: update and drawing methods (for enemy container implementation),
		//
		//and a enumerated type for what type of enemy it is
		//
		//Abstract class since all enemies have specialised implementations
		//
	{
	protected:
		EnemyType type;
		const sf::Vector2f startSpeed;	
		
		
		
	public:
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
		virtual void update(Character& ch) = 0;
		void DisplayInfo();
		bool CanFall;
		bool IsWalking;
		Enemy(const sf::Vector2f& startPos,const sf::Vector2f& startSize,const sf::Vector2f& startSpeed,EnemyType t);
	
	};
	typedef std::vector<std::unique_ptr<Enemy>> EnemyList;
}
#endif



