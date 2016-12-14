#pragma once
#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "AnimatedObject.hpp"
#include "Character.hpp"
namespace Game {
	class Character;
	enum class EnemyType
	{
		TY1,//change later
		TY2,
	};
	class Enemy : public AnimatedObject
	{
	private:
		EnemyType type;
		const static sf::Vector2f startSpeed;
		
		void move(float delta, Character& ch);
		bool colFlag;
		
	public:
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
		void update(Character& ch);
		void addSprites();
		void DisplayInfo();
		bool collisionCheck(Level& l);
		Enemy(const sf::Vector2f& startPos, const sf::Vector2f& startSize,int NoOfSprites,EnemyType t);
		~Enemy();
	};
}
#endif



