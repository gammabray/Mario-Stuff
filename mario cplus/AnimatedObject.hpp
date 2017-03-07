#pragma once

#ifndef ANIMATEDOBJECT_HPP
#define ANIMATEDOBJECT_HPP
#include "DisplayObject.hpp"
#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>




namespace Game {
	class AnimatedObject : public Game::DisplayObject {
		///<summary>
		/// Class: AnimatedObject (Abstract)
		///
		///</summary>
	protected:
		friend std::ostream& operator<<(std::ostream& o, sf::Vector2f v);//for displaying position of object
		std::vector<sf::IntRect> SpriteStates;//container of different sprites for animation
		enum class direction {
			LEFT,
			RIGHT,
			UP,
			DOWN,
			STATIONARY
		};
		enum class collisionType {
			TOP,
			LEFT,
			RIGHT,
			BOTTOM,
			NOCOL,
			GENERIC,
		};
		direction     travelling; //where the object is moving
		direction	  facing;     //what direction the object is facing
		int           currSprite; //current sprite the object is using
		sf::Clock     animationClock; //clock to time walkign animation
		sf::Clock     speedClock; // clock to measure time since last frame to smoothly move the same amount every frame		  
		sf::Vector2f  acceleration;
		sf::Vector2f  deceleration;
		sf::Vector2f  velocity;
		const sf::Vector2f maxVelocity;
		
		
	public:
		virtual void addSprites() = 0;//add co-ordinate information for sprite areas
		virtual void DisplayInfo() = 0;// show where sprite is
		virtual void changeSprite(int changeTo) = 0;
		const sf::Vector2f& getVelocity() { return velocity; }
		void  setVelocity(const sf::Vector2f& velocity) { this->velocity = velocity; }
		const sf::Vector2f& getAcceleration() { return acceleration; };
		bool  IsAccelerating;
		const direction getDirection() { return travelling; }
		const direction getFacing() { return facing; }

		AnimatedObject(const sf::Vector2f& startPos, const sf::Vector2f& startSize, int noOfSprites, const sf::Vector2f& acceleration, const sf::Vector2f& maxSpeed);
		
	};
}
#endif