#pragma once
#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AnimatedObject.hpp"
#include <SFML\Graphics.hpp>
#include <queue>
#include "Projectile.hpp"
#include "Level.hpp"
#include "Enemy.hpp"
#include "PlayerTracker.hpp"




namespace Game {
	class Enemy; class PlayerTracker; class Level; class Projectile;
	class Character : public AnimatedObject
	{
		///<summary>
		///Class: Character
		///
		///The class that represents the player in the game.
		///
		///</summary>
	private:
		sf::Vector2f currentFallSpeed;
		const sf::Vector2f fallAcceleration;
		sf::Vector2f VelocityBeforeJumping;//what the players velocity was before the jump function was executed
		direction directionBeforeJumping;
		const sf::Vector2f StartSpeed;//original speed when starting to move
		sf::Vector2f respawnPoint;
		void jump();//Initiate jumping
		sf::Clock powerUpClock;
		int projectilesToCreate;
		std::queue<ProjectileType> projectileQueue;//a queue of projectiles the engine needs to create
													//Stored as vector of enum representing type
													//instead of actual type to reduce memory usage
		
	public:
		PlayerTracker* tracker;
		bool IsWalking;
		bool IsJumping;
		bool respawnPointSet;
		bool CanFall;
		bool IsDead;	

		Character(const sf::Vector2f& startPos);
		~Character();

		void addSprites();
		void Move(float delta, Level& l);//move character and view according to speed, whether player is jumping
		void Update(Level& l);//Update position of character on screen
		
		void StopJump();
	
		void DisplayInfo();
		void Draw(sf::RenderTarget& target, const sf::RenderStates& states = sf::RenderStates::Default) const;
		void changeSprite(int changeTo = 0);//change what sprite is displayed
		void Destroy();
		void fall(float delta);
		void setRespawnPoint(const sf::Vector2f& value) { respawnPoint = value; }

		size_t getProjectileCount() { return projectileQueue.size();}
		ProjectileType dequeue_projectile(); //Removes a projectileType from the queue and returns its value
		void restartPowerClock() { powerUpClock.restart(); } // restart the clock for power-ups
	
		sf::Vector2f& getRespawnPoint() { return respawnPoint; }


	};
}

#endif