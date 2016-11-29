#pragma once

#ifndef ANIMATEDOBJECT_HPP
#define ANIMATEDOBJECT_HPP
#include "DisplayObject.hpp"
#include "SFML\Graphics.hpp"
#include <vector>
#include <memory>

using sf::Vector2f;


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
		direction travelling; //where the object is facing
		int       currSprite; //current sprite the object is using
		sf::Clock animationClock; //clock to time walkign animation
		sf::Clock speedClock; // clock to measure time since last frame to smoothly move the same amount every frame		  
		Vector2f  acceleration;
		Vector2f  deceleration;
		Vector2f  velocity;
		
	public:
		virtual void addSprites() = 0;//add co-ordinate information for sprite areas
		virtual void DisplayInfo() = 0;// show where sprite is


		AnimatedObject(const Vector2f& startPos, const Vector2f& startSize, int noOfSprites);
		virtual ~AnimatedObject();
	};
}
#endif