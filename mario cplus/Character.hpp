#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AnimatedObject.hpp"
#include <SFML\Graphics.hpp>

#include "Level.hpp"
#include "Enemy.hpp"
#include "PlayerTracker.hpp"




namespace Game {
	class Enemy; class PlayerTracker;
	class Character : public AnimatedObject
	{
		///<summary>
		///Class: Character
		///
		///The class that represents the player in the game.
		///
		///</summary>
	protected:
		sf::Vector2f currentFallSpeed;
		const sf::Vector2f fallAcceleration;
		sf::Vector2f VelocityBeforeJumping;//what the players velocity was before the jump function was executed
		direction directionBeforeJumping;
		const sf::Vector2f StartSpeed;//original speed when starting to move
		sf::Vector2f respawnPoint;

	public:
		PlayerTracker* tracker;
		bool IsWalking;
		bool IsJumping;

		Character(const sf::Vector2f& startPos);
		~Character();

		void addSprites();
		void move(float delta, Level& l);//move character and view according to speed, whether player is jumping
		void update(Level& l);//Update position of character on screen
		void jump();//Initiate jumping
		void DisplayInfo();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default);
		bool collisionCheck(Enemy& e);
		bool collisionCheck(Level& l); 	
		void changeSprite(int changeTo = 0);//change what sprite is displayed
		void hit(sf::RenderWindow& rw);//when hit by enemy
		
		void setRespawnPoint(const sf::Vector2f& value) { respawnPoint = value; }
		sf::Vector2f& getRespawnPoint() { return respawnPoint; }


	};
}

#endif