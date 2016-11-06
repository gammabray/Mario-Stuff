#pragma once

#ifndef ANIMATEDOBJECT_HPP
#define ANIMATEDOBJECT_HPP
#include "DisplayObject.hpp"
#include "SFML\Graphics.hpp"
#include <vector>

using sf::Vector2f;
//base class for all animated ojects in game.
namespace Game {
	class AnimatedObject : public Game::DisplayObject {
	protected:
		std::vector<sf::IntRect> SpriteStates;
		enum class direction {
			LEFT,
			RIGHT,									   
			UP,
			DOWN
		};
		direction travelling;
		int       currSprite;
		sf::Clock animationClock;
		sf::Clock speedClock;		  
		Vector2f* acceleration;
		Vector2f* deceleration;
		Vector2f* velocity;
	public:
		virtual void addSprites() = 0;
		virtual void move(float delta, sf::View& v) = 0;
		virtual void update(sf::View& v, sf::Keyboard::Key k = sf::Keyboard::Key::Unknown) = 0;
		virtual void DisplayInfo() = 0;


		AnimatedObject(const Vector2f& startPos, const Vector2f& startSize, int noOfSprites);
		virtual ~AnimatedObject();
	};
}
#endif